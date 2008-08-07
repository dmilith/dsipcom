/*
 * author: Daniel (dmilith) Dettlaff
 * email: dmilith at drakor.eu
 * released under GPL2 & LGPL license
 * (c) 2oo8
 *
 */

#include <qt4/QtCore/qtimer.h>

// TODO: make header check for dsipcom.dcnf
// TODO: make use of MSList * linphone_core_get_call_logs(LinphoneCore *lc), while generation of daily call logs
#include "dsipcom_ui.h"
#include "version.h"
//#include "main.h"

using namespace Log;
using namespace Ui;
using namespace std;
using namespace boost::filesystem;

// Linphone variables & consts
//
//Linphone Core
LinphoneCore linphonec;
LinphoneCallLog linphone_call_log;
// today_log will contain current session call log
static string today_log = "";
// List of sound devices
const char **sound_dev_names;
// List of sound codecs
const MSList *audio_codec_list, *video_codec_list;
FILE* linphone_logger_file;
LPC_AUTH_STACK auth_stack; // stack of auth requests (?) 
char prompt[PROMPT_MAX_LEN];
static bool_t auto_answer = FALSE;
static bool_t vcap_enabled = FALSE;
static bool_t display_enabled = FALSE;
// pending_call_sip contains sip address of caller
static string pending_call_sip;


	/* Linphone structs
	    These are callback for linphone core */
		static void linphonec_call_received( LinphoneCore *lc, const char *from );
		static void linphonec_prompt_for_auth( LinphoneCore *lc, const char *realm, const char *username );
		static void linphonec_display_something ( LinphoneCore * lc, const char *something );
		static void linphonec_display_url ( LinphoneCore * lc, const char *something, const char *url );
		static void linphonec_display_warning ( LinphoneCore * lc, const char *something );
		static void stub () {}
		static void linphonec_notify_received( LinphoneCore *lc, LinphoneFriend *fid, 
																				const char *from, const char *status, const char *img );
		static void linphonec_new_unknown_subscriber( LinphoneCore *lc,
																				LinphoneFriend *lf, const char *url );
		static void linphonec_bye_received( LinphoneCore *lc, const char *from );
