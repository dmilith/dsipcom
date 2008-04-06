/* 
 * File:   main.cpp
 * Author: dmilith
 *
 * Created on 1 kwiecień 2008, 11:15
 */

#include <qt4/QtCore/Qt>
#include <qt4/QtCore/QTextOStream>
#include <qt4/QtGui/QWidget> 
#include <qt4/QtGui/QApplication>
#include <qt4/QtGui/QMainWindow>
#include <qt4/QtGui/QWidget>

#include <osip2/osip.h>
#include <osipparser2/osip_message.h>

#include "main.h"
#include "user_interface.h"
#include "ui_icons.h"
#include "logger.h"

using namespace Log;

class DSipCom : public Ui_MainWindow {
  public:
  DSipCom() {
    Logger logger("dsipcom.logger.ui");
    logger.log( "Initialising DSipCom" );
   	 setupUi( this );
     setWindowTitle( main_window_title );
     toolBox->setCurrentIndex(0);
     show();
    logger.log( "DSipCom initialised" );
  }
};


int
main(int argc, char *argv[]) {
  /* macro to load images from dsipcom.qrc
     could be problematic on some archs.. but on linux seems to be unecessary
     Q_INIT_RESOURCE(dsipcom); */

 QApplication app( argc, argv );
 
 Logger logger( "dsipcom.logger" ); // = new Logger();
 logger.log( "Loading DsipCom" );
 
 DSipCom *dsipcom = new DSipCom();

 QString z = dsipcom->user_sip->text();

    if ( dsipcom->user_sip->text() == "sip:" ) {
       logger.log( "Empty: user_sip" );
     }
     if ( dsipcom->user_sip->text() == "" ) {
       dsipcom->toolBox->setCurrentIndex(0);
     }

   QString a = dsipcom->number_entry->text();
   logger.log( a );

 return app.exec();
}
