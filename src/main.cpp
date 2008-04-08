/* 
 * File:   main.cpp
 * Author: dmilith
 *
 * Created on 1 kwiecień 2008, 11:15
 */

#include <qt4/QtGui/QApplication>

#include <osip2/osip.h>
#include <osipparser2/osip_message.h>

#include "version.h" //main program version
#include "main.h" // main constants and settings
#include "logger.h" // logging facility
//#include "ui_icons.h" // ~ 1000 icons built in
#include "ui_dsipcom.h" //ui declaration
#include "dsipcom_ui.h" // main user interface
#include "sip_main.h"

using namespace Log;
using namespace Ui;
using namespace Sip;

int
main(int argc, char *argv[]) {
  /* macro to load images from dsipcom.qrc
     could be problematic on some archs.. but on linux seems to be unecessary
     Q_INIT_RESOURCE(dsipcom); */
     
   QApplication app( argc, argv );

   Logger logger( LOGGER_FILE );
   logger.log( "Loading DsipCom" );
 
   Ui::DSipCom *dsipcom = new Ui::DSipCom(MAIN_WINDOW_TITLE);
   //QString z = dsipcom->user_sip->text();
   
   if ( dsipcom->user_sip->text() == "sip:" ) {
       logger.log( "Empty: user_sip" );
   }
   if ( dsipcom->user_sip->text() == "" ) {
     dsipcom->toolBox->setCurrentIndex(0);
   }

   logger.log( "Initializing LinPhone" );
   SIP *sip = new SIP();
   
   //free(sip);
   //sip->handler
   //QString a = dsipcom->number_entry->text();
   //logger.log( a );
   logger.log( "Quitting" );
 return app.exec();
}