/*		static void linphonec_text_received( LinphoneCore *lc, LinphoneChatRoom *cr,
																			 const char *from, const char *msg ); */
		static void linphonec_display_status ( LinphoneCore * lc, const char *something );
    static void linphonec_call_log_updated( LinphoneCore *lc, LinphoneCallLog *call_log );
		
		// main Linphone table.
		LinphoneCoreVTable linphonec_vtable = {
			show:(ShowInterfaceCb) stub,
			inv_recv: linphonec_call_received,
			bye_recv: linphonec_bye_received, 
			notify_recv: linphonec_notify_received,
			new_unknown_subscriber: linphonec_new_unknown_subscriber,
			auth_info_requested: linphonec_prompt_for_auth,
			display_status: linphonec_display_status,
			display_message: linphonec_display_something,
			display_warning: linphonec_display_warning,
			display_url: linphonec_display_url,
			display_question: (DisplayQuestionCb)stub,
     	call_log_updated: linphonec_call_log_updated,

		  //text_received:linphonec_text_received,
		};

      void
      display_qt4_error_message( const char* message ) {
        QMessageBox::critical( 0, MAIN_WINDOW_TITLE.c_str(), message );
      }
      
      void
      display_qt4_warning_message( const char* message ) {
        QMessageBox::warning( 0, MAIN_WINDOW_TITLE.c_str(), message );
      }
      
      void
      display_qt4_message( const char* message ) {
        QMessageBox::information( 0, MAIN_WINDOW_TITLE.c_str(), message );
      }

		/* Linphone callbacks definitions */
      static void
      linphonec_call_log_updated( LinphoneCore *lc, LinphoneCallLog *call_log ) {
        lc = &linphonec;
        call_log = &linphone_call_log;
        MSList *elem = linphone_core_get_call_logs( lc );
        for ( ; elem != NULL; elem = ms_list_next( elem ) ) {
                LinphoneCallLog *cl = (LinphoneCallLog*)elem->data;
                char *str = linphone_call_log_to_str( cl );
             #ifdef DEBUG
                cout << endl << "CallLog:" << str << endl << endl;
             #endif   
                today_log += (string)str + "\n"; // adding call logs to common log
                ms_free( str );
        }
      }
      
			static void
			linphonec_display_something ( LinphoneCore * lc, const char *something ) {
        lc = &linphonec;
        #ifdef DEBUG
          cout << "\ndebug_linphonec_display_something_: " << something << endl;
        #endif
        display_qt4_message( something );  
			}

			static void
			linphonec_display_status ( LinphoneCore * lc, const char *something ) {
        lc = &linphonec;
        #ifdef DEBUG
          cout << "\ndebug_linphonec_display_status_: " << something << endl;
        #endif
        // inform about everything but Ready
        if ( (string)"Ready" == (string)something ) {
          //display_qt4_message( something );  
        } else if ( (string)something == (string)"Could not reach destination." ) {
          display_qt4_error_message( something );  
          linphone_core_terminate_call( &linphonec, pending_call_sip.c_str() );
        }
			}

			static void
			linphonec_display_warning ( LinphoneCore * lc, const char *something ) {
        lc = &linphonec;
        #ifdef DEBUG
          cout << "\ndebug_linphonec_display_warning_: " << something << endl;
        #endif
        display_qt4_warning_message( something );    
			}

			static void
			linphonec_display_url ( LinphoneCore * lc, const char *something, const char *url ) {
			  lc = &linphonec;
        #ifdef DEBUG
          cout << "\ndebug_linphonec_display_url_: " << something << ", url: " << url << endl;
        #endif
        display_qt4_message( something );  
      }

			static void
			linphonec_call_received( LinphoneCore *lc, const char *from ) {
        lc = &linphonec;
				#ifdef DEBUG
          cout << "\ndebug_linphonec_call_received_: from: " << from << endl;
        #endif
        if ( auto_answer )  {
          #ifdef DEBUG
            cout << "\ndebug_linphonec_call_received_: Auto answered call" << endl;
          #endif
				}
        //display_qt4_message( from );
        /*LinphoneAuthInfo *info;
            info = linphone_auth_info_new( "ktokolwiek_bo_kazdemu_ufamy", NULL, NULL, NULL, from );
            linphone_core_add_auth_info( lc, info );
            */
			}

			static void
			linphonec_prompt_for_auth( LinphoneCore *lc, const char *realm, const char *username ) {
        lc = &linphonec;
        LinphoneAuthInfo *pending_auth;
        #ifdef DEBUG
          cout << "\ndebug_linphonec_prompt_for_auth_: realm:" << realm << ", username: " << username << endl;
        #endif
				if ( auth_stack.nitems + 1 > MAX_PENDING_AUTH ) {
					cout << "\n\nCan't accept another authentication request.\n" << 
                  "Consider incrementing MAX_PENDING_AUTH macro." << endl;
					return;
				} 
				pending_auth = linphone_auth_info_new( username, NULL, NULL, NULL, realm );
				auth_stack.elem[ auth_stack.nitems++ ] = pending_auth;
        string concated = "Odebrano żądanie autoryzacji od " + (string)username + " (" + (string)realm + ") ";
        display_qt4_message( concated.c_str() );  
			}

			static void
			linphonec_notify_received( LinphoneCore *lc, LinphoneFriend *fid,
						    								 const char *from, const char *status, const char *img ) {
        lc = &linphonec;
				// TODO: update Friend list state (unimplemented in linphonec)
        // TODO: do something with LinphoneFriend struct
        #ifdef DEBUG
         cout << "\ndebug_linphonec_notify_received_: From: " << from << " Status: " << status << " img: " << img << endl;
        #endif
        string concated = "Odebrano zdarzenie od " + (string)from + " ( status:" + (string)status + ") ";
        display_qt4_message( concated.c_str() );
			}

			static void
			linphonec_new_unknown_subscriber( LinphoneCore *lc, LinphoneFriend *lf, const char *url ) {
        lc = &linphonec;
        #ifdef DEBUG
          cout << "\ndebug_linphonec_new_unknown_subscriber_: friend: " << url << 
                  " requested subscription (accept/deny is not implemented yet)" << endl; 
        // This means that this person wishes to be notified 
				// of your presence information (online, busy, away...).
        #endif
			}

			static void
			linphonec_bye_received( LinphoneCore *lc, const char *from ) {
				// printing this is unneeded as we'd get a "Communication ended"
				// message trough display_status callback anyway
        lc = &linphonec;
				#ifdef DEBUG
          cout << "\ndebug_linphonec_bye_received_: from: " << from << endl;
        #endif
			}

 // TODO: text chats should be implemented soon     
 /*
			static void
			linphonec_text_received( LinphoneCore *lc, LinphoneChatRoom *cr, const char *from, const char *msg) {
				// TODO: provide mechanism for answering.. ('say' command?)
				printf("\n\nFrom: %s: Msg: %s\n", from, msg);
				fflush( stdout );
			}
 */
			void
      DSipCom::linphonec_main_loop() {
        linphone_core_iterate( &linphonec );
        if ( linphonec.call != NULL ) {
          #ifdef DEBUG
            cout << ".";
            fflush( stdout );
          #endif
        }
			}

      void
      DSipCom::reset_status_bar() {
         this->status_bar->setText( "Program nie wykonuje żadnej akcji" );
      }
      
      
//DSipCom objects
#ifdef DEBUG
  Logger
  logger( LOGGER_DSIPCOM_UI.c_str(), "debug" );
#endif

  void DSipCom::read_logs() {
    // this->calendar->selectedDate().day();
    // TODO: make proper structure for log data
    // log_data
    //
    
  }
 
//DSipCom methods
DSipCom::DSipCom( const QString& title ) {
  #ifdef DEBUG
    logger.log( "Checking HOME and DIRS" );
  #endif
    setupDIRs();
  #ifdef DEBUG
    logger.log( "Initializing UI" );
  #endif
  setupUi( this );
   // global ui encoding => utf8
   QTextCodec::setCodecForCStrings( QTextCodec::codecForName( "UTF-8" ) );
   // setting window flags
   Qt::WindowFlags flags;
   flags = Qt::Window | Qt::WindowMinimizeButtonHint | Qt::WindowStaysOnTopHint;
   setWindowFlags( flags );
   // ui settings
   setWindowTitle( title );
   // contacts list in front by default
   toolBox->setCurrentIndex( 0 );
   show();
   #ifdef DEBUG
    logger.log( "Initializing QT4 actions" );
   #endif
    init_actions();
   #ifdef DEBUG
    logger.log( "DSipCom initialized" );
    logger.log( "Loading User List" );
   #endif
   //save_user_list();
   user_list.reserve( 100 ); // reserve place for 100 elements 
   load_user_list();
   
   #ifdef DEBUG
    logger.log( "Loading User Config" );
   #endif
  user_config = new USER_CONFIG;
  create_linphone_core();
  load_user_config();
  //reading logs for calendar
  read_logs();
   #ifdef DEBUG
    logger.log( "Loading Linphone, version: " + (QString)linphone_core_get_version() );
   #endif
}

