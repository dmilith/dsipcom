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

#include <stdio.h>
#include <string>
#include "version.h" // main program version
#include "platform.h" // platform specific setting
#include "main.h" // main constants and settings
#include "dsipcom_ui.h" // main user interface

using namespace Ui;

void receive_signal( int param ) {
  printf( "Received signal :%d\n", param );
}

int main( int argc, char *argv[] ) {
  /* macro to load images from dsipcom.qrc
     could be problematic on some archs.. but on linux seems to be unecessary */
     Q_INIT_RESOURCE(dsipcom); 
   QApplication app( argc, argv );
   new DSipCom( MAIN_WINDOW_TITLE.c_str() );

   //signal handling
   //signal( SIGTERM, receive_signal );
   signal( SIGINT, receive_signal );
   //signal( SIGSEGV, receive_signal );
   
  return app.exec();
}
