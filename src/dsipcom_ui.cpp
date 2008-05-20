#include "dsipcom_ui.h"
#include "version.h"

using namespace Log;
using namespace Ui;

#ifdef	__cplusplus
extern "C" {
#endif
// C externs for linphone
  //static int handle_configfile_migration(void);
  //static int copy_file(const char *from, const char *to);
  //static int linphonec_parse_cmdline(int argc, char **argv);
  //static int linphonec_initialize_readline(void);
  //static int linphonec_finish_readline();  
  char *lpc_strip_blanks(char *input);
  static int linphonec_init( int argc, char **argv );
  static int linphonec_main_loop ( LinphoneCore * opm, char * sipAddr );
  static int linphonec_idle_call ( void );

  /* These are callback for linphone core */
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
  static void linphonec_text_received( LinphoneCore *lc, LinphoneChatRoom *cr,
                                     const char *from, const char *msg );
  static void linphonec_display_status ( LinphoneCore * lc, const char *something );

 // static bool_t vcap_enabled=FALSE;
 // static bool_t display_enabled=FALSE;
 // static int trace_level = 0;
 // static char *logfile_name = NULL;
 // static char configfile_name[PATH_MAX];
 // static char *sipAddr = NULL; /* for autocall */
 // static void linphonec_general_state ( LinphoneCore * lc, LinphoneGeneralState *gstate );
 // static void print_prompt( LinphoneCore *opm );
  //static char *histfile_name=NULL;
  //static char last_in_history[256];
  //auto answer (-a) option  
  
  static bool_t show_general_state = FALSE;
  LPC_AUTH_STACK auth_stack;
  static bool_t auto_answer = FALSE;
  static bool_t answer_call = FALSE;
  char prompt[PROMPT_MAX_LEN];
  
  // main Linphone table.
  LinphoneCoreVTable linphonec_vtable = {
    show:(ShowInterfaceCb) stub,
    inv_recv: linphonec_call_received,
    bye_recv: linphonec_bye_received, 
    notify_recv: linphonec_notify_received,
    new_unknown_subscriber: linphonec_new_unknown_subscriber,
    auth_info_requested: linphonec_prompt_for_auth,
    display_status:linphonec_display_status,
    display_message:linphonec_display_something,
    display_warning:linphonec_display_warning,
    display_url:linphonec_display_url,
    display_question:(DisplayQuestionCb)stub,
  //  text_received:linphonec_text_received
  //  general_state:linphonec_general_state
  };


  /* Linphone callbacks definitions */
  
    static void
    linphonec_display_something (LinphoneCore * lc, const char *something) {
      fprintf (stdout, "%s\n%s", something,prompt);
      fflush(stdout);
    }

    static void
    linphonec_display_status (LinphoneCore * lc, const char *something) {
      fprintf (stdout, "%s\n%s", something,prompt);
      fflush(stdout);
    }

    static void
    linphonec_display_warning (LinphoneCore * lc, const char *something) {
      fprintf (stdout, "Warning: %s\n%s", something,prompt);
      fflush(stdout);
    }

    static void
    linphonec_display_url (LinphoneCore * lc, const char *something, const char *url) {
      fprintf (stdout, "%s : %s\n", something, url);
    }

    static void
    linphonec_call_received(LinphoneCore *lc, const char *from) {
      if ( auto_answer)  {
        answer_call=TRUE;
      }
    }

    static void
    linphonec_prompt_for_auth(LinphoneCore *lc, const char *realm, const char *username) {
      LinphoneAuthInfo *pending_auth;
      if ( auth_stack.nitems+1 > MAX_PENDING_AUTH ) {
        fprintf(stderr,
          "Can't accept another authentication request.\n"
          "Consider incrementing MAX_PENDING_AUTH macro.\n");
        return;
      } 

      pending_auth=linphone_auth_info_new(username,NULL,NULL,NULL,realm);
      auth_stack.elem[auth_stack.nitems++] = pending_auth;
    }

    static void
    linphonec_notify_received( LinphoneCore *lc,LinphoneFriend *fid,
                            const char *from, const char *status, const char *img) {
      printf("Friend %s is %s\n", from, status);
      // todo: update Friend list state (unimplemented)
    }

    static void
    linphonec_new_unknown_subscriber(LinphoneCore *lc, LinphoneFriend *lf, const char *url) {
      printf("Friend %s requested subscription "
        "(accept/deny is not implemented yet)\n", url); 
      // This means that this person wishes to be notified 
      // of your presence information (online, busy, away...).
    }

    static void
    linphonec_bye_received(LinphoneCore *lc, const char *from) {
      // printing this is unneeded as we'd get a "Communication ended"
      // message trough display_status callback anyway
      printf("Bye received from %s\n", from);
    }

    static void
    linphonec_text_received( LinphoneCore *lc, LinphoneChatRoom *cr, const char *from, const char *msg) {
      printf("%s: %s\n", from, msg);
      // TODO: provide mechanism for answering.. ('say' command?)
    }

    static void 
    linphonec_general_state (LinphoneCore *lc, LinphoneGeneralState *gstate) {
            if (show_general_state) {
              switch(gstate->new_state) {
               case GSTATE_POWER_OFF:
                 printf("GSTATE_POWER_OFF");
                 break;
               case GSTATE_POWER_STARTUP:
                 printf("GSTATE_POWER_STARTUP");
                 break;
               case GSTATE_POWER_ON:
                 printf("GSTATE_POWER_ON");
                 break;
               case GSTATE_POWER_SHUTDOWN:
                 printf("GSTATE_POWER_SHUTDOWN");
                 break;
               case GSTATE_REG_NONE:
                 printf("GSTATE_REG_NONE");
                 break;
               case GSTATE_REG_OK:
                 printf("GSTATE_REG_OK");
                 break;
               case GSTATE_REG_FAILED:
                 printf("GSTATE_REG_FAILED");
                 break;
               case GSTATE_CALL_IDLE:
                 printf("GSTATE_CALL_IDLE");
                 break;
               case GSTATE_CALL_OUT_INVITE:
                 printf("GSTATE_CALL_OUT_INVITE");
                 break;
               case GSTATE_CALL_OUT_CONNECTED:
                 printf("GSTATE_CALL_OUT_CONNECTED");
                 break;
               case GSTATE_CALL_IN_INVITE:
                 printf("GSTATE_CALL_IN_INVITE");
                 break;
               case GSTATE_CALL_IN_CONNECTED:
                 printf("GSTATE_CALL_IN_CONNECTED");
                 break;
               case GSTATE_CALL_END:
                 printf("GSTATE_CALL_END");
                 break;
               case GSTATE_CALL_ERROR:
                 printf("GSTATE_CALL_ERROR");
                 break;
               default:
                  printf("GSTATE_UNKNOWN_%d",gstate->new_state);   
              }
              if (gstate->message) printf(" %s", gstate->message);
              printf("\n");
            }  
    }
    
#ifdef	__cplusplus
} // extern C
#endif