DSipCom::~DSipCom() {
  // destroing main linphone core structure
  linphone_core_uninit( &linphonec );
 #ifdef DEBUG
  cout << "\nDsipCom destructor." << endl;
  cout << today_log;
 #endif 
}

void
DSipCom::setupDIRs() {
  // this method will check existance of main program directories and it will try to create them if they doesn't exist
  if ( !exists( DSIP_MAIN_DIR ) ) create_directory( DSIP_MAIN_DIR );
  if ( !exists( LOGS_DIR ) ) create_directory( LOGS_DIR );
  if ( !exists( CONF_DIR ) ) create_directory( CONF_DIR );
  if ( !exists( ULIST_DIR ) ) create_directory( ULIST_DIR );
}

void
DSipCom::create_linphone_core() {
    #ifdef DEBUG
       logger.log( "Linphone config: " + (QString)( LINPHONE_CONFIG.c_str() ) );
       logger.log( "Initializing Linphone core logger" );
       linphone_core_enable_logs( stdout );
       TRACE_INITIALIZE( (trace_level_t)0, stdout );
    #endif
    #ifndef DEBUG   
       linphone_core_disable_logs();
    #endif
    #ifdef DEBUG
      logger.log( "Linphone logger initialized" );
      logger.log( "Initializing LinPhone" );
    #endif
    // TODO: make configurable choosing ipv4/v6  
    // disable ipv6 by default.
    linphone_core_enable_ipv6( &linphonec, FALSE );
    auth_stack.nitems = 0;
    linphone_core_init ( &linphonec, &linphonec_vtable, LINPHONE_CONFIG.c_str(), NULL );
    linphone_core_enable_video( &linphonec, vcap_enabled, display_enabled );
    // CRITICAL SECTION OF DSIPCOM:
    // Creating timer with 60ms trigger, and launch it in the background thread
    // Here we going to iterate main Linphone engine.
    QTimer *timer = new QTimer( this );
    connect( timer, SIGNAL( timeout() ) , this, SLOT( linphonec_main_loop() ) );
    timer->start( 60 ); // 60ms is enough
    // char** with list of sound devices
    sound_dev_names = linphone_core_get_sound_devices( &linphonec );
    // MSlist with audio codecs list
    audio_codec_list = linphone_core_get_audio_codecs( &linphonec );
    video_codec_list = linphone_core_get_video_codecs( &linphonec );
   // linphone_core_set_audio_codecs( &linphonec, (MSList*)audio_codec_list->next );
   // linphone_core_set_video_codecs( &linphonec, (MSList*)video_codec_list );
    #ifdef DEBUG
      logger.log( "Linphone core Ready!" );
    #endif
}

void
DSipCom::save_user_list() {
// TODO: implement User Authorisation for linphone core
//  LinphoneAuthInfo *linphone_auth_info_new(const char *username, const char *userid,
//		const char *passwd, const char *ha1,const char *realm);
//void linphone_auth_info_set_passwd(LinphoneAuthInfo *info, const char *passwd);
//  LinphoneAuthInfo * linphone_auth_info_new_from_config_file(struct _LpConfig *config, int pos);
  LinphoneAuthInfo* temp;
  FILE* userlist_file;
  userlist_file = fopen( USER_LIST_FILE.c_str(), "wb+" );
  if ( userlist_file == 0 ) {
    cout << "Error writing userlist file!\nCannot continue. Check Your user access and try again." << endl;
    exit( 1 );
  }
  // writing header
  char user_list_header[] = "dulf2";
  fwrite( user_list_header, sizeof( user_list_header ), 1, userlist_file );
  // writing amount of users
  uint32_t user_list_size = user_list.size();
  fwrite( &user_list_size, sizeof( uint32_t ), 1, userlist_file );
  cout << "\nuser_list_size_:" << user_list_size << endl;
  // writing data
  if ( user_list_size > 0 ) {
    for (int i = 0; i < user_list.size(); i++ ) {
      char realm[255] = "";
      char username[255] = "";
      temp = linphone_auth_info_new( user_list.at( i ).username, NULL, NULL, NULL, user_list.at( i ).realm );
      strcpy( username, user_list.at( i ).username );
      strcpy( realm, user_list.at( i ).realm );
      cout << username << " " << realm << endl;
      fflush( stdout );
      #ifdef DEBUG
        cout << "\nsave_user_list_: " << username << "@" << realm << " vs " << 
                user_list.at( i ).username << "@" << user_list.at( i ).realm << endl;
      #endif
      fwrite( username, sizeof( username ), 1, userlist_file );
      fwrite( realm, sizeof( realm ), 1, userlist_file );
    }
  }
  #ifdef DEBUG
    cout << "\nsave_user_list_: amount of records written to file: " << (uint32_t)user_list_size << endl;
  #endif  
  fclose( userlist_file );
}

