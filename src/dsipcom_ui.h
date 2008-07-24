/*
 * author: Daniel (dmilith) Dettlaff
 * email: dmilith at drakor.eu
 * released under GPL2 & LGPL license
 * (c) 2oo8
 *
 */

#ifndef _DSIPCOM_UI_H
#define	_DSIPCOM_UI_H

#include <stdio.h>
#include <stdint.h>
#include <signal.h>
#include <assert.h>

#include <qt4/QtCore/Qt>
#include <qt4/QtCore/QFile>
#include <qt4/QtGui/QDialog>
#include <qt4/QtCore/QTextCodec>
#include <qt4/QtGui/QMessageBox>
#include <qt4/QtCore/QQueue>

#include <linphone/config.h>
#include <linphone/linphonecore.h>

#include <string>
#include <sstream>
#include <boost/filesystem/operations.hpp>

#include "ui_dsipcom.h" // automaticly generated interface from ui file
#include "ui_add_contact_dialog.h" // automaticly generated widget window
#include "ui_about.h" // obviously, just about window
#include "logger.h" //logger defs
#include "main.h"

// integer to C string converter
static const char*
uint2cstr( uint64_t i ) {
  stringstream ss;
  string temp;
  ss << i;
  ss >> temp;
  return temp.c_str();
}

#define MAX_PENDING_AUTH 8
//#define HISTSIZE 500		/* how many lines of input history */
#define PROMPT_MAX_LEN 256	/* max len of prompt string */
#define LINE_MAX_LEN 256	/* really needed ? */

// Linphone definitions
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
	// 64bit numbers no matter system architecture
  uint32_t out_soundcard;
  uint32_t in_soundcard;
  uint32_t recording_source;
  char ring_sound[255];
  char default_port[5];
  uint32_t no_firewall;
  uint32_t use_stun_server;
  char stun_address[50];
  uint32_t manual_firewall_address;
  char firewall_address[50];
  uint32_t gsm_8_codec;
  uint32_t speex_8_codec;
  uint32_t speex_16_codec;
  uint32_t pcmu_8_codec;
  uint32_t pcma_8_codec;
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
      AboutBox();
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
      void setupDIRs();
      void load_user_list();
      void save_user_list();
      void load_user_config();
      void save_user_config();
      
      // init linphone
      void apply_settings_to_linphone();
      void create_linphone_core();
      //LinphoneCore *_core;
      LinphoneCore linphonec;
	    //SipMutex _mutex;
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