Logger logger( LOGGER_DSIPCOM_UI, "debug" );

DSipCom::DSipCom( const QString& title ) {
  logger.log( "Initializing UI" );
   setupUi( this );
   // global ui encoding => utf8
   QTextCodec::setCodecForCStrings( QTextCodec::codecForName( "UTF-8" ) );
   // setting window flags
   Qt::WindowFlags flags;
   flags = Qt::Window; //| Qt::WindowMinimizeButtonHint | Qt::WindowStaysOnTopHint;
   setWindowFlags( flags );
   // ui settings
   setWindowTitle( title );
   // contacts list in front by default
   toolBox->setCurrentIndex( 0 );
   show();
  logger.log( "Initializing QT4 actions" );
   init_actions();
  logger.log( "Initializing LinPhone" );
   create_linphone_core();
  logger.log( "DSipCom initialized" );
  logger.log( "Loading User List" );
   load_user_list();
   save_user_list();
  logger.log( "Loading User Config" );
   user_config = new USER_CONFIG;
   load_user_config();
}

void DSipCom::load_user_list() {
  // TODO: fix loading of user list from file
  USER_LIST *temp = new USER_LIST;
  strcpy( temp->contact_name, "dmilith" );
  strcpy( temp->contact_sip_address, "dmilith@drakor.eu" );
  user_list.append( *temp );
  delete temp;
  
  QIcon icon1;
  icon1.addPixmap( QPixmap( QString::fromUtf8( ":/images/images/user_green.png" ) ), QIcon::Active, QIcon::On);
  QListWidgetItem *__listItem = new QListWidgetItem(this->contacts_list);
  __listItem->setIcon(icon1);
  __listItem->setText((QString)(user_list[0].contact_name) + " => " + (QString)(user_list[0].contact_sip_address));
  
  // matter of security - always one of elements on user list should be choosed:
  this->contacts_list->setCurrentRow( 0 );
}