void
DSipCom::load_user_list() {
  // TODO: each contact on DSipCom's user list should get linphone presence info
  //void linphone_core_set_presence_info(LinphoneCore *lc,int minutes_away,const char *contact,LinphoneOnlineStatus os);
  //linphone_core_set_presence_info( &linphonec, 0, )
  // clear user_list QVector
  this->user_list.clear(); // == .resize(0)
  // clear items on contacts list
  this->contacts_list->clear();
  // reading user_list from file
  uint32_t size_of_list;
  FILE* userlist_file;
  userlist_file = fopen( USER_LIST_FILE.c_str(), "rb+" );
  // checking existance of list file
  if ( userlist_file == 0 ) {  
    cout << "Error reading userlist file!\nNew user_list file will be created." << endl;
    save_user_list();
    userlist_file = fopen( USER_LIST_FILE.c_str(), "rb+" );
  }
  // checking userlist file header
  char user_list_header_correct[] = "dulf2";
  char* user_list_header = new char[ sizeof( user_list_header_correct ) + 1 ];
  fread( user_list_header, sizeof( user_list_header_correct ), 1, userlist_file );
  #ifdef DEBUG
    logger.log( "Userlist file header check: " + (QString)user_list_header + " vs " + (QString)user_list_header_correct );
  #endif
  if ( strcmp( user_list_header, user_list_header_correct ) != 0 ) {
    cout << "Error in user_list file header. (" << user_list_header << " instead of " << 
            user_list_header_correct << ") Probably I tried to read bad format user_list" <<
            " file! Delete this file, maybe it's broken or smth" << endl;
    exit( 1 );
  }
  delete[] user_list_header;
  // reading number of elements
  fread( &size_of_list, sizeof( uint32_t ), 1, userlist_file );
  // reading elements
  if ( size_of_list > 0 ) {
    char realm[255];
    char username[255]; //temp ones
    for ( uint32_t i = 0; i < size_of_list; i++ ) {
      fread( username, sizeof( username ), 1, userlist_file );
      fread( realm, sizeof( realm ), 1, userlist_file );
      LinphoneAuthInfo* temp = linphone_auth_info_new( username, "", "", "", realm );
      user_list.append( *temp );
    }
    // putting elements to user_list plus icons
    if (! user_list.empty() ) {
      for ( uint32_t i = 0; i< size_of_list; i++ ) {
        // C-c C-v from Qt4 example. It will set specified icon to current list element, then will set caption, and add object to user_list
        QIcon icon1;
        icon1.addPixmap( QPixmap( QString::fromUtf8( ":/images/images/user_green.png" ) ), QIcon::Active, QIcon::On );
        QListWidgetItem *__listItem = new QListWidgetItem( this->contacts_list );
        __listItem->setIcon( icon1 );
        __listItem->setText( QString( user_list.at( i ).username ) + QString( " : " ) + QString( user_list.at( i ).realm ) );  
      }
    }
  }
  fclose( userlist_file );
  // matter of security - always, one element on user list need to be choosen: ( SEGV when accessing unchoosen element )
  this->contacts_list->setCurrentRow( 0 );
}

void
DSipCom::apply_settings_to_linphone() {
  // applying settings to linphone core:
  uint64_t port = strtol( user_config->default_port, NULL, 10 ); //conversion from char[5] to uint64_t, 10 => decimal number sys.
  if ( ( port > 65535 ) || ( port < 1024 ) ) { // 65535 is max port, greater than 1024 cause 0...1024 are root ports
    linphone_core_set_sip_port( &linphonec, 5060 );
    strcpy( user_config->default_port, "5060" );
  } else { 
    linphone_core_set_sip_port( &linphonec, port );
  }
  #ifdef DEBUG
    cout << "\nConfig port value/ after conversion: " << user_config->default_port << "/ " << port << endl;
    cout << "\nSetting default port to: " << (uint64_t)linphone_core_get_sip_port( &linphonec ) << endl;
  #endif
  linphone_core_set_inc_timeout( &linphonec, 60 ); // 60 to timeout
  linphone_core_set_firewall_policy( &linphonec, LINPHONE_POLICY_NO_FIREWALL );
  if ( user_config->use_stun_server ) {
    linphone_core_set_stun_server( &linphonec, user_config->stun_address );
    linphone_core_set_firewall_policy( &linphonec, LINPHONE_POLICY_USE_STUN );
  }
  if ( user_config->manual_firewall_address ) {
    linphone_core_set_nat_address( &linphonec, user_config->firewall_address );
    linphone_core_set_firewall_policy( &linphonec, LINPHONE_POLICY_USE_NAT_ADDRESS );
  }
  #ifdef DEBUG
    PayloadType *pt = NULL;
    for( MSList* elem = (MSList*)audio_codec_list; elem != NULL; elem = elem->next ) {
      cout << elem << endl;
      
    }
  #endif
  // TODO: add ring volume level setting
  // void linphone_core_set_ring_level(LinphoneCore *lc, int level);
  linphone_core_set_ring_level( &linphonec, 5 );
  // void linphone_core_set_play_level(LinphoneCore *lc, int level);
  linphone_core_set_play_level( &linphonec, 5 );
  // void linphone_core_set_rec_level(LinphoneCore *lc, int level);
  linphone_core_set_rec_level( &linphonec, 6 );
  // TODO: add option to manually choose ring sound
  strcpy( user_config->ring_sound, "sounds/toyphone.wav" ); 
  linphone_core_set_ring( &linphonec, user_config->ring_sound );
  // TODO: add support for echo cancelation:
  // void linphone_core_enable_echo_cancelation(LinphoneCore *lc, bool_t val);
  linphone_core_set_ringer_device( &linphonec, user_config->out_soundcard  );
  #ifdef DEBUG
    cout << "\nSound RING OUT device: " << linphone_core_get_ringer_device( &linphonec ) << endl;
  #endif
  linphone_core_set_playback_device( &linphonec, user_config->out_soundcard );
  #ifdef DEBUG
    cout << "\nSound PLAYBACK OUT device: " << linphone_core_get_playback_device( &linphonec ) << endl;
  #endif
  linphone_core_set_capture_device( &linphonec, user_config->in_soundcard );
  #ifdef DEBUG
    cout << "\nSound CAPTURE IN device: " << linphone_core_get_capture_device( &linphonec ) << endl;
  #endif
  linphone_core_set_guess_hostname( &linphonec, TRUE );
  // TODO: make possible to set bandwith capacity
  linphone_core_set_download_bandwidth( &linphonec, 0 ); // bandwidth unlimited
  linphone_core_set_upload_bandwidth( &linphonec, 0 ); // same as above.
  // TODO: make able to preview selected ring 
 /* #ifdef DEBUG
    cout << sound_dev_names[0] << endl; // alsa
    cout << sound_dev_names[1] << endl; // oss
    void* userdata;
    LinphoneCoreCbFunc func;
    int result = linphone_core_preview_ring( &linphonec, user_config->ring_sound, func, userdata );
    if ( result != 0 ) {
      cout << "\nError in preview!";
      exit( 1 );
    }
    cout << "\n\n\nRing preview: " << user_config->ring_sound << " - " << endl;
    fflush(stdout);
  #endif */
}

