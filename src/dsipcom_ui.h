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
#include <qt4/QtCore/QFile>
#include <qt4/QtGui/QDialog>
#include <qt4/QtCore/QTextCodec>
#include <qt4/QtGui/QMessageBox>
#include <qt4/QtCore/QQueue>

#include <linphone/config.h>
#include <linphone/linphonecore.h>

#include "ui_dsipcom.h" // automaticly generated interface from ui file
#include "ui_add_contact_dialog.h" // automaticly generated widget window
#include "ui_about.h" // obviously, just about window
#include "logger.h" //logger defs
#include "main.h"

// Linphone definitions
#define MAX_PENDING_AUTH 8
//#define HISTSIZE 500		/* how many lines of input history */
#define PROMPT_MAX_LEN 256	/* max len of prompt string */
#define LINE_MAX_LEN 256	/* really needed ? */
//#define LPC_READLINE_TIMEOUT 1000000

// Linphone defs:
typedef struct {
  LinphoneAuthInfo *elem[MAX_PENDING_AUTH];
  int nitems;
} LPC_AUTH_STACK;

typedef struct {
  char contact_name[50];
  char contact_sip_address[50];
} USER_LIST;

typedef struct {
  char user_sip_server[50];
  char user_sip[50];
  char user_password[50];
  char user_name[50];
} USER_CONFIG;


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
  
  class AboutBox : public QDialog, public Ui::AboutWindow { 
    // qt4 ui macro (for actions)
    Q_OBJECT
        
    public:
      AboutBox( QString version = "0.0.0" );
      ~AboutBox();
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
     ~DSipCom();
     
      // init qt4 actions (ui slots and signals)
      void init_actions();
      
      // loading data from files
      void load_user_list();
      void save_user_list();
      void load_user_config();
      void save_user_config();
      
      // init linphone
      void create_linphone_core();
      LinphoneCore *_core;
	    SipMutex _mutex;
      FILE* linphone_logger_file;

      // add contact dialog:
      AddContactWindow *dialog;
      QVector<USER_LIST> user_list;
      USER_CONFIG *user_config;
      
    // qt4 action slots
    public slots:
      void action_help_func();
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
      void action_save_user_config();
      void action_load_user_config();
      void action_save_user_list();
      void action_load_user_list();
      
    // qt4 action signals
    signals:
      void clicked();
  };

} // of namespace

#endif	/* _DSIPCOM_UI_H */

