/*
 * author: Daniel (dmilith) Dettlaff
 * email: dmilith at drakor.eu
 * released under GPL2 & LGPL license
 * (c) 2oo8
 *
 */


#ifndef _DSIPCOM_MAIN_H
#define _DSIPCOM_MAIN_H

// enabling debuging options
#define DEBUG
//#define WIN32
// enable asserts in code
#define D_ASSERT

#include <stdlib.h>

using namespace std;

const string SLASH = "/";
const string BACKSLASH = "\\";
static string pp = SLASH; // "normal" UNIX slash to separate parts path

// main declarations and constants
#ifndef WIN32
 const string DSIP_MAIN_DIR = string( getenv( "HOME" ) ) + pp + ".dSipCom";
#else
 pp = BACKSLASH;
 // TODO: fix static path for windows 
 const string DSIP_MAIN_DIR = string( "C:" + pp + "dSipCom" );
#endif
 
 const string LOGS_DIR = DSIP_MAIN_DIR + pp + "logs";
 const string CONF_DIR = DSIP_MAIN_DIR + pp + "config";
 const string ULIST_DIR = DSIP_MAIN_DIR + pp + "user_list";

 const string LOGGER_FILE = LOGS_DIR + pp + "dsipcom.main.log";
//	static const string LOGGER_LINPHONE = LOGS_DIR + "dsipcom.linphone.log";
 const string LOGGER_DSIPCOM_UI = LOGS_DIR + pp + "dsipcom.logger.ui.log";

 const string CONFIG_FILE = CONF_DIR + pp + "dsipcom.dcnf";
 const string LINPHONE_CONFIG = CONF_DIR + pp + "linphone.conf";

 const string USER_LIST_FILE = ULIST_DIR + pp + "dsipcom.dulf";
#endif