// load_user_config() it's method which load application settings and apply them in linphone core right after init
void
DSipCom::load_user_config() {
  FILE* config_file;
  config_file = fopen( CONFIG_FILE.c_str(), "rb+" );
  if ( config_file == 0 ) {  
    cout << "Error reading user config file!\nNew user config will be created." << endl;
    save_user_config();
    config_file = fopen( CONFIG_FILE.c_str(), "rb+" );
  }
  // reading user config structure at once
  fread( user_config, sizeof( USER_CONFIG ), 1, config_file );
  fclose( config_file );
  // putting values from file to edit objects
  this->user_name->setText( user_config->user_name );
  this->user_password->setText( user_config->user_password );
  this->user_sip->setText( user_config->user_sip );
  this->user_sip_server->setText( user_config->user_sip_server );
// TODO: it should set properly those, now we'll set OSS as CONST!: 
  this->out_soundcard->setCurrentIndex( 0 ); //user_config->out_soundcard );
  this->in_soundcard->setCurrentIndex( 0 ); //user_config->in_soundcard );
  this->recording_source->setCurrentIndex( 0 ); //user_config->recording_source );
  strcpy( user_config->out_soundcard, sound_dev_names[ 1 ] );
  strcpy( user_config->in_soundcard, sound_dev_names[ 1 ] );
  strcpy( user_config->recording_source, sound_dev_names[ 1 ] );
  this->ring_sound->setItemText( this->ring_sound->currentIndex(), user_config->ring_sound );
  this->ring_sound->setEditable( true );
  this->default_port->setText( user_config->default_port );
  this->no_firewall->setChecked( user_config->no_firewall );
  this->use_stun_server->setChecked( user_config->use_stun_server );
  this->stun_address->setText( user_config->stun_address );
  this->manual_firewall_address->setChecked( user_config->manual_firewall_address );
  this->firewall_address->setText( user_config->firewall_address );
  this->gsm_8_codec->setChecked( user_config->gsm_8_codec );
  this->speex_8_codec->setChecked( user_config->speex_8_codec );
  this->speex_16_codec->setChecked( user_config->speex_16_codec );
  this->pcmu_8_codec->setChecked( user_config->pcmu_8_codec );
  this->pcma_8_codec->setChecked( user_config->pcma_8_codec );
  apply_settings_to_linphone();
}

void
DSipCom::save_user_config() {
  // getting values from main window objects
  strcpy( user_config->user_name, this->user_name->text().toUtf8() );
  strcpy( user_config->user_password, this->user_password->text().toUtf8() );
  strcpy( user_config->user_sip, this->user_sip->text().toUtf8() );
  strcpy( user_config->user_sip_server, this->user_sip_server->text().toUtf8() );
  if ( this->out_soundcard->currentIndex() == 0 ) { // index 0 means OSS on dSipCom device list, but it's 1 on sound_dev_names list
    strcpy( user_config->out_soundcard, sound_dev_names[ 1 ] );
  } else {
    strcpy( user_config->out_soundcard, sound_dev_names[ 0 ] );
  }
  if ( this->in_soundcard->currentIndex() == 0 ) {
    strcpy( user_config->in_soundcard, sound_dev_names[ 1 ] );
  } else {
    strcpy( user_config->in_soundcard, sound_dev_names[ 0 ] );
  }  
  if ( this->recording_source->currentIndex() == 0 ) {
    strcpy( user_config->recording_source, sound_dev_names[ 1 ] );  
  } else {
    strcpy( user_config->recording_source, sound_dev_names[ 0 ] );  
  }
  strcpy( user_config->ring_sound, this->ring_sound->currentText().toUtf8() );
  strcpy( user_config->default_port, this->default_port->text().toUtf8() );
  user_config->no_firewall = this->no_firewall->isChecked();
  user_config->use_stun_server = this->use_stun_server->isChecked();
  strcpy( user_config->stun_address, this->stun_address->text().toUtf8() );
  user_config->manual_firewall_address = this->manual_firewall_address->isChecked();
  strcpy( user_config->firewall_address, this->firewall_address->text().toUtf8() );
  user_config->gsm_8_codec = this->gsm_8_codec->isChecked();
  user_config->speex_8_codec = this->speex_8_codec->isChecked();
  user_config->speex_16_codec = this->speex_16_codec->isChecked();
  user_config->pcmu_8_codec = this->pcmu_8_codec->isChecked();
  user_config->pcma_8_codec = this->pcma_8_codec->isChecked();
  FILE* config_file;
  config_file = fopen( CONFIG_FILE.c_str(), "wb+" );
  if ( config_file == 0 ) {
    cout << "Error writing user config file!\nCannot continue. Check Your user access and try again." << endl;
    exit( 1 );
  }
  // writing whole structure with data to file
  fwrite( user_config, sizeof( USER_CONFIG ), 1, config_file );
  fclose( config_file );
  apply_settings_to_linphone();
}