void DSipCom::save_user_list() {
  // TODO: fix saving of user list to file
  FILE* userlist_file;
  userlist_file = fopen( USER_LIST_FILE, "wb+" );
  fwrite( &user_list, sizeof( &user_list ), 1, userlist_file );
  fclose( userlist_file );
}

void DSipCom::load_user_config() {
  FILE* config_file;
  config_file = fopen( CONFIG_FILE, "rb+" );
  fread( user_config, sizeof( USER_CONFIG ), 1, config_file );
  fclose( config_file );
  // putting config data to lineedits in config tab
  this->user_name->setText( user_config->user_name );
  this->user_password->setText( user_config->user_password );
  this->user_sip->setText( user_config->user_sip );
  this->user_sip_server->setText( user_config->user_sip_server );
}

void DSipCom::save_user_config() {
  strcpy( user_config->user_name, this->user_name->text().toUtf8() );
  strcpy( user_config->user_password, this->user_password->text().toUtf8() );
  strcpy( user_config->user_sip, this->user_sip->text().toUtf8() );
  strcpy( user_config->user_sip_server, this->user_sip_server->text().toUtf8() );
  
  FILE* config_file;
  config_file = fopen( CONFIG_FILE, "wb+" );
  fwrite( user_config, sizeof( USER_CONFIG ), 1, config_file );
  fclose( config_file );
}

DSipCom::DSipCom() {
  setupUi( this );
}

DSipCom::~DSipCom() {
  linphone_core_destroy( _core );
  fclose( linphone_logger_file );
}

// init_actions will init all actions and binds in application
void DSipCom::init_actions() {
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
  QObject::connect( save_config_button, SIGNAL( clicked() ), this, SLOT( action_save_config_button() ));
  QObject::connect( load_config_button, SIGNAL( clicked() ), this, SLOT( action_load_config_button() ));
  
  // menu bar:
  QObject::connect( action_help, SIGNAL( activated() ), this, SLOT( action_help_func() ));
  QObject::connect( action_about, SIGNAL( activated() ), this, SLOT( action_about_func() ));
  QObject::connect( action_connect_to_sip_server, SIGNAL( activated() ), this, SLOT( action_connect_to_sip_server_func() ));
  QObject::connect( action_disconnect_from_sip_server, SIGNAL( activated() ), this, SLOT( action_disconnect_from_sip_server_func() ));
  QObject::connect( action_add_contact_to_list, SIGNAL( activated() ), this, SLOT( action_add_contact_func() ));
  QObject::connect( action_remove_contact_from_list, SIGNAL( activated() ), this, SLOT( action_remove_contact_func() ));
  
}

void DSipCom::action_save_config_button() {
  save_user_config();
}

void DSipCom::action_load_config_button() {
  load_user_config();
}

/* numbers enterance: */
void DSipCom::action_enter_0() {
  (this)->number_entry->setText( (this)->number_entry->text() + "0" );
}

void DSipCom::action_enter_1() {
  (this)->number_entry->setText( (this)->number_entry->text() + "1" );
}

