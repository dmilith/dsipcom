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

#include <qt4/QtCore/QTimer>
#include <qt4/QtCore/Qt>
#include <qt4/QtCore/QFile>
#include <qt4/QtGui/QDialog>
#include <qt4/QtCore/QTextCodec>
#include <qt4/QtGui/QMessageBox>
#include <qt4/QtCore/QQueue>
// interesting way to make widget int omain window.. #include <qt4/QtGui/QDockWidget>

#include <linphone/config.h>
#include <linphone/linphonecore.h>

#include <string>
#include <iostream>
#include <sstream>
#include <boost/filesystem/operations.hpp>

#include "d_utils.h"
#include "ui_dsipcom.h" // automaticly generated interface from ui file
#include "ui_add_contact_dialog.h" // automaticly generated widget window
#include "ui_about.h" // obviously, just about window
#include "logger.h" //logger defs
#include "main.h"


#define MAX_PENDING_AUTH 8
#define PROMPT_MAX_LEN 256	/* max len of prompt string */
#define LINE_MAX_LEN 256	/* really needed ? */

// Linphone definitions
typedef struct {
  LinphoneAuthInfo *elem[MAX_PENDING_AUTH];
  int nitems;
} LPC_AUTH_STACK;

typedef struct {
  char user_sip_server[50];
  char user_sip[50];
  char user_password[50];
  char user_name[50];
	// 64bit numbers no matter system architecture
  char out_soundcard[50];
  char in_soundcard[50];
  char recording_source[50];
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

      // add contact dialog:
      AddContactWindow *dialog;
      QVector<LinphoneAuthInfo> user_list;
      USER_CONFIG *user_config;
      
    // qt4 action slots
    public slots:
      void linphonec_main_loop();
      void reset_status_bar();
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