// init_actions will init all actions and binds in application
void
DSipCom::init_actions() {
  // buttons
  QObject::connect( call_button, SIGNAL( clicked() ), this, SLOT( action_make_a_call() ));
  QObject::connect( hang_button, SIGNAL( clicked() ), this, SLOT( action_end_call() ));
  QObject::connect( dial_0, SIGNAL( clicked() ), this, SLOT( action_enter_0() ));
  QObject::connect( dial_1, SIGNAL( clicked() ), this, SLOT( action_enter_1() ));
  QObject::connect( dial_2, SIGNAL( clicked() ), this, SLOT( action_enter_2() ));
  QObject::connect( dial_3, SIGNAL( clicked() ), this, SLOT( action_enter_3() ));
  QObject::connect( dial_4, SIGNAL( clicked() ), this, SLOT( action_enter_4() ));
  QObject::connect( dial_5, SIGNAL( clicked() ), this, SLOT( action_enter_5() ));
  QObject::connect( dial_6, SIGNAL( clicked() ), this, SLOT( action_enter_6() ));
  QObject::connect( dial_7, SIGNAL( clicked() ), this, SLOT( action_enter_7() ));
  QObject::connect( dial_8, SIGNAL( clicked() ), this, SLOT( action_enter_8() ));
  QObject::connect( dial_9, SIGNAL( clicked() ), this, SLOT( action_enter_9() ));
  QObject::connect( dial_star, SIGNAL( clicked() ), this, SLOT( action_enter_star() ));
  QObject::connect( dial_hash, SIGNAL( clicked() ), this, SLOT( action_enter_hash() ));
  QObject::connect( save_config_button, SIGNAL( clicked() ), this, SLOT( action_save_user_config() ));
  QObject::connect( load_config_button, SIGNAL( clicked() ), this, SLOT( action_load_user_config() ));
  QObject::connect( save_contact_list_button, SIGNAL( clicked() ), this, SLOT( action_save_user_list() ));
  QObject::connect( load_contact_list_button, SIGNAL( clicked() ), this, SLOT( action_load_user_list() ));
  // menu bar:
  QObject::connect( action_help, SIGNAL( activated() ), this, SLOT( action_help_func() ));
  QObject::connect( action_about, SIGNAL( activated() ), this, SLOT( action_about_func() ));
  QObject::connect( action_connect_to_sip_server, SIGNAL( activated() ), this, SLOT( action_connect_to_sip_server_func() ));
  QObject::connect( action_disconnect_from_sip_server, SIGNAL( activated() ), this, SLOT( action_disconnect_from_sip_server_func() ));
  QObject::connect( action_add_contact_to_list, SIGNAL( activated() ), this, SLOT( action_add_contact_func() ));
  QObject::connect( action_remove_contact_from_list, SIGNAL( activated() ), this, SLOT( action_remove_contact_func() ));
  // calendar
  QObject::connect( calendar, SIGNAL( selectionChanged() ), this, SLOT( action_get_log_func() ));
}

void
DSipCom::action_get_log_func() {
  QDate selected = this->calendar->selectedDate();
  #ifdef DEBUG
    cout << endl << "Current selected day: " << selected.day() << endl;
    fflush(stdout);
  #endif
  // TODO: it should be readed from special call log file
  raport_viewer->setPlainText( "\n" + (QString)today_log.c_str() );  
}
void
DSipCom::action_save_user_config() {
  save_user_config();
}
void
DSipCom::action_load_user_config() {
  load_user_config();
}
// TODO: add support for void linphone_core_add_friend(LinphoneCore *lc, LinphoneFriend *fr), and LinphoneFriend structure in place of actual two user info fields
void
DSipCom::action_load_user_list() {
  load_user_list();
}
void
DSipCom::action_save_user_list() {
  save_user_list();
}
/* numbers enterance: */
void
DSipCom::action_enter_0() {
  this->number_entry->setText( this->number_entry->text() + "0" );
}
void
DSipCom::action_enter_1() {
  this->number_entry->setText( this->number_entry->text() + "1" );
}
void
DSipCom::action_enter_2() {
  this->number_entry->setText( this->number_entry->text() + "2" );
}
void
DSipCom::action_enter_3() {
  this->number_entry->setText( this->number_entry->text() + "3" );
}
void
DSipCom::action_enter_4() {
  this->number_entry->setText( this->number_entry->text() + "4" );
}
void
DSipCom::action_enter_5() {
  this->number_entry->setText( this->number_entry->text() + "5" );
}
void
DSipCom::action_enter_6() {
  this->number_entry->setText( this->number_entry->text() + "6" );
}
void
DSipCom::action_enter_7() {
  this->number_entry->setText( this->number_entry->text() + "7" );
}
void
DSipCom::action_enter_8() {
  this->number_entry->setText( this->number_entry->text() + "8" );
}
void
DSipCom::action_enter_9() {
  this->number_entry->setText( this->number_entry->text() + "9" );
}
void
DSipCom::action_enter_star() {
  this->number_entry->setText( this->number_entry->text() + "*" );
}
void
DSipCom::action_enter_hash() {
  this->number_entry->setText( this->number_entry->text() + "#" );
}

