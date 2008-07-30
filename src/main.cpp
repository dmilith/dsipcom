/*
 * author: Daniel (dmilith) Dettlaff
 * email: dmilith at drakor.eu
 * released under GPL2 & LGPL license
 * (c) 2oo8
 *
 */

#include <qt4/QtGui/QApplication>

//#include <osip2/osip.h>
//#include <osipparser2/osip_message.h>

#include <stdio.h>
#include <string>
#include <execinfo.h> 
#include "version.h" // main program version
#include "platform.h" // platform specific setting
#include "main.h" // main constants and settings
#include "dsipcom_ui.h" // main user interface

using namespace Ui;

void
received_normal_signal( int param ) {
  printf( "Received signal :%d\n", param );
}

void
backtrace( void ) {
  void *addresses[ 10 ];
  char **strings;
  uint64_t size = backtrace( addresses, 10 );
  strings = backtrace_symbols( addresses, size );
   printf( "Stack frames: %d\n", size );
    for ( uint64_t i = 0; i < size; i++ ) {
      printf( "%ld: %X\n", i, (uint64_t)addresses[ i ] );
      printf( "%s\n", strings[ i ] ); 
    }
  free(strings);
}

void
received_SIGSEGV_signal( int param ) {
  printf( "\n\nSIGSEGV!\n" );
  backtrace();
  exit(11);
}

int
main( int argc, char *argv[] ) {
  /* macro to load images from dsipcom.qrc
     could be problematic on some archs.. but on linux seems to be unecessary
     Q_INIT_RESOURCE(dsipcom); */ 
  
   QApplication app( argc, argv );
   DSipCom* main_obj = new DSipCom( MAIN_WINDOW_TITLE.c_str() );

   //signal handling
   signal( SIGINT, received_normal_signal );
   signal( SIGSEGV, received_SIGSEGV_signal );
   
   if ( app.exec() == 0 ) {
     delete main_obj;
   }
   
   return 0;
}
