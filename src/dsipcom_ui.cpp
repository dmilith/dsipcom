#include "dsipcom_ui.h"
#include "logger.h"
#include "main.h"
#include "ui_dsipcom.h"

using namespace Log;
using namespace Ui;

Logger logger( "dsipcom.logger.ui" );

DSipCom::DSipCom( QString title ) {
     setupUi( this );
    logger.log( "Initializing UI" );
     setWindowTitle( title );
     toolBox->setCurrentIndex(0);
     show();
    logger.log( "Initializing QT4 actions" );
     init_actions();   
    logger.log( "DSipCom initialized" );
}

// init_actions will init all actions and binds in application
void DSipCom::init_actions() {
  QObject::connect( call_button, SIGNAL( clicked() ), this, SLOT( action_make_a_call() ));
  (this)->call_button->setText("tu pres");
}

void DSipCom::action_make_a_call() {
 // QMessageBox::information(this, "Some window label here", "String: " + caller);
  logger.log( "gogogo" );
  QString zlo = "wykonuje rozmowe";
  zlo = zlo.toAscii();
  (this)->call_button->setText( zlo );
}
