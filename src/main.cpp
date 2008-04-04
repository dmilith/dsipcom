#ifdef HAVE_CONFIG_H
#include <config.h>
#endif
#include <qt4/QtCore/Qt>
#include <qt4/QtGui/QWidget> 
#include <qt4/QtGui/QApplication>
#include <qt4/QtGui/QMainWindow>
#include <qt4/QtGui/QWidget>

#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <osip2/osip.h>
#include <osipparser2/osip_message.h>

#include "main.h"
#include "user_interface.h"
#include "ui_icons.h"

//#include <linphone/config.h>
//#include <linphone/linphonecore.h>
//#include <mediastreamer2/mediastream.h>
//#include <eXosip2/eXosip.h>
//#include <osipparser2/osip_message.h>
//#include <ortp/ortp.h>
//#include <ortp/payloadtype.h>
//#include <mediastreamer2/mscommon.h>

using namespace Ui;
using namespace std;


class DSipCom {
public:
  
  void
  do_something() {
    std::cout << "złooo";
  }  

  
  DSipCom() {
     MainWindow *main_window = new MainWindow();
   	 main_window->setupUi( main_window );
     main_window->setWindowTitle( main_window_title );

     QString z;
     z = main_window->user_sip->text();
     //QTreeView *tree = new QTreeView();

     if ( main_window->user_sip->text().toUtf8().length() == 0 ) {
       cout << "pusty user_sip" << endl;
     }

     if ( main_window->user_sip->text().toUtf8().length() == 0 ) {
       //main_window->page_dialer->show(); 
       //main_window->page_dialer->setVisible(true);
       //main_window->page_dialer->setFocus();
       main_window->toolBox->setCurrentIndex(2);
       main_window->repaint();
     }

     //osip_call_info_t *osip = new osip_call_info_t();
     osip_to_t *to = new osip_to_t();
     //to->displayname = (char*)"dmilith@sip.com";

     int errcode = NULL;
     char *a_to = NULL;

     a_to = (char *) osip_malloc (200);
     //res = fgets (a_to, 200, tos_file);    /* lines are under 200 */
     osip_to_init(&to);
     a_to = (char*)"<sip:dmilith@actio.pl>\n";
     errcode = osip_to_parse(to, a_to);
     cout << errcode << endl;
     //cout << to->displayname() << endl;

     osip_to_free(to);
     //osip_free(a_to);

     main_window->show();
  }
};

int
main(int argc, char *argv[]) {
   //Q_INIT_RESOURCE(app);

   QApplication app( argc, argv );
   DSipCom *starter = new DSipCom();
   return app.exec();
}
