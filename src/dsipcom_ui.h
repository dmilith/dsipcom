/* 
 * File:   dsipcom_ui.h
 * Author: dmilith
 *
 * Created on 6 kwiecień 2008, 19:45
 */

#ifndef _DSIPCOM_UI_H
#define	_DSIPCOM_UI_H

#include <qt4/QtCore/Qt>
#include <qt4/QtCore/QTextCodec>
#include <qt4/QtGui/QMessageBox>
#include "ui_dsipcom.h"

/* User Interface namespace is providing main UI inherited from automaticaly generated qt-designer templates */
namespace Ui {
  class DSipCom : public QMainWindow, public Ui::MainWindow {

    // qt4 ui macro (for actions)
    Q_OBJECT

    public:
      DSipCom( QString title );
      void init_actions();

    // qt4 action slots
    public slots:
      void action_make_a_call();
      void action_about_func();
      void action_connect_to_sip_server_func();
      void action_disconnect_from_sip_server_func();

    // qt4 action signals
    signals:
      void clicked();
  };

}

#endif	/* _DSIPCOM_UI_H */

