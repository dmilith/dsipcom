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
// enable asserts in code
#define D_ASSERT

#include <stdlib.h>

using namespace std;

// main declarations and constants
 const string DSIP_MAIN_DIR = string( getenv( "HOME" ) ) + "/.dSipCom";

 const string LOGS_DIR = DSIP_MAIN_DIR + "/logs";
 const string CONF_DIR = DSIP_MAIN_DIR + "/config";
 const string ULIST_DIR = DSIP_MAIN_DIR + "/user_list";

 const string LOGGER_FILE = LOGS_DIR + "/dsipcom.main.log";
//	static const string LOGGER_LINPHONE = LOGS_DIR + "/dsipcom.linphone.log";
 const string LOGGER_DSIPCOM_UI = LOGS_DIR + "/dsipcom.logger.ui.log";

 const string CONFIG_FILE = CONF_DIR + "/dsipcom.dcnf";
 const string LINPHONE_CONFIG = CONF_DIR + "/linphone.conf";

 const string USER_LIST_FILE = ULIST_DIR + "/dsipcom.dulf";

#endif