void
DSipCom::action_end_call() {
  if ( linphonec.call != NULL ) {
    // section is equivalent of ruby split method
    this->status_bar->setText( "Rozłączam z " + ( (QString)pending_call_sip.c_str() ).section( ':', 1 ) );
    //this->call_button->setEnabled( true );
    //this->hang_button->setEnabled( false );
  #ifdef DEBUG
    cout << "Ending call with: " << pending_call_sip.c_str() << endl;
  #endif
    linphone_core_terminate_call( &linphonec, pending_call_sip.c_str() );
    QTimer *timer = new QTimer( this );
    connect( timer, SIGNAL( timeout() ) , this, SLOT( reset_status_bar() ) );
    timer->setSingleShot ( true ); //activate only once
    timer->start( 3000 ); // 3s
    // filling raport viewer log for current day:
    raport_viewer->setPlainText( "\n" + (QString)today_log.c_str() );  
  }
}

void
DSipCom::action_make_a_call() {
  // TODO: make DSipCom able to get a call from someone, not only call to someone
  // TODO: DSipCom should ask for video port. codecs should be choosen automaticly linphone_core_set_video_port
  // TODO: void linphone_core_enable_video_preview(LinphoneCore *lc, bool_t val) - it should be "enable video window" setting somewhere with default FALSE.
  // if we're on contacts list tab and this list isn't empty
  if ( ( ( this->contacts_list->count() != 0 ) && ( this->toolBox->currentIndex() == 0 ) ) || 
      // or number entry is at least one char long and we're on number entry page
       ( ( this->number_entry->text().length() > 0 ) && ( this->toolBox->currentIndex() == 1 ) ) ) {
          switch ( this->toolBox->currentIndex() ) {
            case 0:
              // 0 => contact list page
              this->status_bar->setText( "Dzwonię do: " + 
                this->contacts_list->item( this->contacts_list->currentRow() )->text().section( ':', 1 ) ); // str == "myapp" );
              
               pending_call_sip = (string)"sip:" + (string)( this->contacts_list->item( 
                                   this->contacts_list->currentRow() )->text().section( ':', 1 ) ).toUtf8() +
																	(string)":" + (string)user_config->default_port;
               pending_call_sip = strip( pending_call_sip, ' ' );
              //linphone_core_accept_call( &linphonec, NULL ); //to accept call
						#ifdef DEBUG
							cout << "\ndebug_action_make_a_call_:Making new call with: " << pending_call_sip.c_str() << endl;
						#endif
              break;
            case 1:
              // 1 => dialing page
              this->status_bar->setText( "Dzwonię do: " + this->number_entry->text() );
							// SIP address format is "sip:ADDR_OR_NUMBER_HERE:port"
              pending_call_sip = (string)"sip:" + (string)( this->number_entry->text() ).toUtf8() +
																 (string)":" + (string)user_config->default_port;
              pending_call_sip = strip( pending_call_sip, ' ' );
						#ifdef DEBUG
							cout << "Making new call with: " << pending_call_sip.c_str() << endl;
						#endif
              break;
          }
          
          if ( linphonec.call != NULL ) linphone_core_accept_call( &linphonec, pending_call_sip.c_str() );
          else linphone_core_invite( &linphonec, pending_call_sip.c_str() ); // to invite
//   this->call_button->setEnabled( false );
      this->hang_button->setEnabled( true );
  } else {
      this->toolBox->setCurrentIndex( 0 );
  }
}

void
DSipCom::action_help_func() {
  #ifdef DEBUG
    logger.log( "Visited -> Help" );
  #endif
  // TODO: add own help dialog instead of QMessageBox
  QMessageBox::information( this, MAIN_WINDOW_TITLE.c_str(), " Brak pliku pomocy [ niezainicjowano ] ");
}

void
DSipCom::action_about_func() {
  #ifdef DEBUG
    logger.log( "Visited -> about dialog!" );
  #endif
  new AboutBox();
}

void
DSipCom::action_connect_to_sip_server_func() {
  #ifdef DEBUG
    logger.log( "Trying to connect to server" );
  #endif
    if ( this->user_sip_server->text() == "" ) {
      QMessageBox::information( this, MAIN_WINDOW_TITLE.c_str(), " Proszę podać w preferencjach użytkownika nazwę serwera! " );
		} else if ( this->user_sip->text() == "" ) {
      QMessageBox::information( this, MAIN_WINDOW_TITLE.c_str(), " Proszę podać w preferencjach adres SIP użytkownika! " );
    } else if ( this->user_password->text() == "" ) {
      QMessageBox::information( this, MAIN_WINDOW_TITLE.c_str(), " Proszę podać w preferencjach hasło SIP użytkownika! " );
    } else if ( this->user_name->text() == "" ) {
      QMessageBox::information( this, MAIN_WINDOW_TITLE.c_str(), " Proszę podać w preferencjach nazwę użytkownika! " );
    } else {
      QMessageBox::information( this, MAIN_WINDOW_TITLE.c_str(), " Połączono z serwerem: " + (QString)this->user_config->user_sip_server );
      // all required settings are ok
      #ifdef DEBUG
        logger.log( "All required config data is OK!" );
      #endif  
    }
}

