#include "dsipcom_ui.h"
#include "logger.h"
#include "main.h"
#include "version.h"
#include "ui_dsipcom.h"

using namespace Log;
using namespace Ui;

Logger logger( "dsipcom.logger.ui", "debug" );

DSipCom::DSipCom( QString title ) {
    logger.log( "Initializing UI" );
     // drawing ui
     setupUi( this );
     // global ui encoding => utf8
     QTextCodec::setCodecForCStrings( QTextCodec::codecForName( "UTF-8" ) );
     // setting window flags
     Qt::WindowFlags flags;
     flags = Qt::Window; //| Qt::WindowMinimizeButtonHint | Qt::WindowStaysOnTopHint;
     setWindowFlags( flags );
     // ui settings
     setWindowTitle( title );
     toolBox->setCurrentIndex(0);
     show();
    logger.log( "Initializing QT4 actions" );
     init_actions();   
    logger.log( "DSipCom initialized" );
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
  //logger.log ((this)->number_entry->text());
  (this)->call_button->setText( "Dzwonię" );
}

void DSipCom::action_about_func() {
  logger.log( "From about dialog!" );
  QMessageBox::information(this, MAIN_WINDOW_TITLE," Program jest na licencji GPL.\nAutor: Daniel (dmilith) Dettlaff\n (c) 2oo8 ");
}

void DSipCom::action_connect_to_sip_server_func() {
  logger.log( "Trying to connect to server" );
    if ( (this)->user_sip_server->text() == "" ) {
      QMessageBox::information(this, MAIN_WINDOW_TITLE," Proszę podać w preferencjach użytkownika nazwę serwera! ");
    } else if (( (this)->user_sip->text() == "") || ( (this)->user_sip->text() == "sip:" )) {
      QMessageBox::information(this, MAIN_WINDOW_TITLE," Proszę podać w preferencjach adres SIP użytkownika! ");
    } else if ( (this)->user_password->text() == "" ) {
      QMessageBox::information(this, MAIN_WINDOW_TITLE," Proszę podać w preferencjach hasło SIP użytkownika! ");
    } else if ( (this)->user_name->text() == "" ) {
      QMessageBox::information(this, MAIN_WINDOW_TITLE," Proszę podać w preferencjach nazwę użytkownika! ");
    } else {
      // all required settings are ok
      logger.log( "All required data is OK!" );
      
    }
}

void DSipCom::action_disconnect_from_sip_server_func() {
  logger.log( "Trying to disconnect from server" ); 
}