void DSipCom::action_enter_2() {
  (this)->number_entry->setText( (this)->number_entry->text() + "2" );
}

void DSipCom::action_enter_3() {
  (this)->number_entry->setText( (this)->number_entry->text() + "3" );
}

void DSipCom::action_enter_4() {
  (this)->number_entry->setText( (this)->number_entry->text() + "4" );
}

void DSipCom::action_enter_5() {
  (this)->number_entry->setText( (this)->number_entry->text() + "5" );
}

void DSipCom::action_enter_6() {
  (this)->number_entry->setText( (this)->number_entry->text() + "6" );
}

void DSipCom::action_enter_7() {
  (this)->number_entry->setText( (this)->number_entry->text() + "7" );
}

void DSipCom::action_enter_8() {
  (this)->number_entry->setText( (this)->number_entry->text() + "8" );
}

void DSipCom::action_enter_9() {
  (this)->number_entry->setText( (this)->number_entry->text() + "9" );
}

void DSipCom::action_enter_star() {
  (this)->number_entry->setText( (this)->number_entry->text() + "*" );
}

void DSipCom::action_enter_hash() {
  (this)->number_entry->setText( (this)->number_entry->text() + "#" );
}

void DSipCom::action_end_call() {
  this->status_bar->setText( "Program nie wykonuje żadnej akcji" );
  this->call_button->setEnabled( true );
  this->hang_button->setEnabled( false );
}

void DSipCom::action_make_a_call() {
  if ( ( (this)->contacts_list->count() != 0 ) && (( this->toolBox->currentIndex() == 0 ) || ( this->toolBox->currentIndex() == 1 ) ) ) {
    switch ( this->toolBox->currentIndex() ) {
      case 0:
        // 0 => contact list page
        this->status_bar->setText( "Dzwonię do: " + this->contacts_list->item( this->contacts_list->currentRow() )->text().section(' ', -1) ); // str == "myapp" );
        break;
      case 1:
        // 1 => dialing page
        this->status_bar->setText( "Dzwonię do: " + this->number_entry->text() );
        break;
    }
    this->call_button->setEnabled( false );
    this->hang_button->setEnabled( true );
  } else {
  }
  //QListWidgetItem* current_item = (this)->contacts_list->item( (this)->contacts_list->currentRow() );
  //(this)->contacts_list->editItem( current_item );
}

void DSipCom::action_help_func() {
  logger.log( "Visited -> Help" );
  // TODO: add own help dialog instead of QMessageBox
  QMessageBox::information(this, MAIN_WINDOW_TITLE, " Brak pliku pomocy [ niezainicjowano ] ");
}


void DSipCom::action_about_func() {
  logger.log( "From about dialog!" );
  // TODO: add own about dialog instead of QMessageBox
  QMessageBox::information(this, MAIN_WINDOW_TITLE, " Program jest na licencji GPL.\nAutor: Daniel (dmilith) Dettlaff\n (c) 2oo8 ");
}

void DSipCom::action_connect_to_sip_server_func() {
  logger.log( "Trying to connect to server" );
    if ( (this)->user_sip_server->text() == "" ) {
      QMessageBox::information(this, MAIN_WINDOW_TITLE, " Proszę podać w preferencjach użytkownika nazwę serwera! " );
    } else if (( (this)->user_sip->text() == "") || ( (this)->user_sip->text() == "sip:" )) {
      QMessageBox::information(this, MAIN_WINDOW_TITLE, " Proszę podać w preferencjach adres SIP użytkownika! " );
    } else if ( (this)->user_password->text() == "" ) {
      QMessageBox::information(this, MAIN_WINDOW_TITLE, " Proszę podać w preferencjach hasło SIP użytkownika! " );
    } else if ( (this)->user_name->text() == "" ) {
      QMessageBox::information(this, MAIN_WINDOW_TITLE, " Proszę podać w preferencjach nazwę użytkownika! " );
    } else {
      // all required settings are ok
      logger.log( "All required data is OK!" );
    }
}

