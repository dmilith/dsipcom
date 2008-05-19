/* 
 * File:   dsipcom_ui.h
 * Author: dmilith
 *
 * Created on 6 kwiecień 2008, 19:45
 */

#ifndef _DSIPCOM_UI_H
#define	_DSIPCOM_UI_H

#include <stdio.h>

#include <qt4/QtCore/Qt>
#include <qt4/QtGui/QDialog>
#include <qt4/QtCore/QTextCodec>
#include <qt4/QtGui/QMessageBox>
#include <qt4/QtCore/QQueue>

#include <linphone/config.h>
#include <linphone/linphonecore.h>

#include "ui_dsipcom.h" // automaticly generated interface from ui file
#include "ui_add_contact_dialog.h" // automaticly generated widget window
#include "logger.h" //logger defs
#include "main.h"

// Linphone definitions
#define MAX_PENDING_AUTH 8
#define HISTSIZE 500		/* how many lines of input history */
#define PROMPT_MAX_LEN 256	/* max len of prompt string */
#define LINE_MAX_LEN 256	/* really needed ? */
#define LPC_READLINE_TIMEOUT 1000000

// Linphone defs:
typedef struct {
  LinphoneAuthInfo *elem[MAX_PENDING_AUTH];
  int nitems;
} LPC_AUTH_STACK;


/* User Interface namespace is providing main UI inherited from automaticaly generated qt-designer templates */
namespace Ui {
  
  class AddContactWindow : public QDialog, public Ui::addUserDialog { 
    // qt4 ui macro (for actions)
    Q_OBJECT
        
    public:
      AddContactWindow( QWidget *parent );
      ~AddContactWindow();
      void init_actions();

    public slots:
      void action_done();
      void action_cancel();
     
    signals:
      void clicked();
  };
  
  class SipMutex {
    public:
      SipMutex() {
        pthread_mutex_init( &_mutex, NULL );
      }
      void lock() {
        pthread_mutex_lock( &_mutex );
      }
      void unlock() {
        pthread_mutex_unlock( &_mutex );
      }
      ~SipMutex() {
        pthread_mutex_destroy( &_mutex );
      }
    private:
      pthread_mutex_t _mutex;
  };
  
    
  class DSipCom : public QMainWindow, public Ui::MainWindow {
    // qt4 ui macro (for actions)
    Q_OBJECT

    public:
      DSipCom( const QString& title = "dSipCom" );
      DSipCom();
     ~DSipCom();
     
      // init qt4 actions (ui slots and signals)
      void init_actions();
      
      // init linphone
      void create_linphone_core();
      LinphoneCore *_core;
	    SipMutex _mutex;
      FILE* linphone_logger_file;

      // add contact dialog:
      AddContactWindow* dialog;
      
    // qt4 action slots
    public slots:
      void action_make_a_call();
      void action_end_call();
      void action_about_func();
      void action_add_contact_func();
      void action_remove_contact_func();
      void action_connect_to_sip_server_func();
      void action_disconnect_from_sip_server_func();
      void action_enter_0();
      void action_enter_1();
      void action_enter_2();
      void action_enter_3();
      void action_enter_4();
      void action_enter_5();
      void action_enter_6();
      void action_enter_7();
      void action_enter_8();
      void action_enter_9();
      void action_enter_star();
      void action_enter_hash();
      
    // qt4 action signals
    signals:
      void clicked();
  };

} // of namespace

#endif	/* _DSIPCOM_UI_H */