void
DSipCom::action_disconnect_from_sip_server_func() {
  QMessageBox::information( this, MAIN_WINDOW_TITLE.c_str(), " Rozłączono z serwerem: " + (QString)this->user_config->user_sip_server );
	#ifdef DEBUG  
		logger.log( "Trying to disconnect from server" ); 
	#endif
}

void
DSipCom::action_add_contact_func() {
  //creating new window with parent of current one
  dialog = new AddContactWindow( this );
  //switching to contacts list view
  toolBox->setCurrentIndex( 0 );
  //moving all main window content down
  dialog->setGeometry( toolBox->x(), toolBox->y() + 20, toolBox->width(), toolBox->height() + 20 );
  toolBox->setGeometry( toolBox->x(), toolBox->y() + 220, toolBox->width(), toolBox->height() + 220 );
  status_box->setGeometry( status_box->x(), status_box->y() + 220, status_box->width(), status_box->height() + 220 );
  dialog->show();
}

void
DSipCom::action_remove_contact_func() {
  if ( ( toolBox->currentIndex() == 0 ) && ( this->contacts_list->count() > 0 ) ) {
    // and from user_list QVector
	#ifdef DEBUG
		cout << "Removed contact with index: " << this->contacts_list->currentRow() << endl;
	#endif  
    this->user_list.remove( this->contacts_list->currentRow() );
    // delete item from list
    delete this->contacts_list->item( this->contacts_list->currentRow() );
	#ifdef DEBUG
		cout << "Remove contact func contacts list: " << this->contacts_list->count() << endl;
		cout << "Remove contact func list size: " << user_list.size() << endl;
	#endif  
  } else {
	#ifdef DEBUG
		cout << "\nNo elements on list." << endl;
	#endif  
  }
}

AddContactWindow::AddContactWindow( QWidget *parent ) {
  setupUi( this );
  init_actions();
  // we neet to tell child widget that it's parent is main window
  setParent( parent );
}

AddContactWindow::~AddContactWindow() {
}

void
AddContactWindow::init_actions() {
  // buttons
  QObject::connect( add_button, SIGNAL( clicked() ), this, SLOT( action_done() ));
  QObject::connect( cancel_button, SIGNAL( clicked() ), this, SLOT( action_cancel() ));
}

void
AddContactWindow::action_done() {
  // finding parent
  LinphoneAuthInfo* temp = new LinphoneAuthInfo;
  char username[255];
  char realm[255];
  DSipCom *object = ( (DSipCom*)this->parent() );
  // adding lineedit content from dialog on contact list
  if ( ( contact_name->text().length() > 0 ) && ( contact_sip_address->text().length() > 0 ) ) {
    QIcon icon1;
    icon1.addPixmap( QPixmap( QString::fromUtf8( ":/images/images/user_green.png" ) ), QIcon::Active, QIcon::On );
    // after setting icon, we'll bind it to an item, then update text elements
    QListWidgetItem *__listItem = new QListWidgetItem( object->contacts_list );
    __listItem->setIcon( icon1 );
    __listItem->setText( this->contact_name->text() + QString( " : " ) + this->contact_sip_address->text() );
    // marking last element ( just added one )
    // creating new user list element and appending it to user_list object 
    strcpy( username, this->contact_name->text().toUtf8() ); //.toUtf8();
    strcpy( realm, this->contact_sip_address->text().toUtf8() );
    #ifdef DEBUG
      cout << "\ndebug_action_done_: " << "UN: " << username << ", RL: " << realm << endl;
    #endif
    temp = linphone_auth_info_new( username, NULL, NULL, NULL, realm );
    #ifdef DEBUG
      cout << "\ndebug_action_done_: " << "TUN: " << temp->username << ", TRL: " << temp->realm << endl;
    #endif
    // TODO: only for dsipcom local user: strcpy( temp->passwd, "password" );
    object->user_list.append( *temp );
    #ifdef DEBUG
      cout << "\nZŁO: " << object->user_list.last().username << endl; 
    #endif
    //delete temp;
    object->toolBox->setGeometry( object->toolBox->x(), object->toolBox->y() - 220, object->toolBox->width(), object->toolBox->height() - 220 );
    object->status_box->setGeometry( object->status_box->x(), object->status_box->y() - 220, object->status_box->width(), object->status_box->height() - 220 );
    this->close();
  }
}

void
AddContactWindow::action_cancel() {
  //object will be object pointing to parent window
  DSipCom *object = ( (DSipCom*)this->parent() );
  // moving all parent elements back up
  object->toolBox->setGeometry( object->toolBox->x(), object->toolBox->y() - 220, object->toolBox->width(), object->toolBox->height() - 220 );
  object->status_box->setGeometry( object->status_box->x(), object->status_box->y() - 220, object->status_box->width(), object->status_box->height() - 220 );
  close();
}

AboutBox::AboutBox() {
  setupUi( this );
  version_label->setText( DSIPCOM_VERSION.c_str() );
  show();
}

AboutBox::~AboutBox() {
  #ifdef DEBUG
    cout << "AboutBox destructor." << endl;
  #endif
}