void DSipCom::action_disconnect_from_sip_server_func() {
  logger.log( "Trying to disconnect from server" ); 
}

void DSipCom::create_linphone_core(){
   char* config = getenv( "HOME" );
   char* conf_name = "/.dsipcom";
   strcat(config, conf_name);

  logger.log( "Linphone config: " + (QString)config );
  logger.log( "Initializing Linphone core logger" );
  
   /* tracing & logging for osip */
   linphone_logger_file = fopen( LOGGER_LINPHONE, "w");
   TRACE_INITIALIZE( (trace_level_t)5, linphone_logger_file );
   linphone_core_enable_logs( linphone_logger_file );

  logger.log( "Linphone logger initialized" );
   _core = linphone_core_new( &linphonec_vtable, config, NULL );
  logger.log( "Linphone core Ready!" );
}

void DSipCom::action_add_contact_func() {
  dialog = new AddContactWindow( this );
  //switching to contacts list view
  toolBox->setCurrentIndex( 0 );
  dialog->setGeometry( toolBox->x(), toolBox->y() + 20, toolBox->width(), toolBox->height() + 20 );
  toolBox->setGeometry( toolBox->x(), toolBox->y() + 220, toolBox->width(), toolBox->height() + 220 );
  status_box->setGeometry( status_box->x(), status_box->y() + 220, status_box->width(), status_box->height() + 220 );
  dialog->show();
}

void DSipCom::action_remove_contact_func() {
  //removing entry from list ( taking it without destination so it goes to NULL ) but only if current window is 0 - contacts list
  if ( toolBox->currentIndex() == 0 ) {
    (this)->contacts_list->takeItem( (this)->contacts_list->currentRow() ); 
  }
}

AddContactWindow::AddContactWindow( QWidget *parent ) {
  setupUi( this );
  init_actions();
  setParent( parent );
}

AddContactWindow::~AddContactWindow() {
}

void AddContactWindow::init_actions() {
  // buttons
  QObject::connect( add_button, SIGNAL( clicked() ), this, SLOT( action_done() ));
  QObject::connect( cancel_button, SIGNAL( clicked() ), this, SLOT( action_cancel() ));
}

void AddContactWindow::action_done() {
  // finding parent
  DSipCom *object = ( (DSipCom*)this->parent() );
  // adding lineedit content from dialog on contact list
  if ( ( this->contact_name->text().length() > 0 ) && ( this->contact_sip_address->text().length() > 4 ) ) {
    QIcon icon1;
    icon1.addPixmap( QPixmap( QString::fromUtf8( ":/images/images/user_green.png" ) ), QIcon::Active, QIcon::On );
    // after setting icon, we'll bind it to an item, then update text elements
    QListWidgetItem *__listItem = new QListWidgetItem( object->contacts_list );
    __listItem->setIcon(icon1);
    __listItem->setText( this->contact_name->text() + " => " + this->contact_sip_address->text() );
    // marking last element ( just added one )
    object->contacts_list->setCurrentRow( object->contacts_list->count() -1 );
    
    USER_LIST *temp = new USER_LIST;
    strcpy( temp->contact_name, this->contact_name->text().toUtf8() );
    strcpy( temp->contact_sip_address, this->contact_sip_address->text().toUtf8() );
    object->user_list.append( *temp );
    delete temp;
  }
  object->toolBox->setGeometry( object->toolBox->x(), object->toolBox->y() - 220, object->toolBox->width(), object->toolBox->height() - 220 );
  object->status_box->setGeometry( object->status_box->x(), object->status_box->y() - 220, object->status_box->width(), object->status_box->height() - 220 );
  close();
}

void AddContactWindow::action_cancel() {
  DSipCom *object = ( (DSipCom*)this->parent() );
  object->toolBox->setGeometry( object->toolBox->x(), object->toolBox->y() - 220, object->toolBox->width(), object->toolBox->height() - 220 );
  object->status_box->setGeometry( object->status_box->x(), object->status_box->y() - 220, object->status_box->width(), object->status_box->height() - 220 );
  close();
}

