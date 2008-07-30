/*
 * author: Daniel (dmilith) Dettlaff
 * email: dmilith at drakor.eu
 * released under GPL2 & LGPL license
 * (c) 2oo8
 *
 */

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <iostream>

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

using namespace std;
#define CONFIG_FILE "test.dcnf"

string strip( string s, char sign ) {
  std::string::iterator it = std::remove_if(s.begin(), s.end(),
  std::bind2nd(std::equal_to<char>(), sign ));
  s = std::string(s.begin(), it);
  return s;
}
        
int main() {
  
    USER_CONFIG *user_config = NULL, *readed = NULL;
    user_config = new USER_CONFIG;
    readed = new USER_CONFIG;

    strcpy( user_config->user_name, "dmilith" );
    // TODO: make crypted passwords 
    strcpy( user_config->user_password, "alaniemakota_nieszyfrowane!");
    strcpy( user_config->user_sip, "sip:dmilith@drak.kill.pl");
    strcpy( user_config->user_sip_server, "ekiga.net");

    //printf( "zapis\n" );
    FILE* config_file;
    config_file = fopen( CONFIG_FILE, "wb" );
    fwrite( user_config, sizeof( USER_CONFIG ), 1, config_file );
    fclose( config_file );

    //printf( "odczyt\n" );
    config_file = fopen( CONFIG_FILE, "rb" );
    fread( readed, sizeof( USER_CONFIG ), 1, config_file );
    fclose( config_file );

    //printf( "%s\n%s\n\n", readed->user_name, readed->user_password );

    assert( (string)user_config->user_name == (string)readed->user_name );
    assert( (string)user_config->user_password == (string)readed->user_password );


    std::string s = " V er   tic es ";
    // removing spaces from string (utils.h):
    assert( strip( " v d f  ", ' ' ) == (string)"vdf" );
    assert( strip( " z***ło s,23*(%^&#  *", '*') == (string)" zło s,23(%^&#  " );
    assert( strip( "  ", ' ') == (string)"" );
    assert( strip( "123", '*') == (string)"123" );
    assert( strip( "% % %", '%') == (string)"  " );
    
  return 0;
}
