#include "dsipcom_ui.h"
#include "version.h"

using namespace Log;
using namespace Ui;

// C externs for linphone
extern "C" {
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
} //extern C



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
}

DSipCom::~DSipCom() {
  linphone_core_destroy( _core );
  fclose( linphone_logger_file );
}

// init_actions will init all actions and binds in application
void DSipCom::init_actions() {
  // buttons
  QObject::connect( call_button, SIGNAL( clicked() ), this, SLOT( action_make_a_call() ));
  // menu bar:
  QObject::connect( action_about, SIGNAL( activated() ), this, SLOT( action_about_func() ));
  QObject::connect( action_connect_to_sip_server, SIGNAL( activated() ), this, SLOT( action_connect_to_sip_server_func() ));
  QObject::connect( action_disconnect_from_sip_server, SIGNAL( activated() ), this, SLOT( action_disconnect_from_sip_server_func() ));
}

void DSipCom::action_make_a_call() {
  (this)->call_button->setText( "Dzwonię" );
}

void DSipCom::action_about_func() {
  logger.log( "From about dialog!" );
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
