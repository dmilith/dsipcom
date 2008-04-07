/* 
 * File:   dsipcom_ui.h
 * Author: dmilith
 *
 * Created on 6 kwiecień 2008, 19:45
 */

#ifndef _DSIPCOM_UI_H
#define	_DSIPCOM_UI_H

#include <qt4/QtCore/Qt>
#include "ui_dsipcom.h"

namespace Ui {
class DSipCom : public QMainWindow, public Ui::MainWindow {
  
  Q_OBJECT
      
  public:
    DSipCom( QString title );
    void init_actions();
    void gogogo();

  public slots:
    void action_make_a_call();

  signals:
    void clicked();
  
};

}

#endif	/* _DSIPCOM_UI_H */

