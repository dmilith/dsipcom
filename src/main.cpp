/*
 * author: Daniel (dmilith) Dettlaff
 * email: dmilith at drakor.eu
 * released under GPL2 & LGPL license
 * © 2oo8
 */

#include "main.h" // main constants and settings
#include "version.h" // main program version
#include "platform.h" // platform specific setting
#include "dsipcom_ui.h" // main user interface

using namespace Ui;


void
backtrace( void ) {
  void *addresses[ 10 ];
  char **strings;
  uint64_t size = backtrace( addresses, 10 );
  strings = backtrace_symbols( addresses, size );
   cout << "Stack frames: " << size << endl;
    for ( uint64_t i = 0; i < size; i++ ) {
      cout << i << " : " << (uint64_t)addresses[ i ] << endl;
      cout << strings[ i ]; 
    }
  free(strings);
}

void
received_normal_signal( int param ) {
  cout << "\n\nReceived signal : " << param << endl;
  backtrace();
}

void
received_SIGSEGV_signal( int param ) {
  cout << "\n\nSIGSEGV : " << param << " !\n";
  backtrace();
  exit(11);
}

int
main( int argc, char *argv[] ) {
  /* macro to load images from dsipcom.qrc
     could be problematic on some archs.. but on linux seems to be unecessary
     TODO: make dependancy to running OS,
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
