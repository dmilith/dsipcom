/*
 * author: Daniel (dmilith) Dettlaff
 * email: dmilith at drakor.eu
 * released under GPL2 & LGPL license
 * (c) 2oo8
 *
 */

#include <qt4/QtGui/QApplication>

#include <osip2/osip.h>
#include <osipparser2/osip_message.h>

#include <signal.h>
#include <stdio.h>

#include "version.h" // main program version
#include "platform.h" // platform specific setting
#include "main.h" // main constants and settings
#include "logger.h" // logging facility
#include "dsipcom_ui.h" // main user interface


using namespace Log;
using namespace Ui;

void
quit_dsipcom( int param ) {
  printf( "Received signal :%d\n", param );
  exit( param );
}

int
main( int argc, char *argv[] ) {
  /* macro to load images from dsipcom.qrc
     could be problematic on some archs.. but on linux seems to be unecessary
     Q_INIT_RESOURCE(dsipcom); */
   QApplication app( argc, argv );
   new DSipCom( MAIN_WINDOW_TITLE );
   Logger logger( LOGGER_FILE );
   logger.log( "Loading DsipCom" );


   //signal handling
   signal( SIGTERM, quit_dsipcom );
   signal( SIGINT, quit_dsipcom );
   signal( SIGSEGV, quit_dsipcom );
   
  return app.exec();
}
