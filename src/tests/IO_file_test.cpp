/*
 * author: Daniel (dmilith) Dettlaff
 * email: dmilith at drakor . eu
 * released under GPL2 & LGPL license
 * (c) 2oo8
 *
 */

#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>

#define CONFIG_FILE "test.dcnf"


// TODO: make crypted passwords 
//

using namespace std;

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


string
strip( string s, char sign ) {
  string::iterator it = remove_if(s.begin(), s.end(),
  bind2nd( equal_to<char>(), sign ));
  s = string( s.begin(), it );
  return s;
}


const char*
uint2cstr( uint64_t i ) {
  stringstream ss;
  string temp;
  ss << i;
  ss >> temp;
  return temp.c_str();
}


int
main() {
// uint2cstr test
  uint32_t z32 = 1234567890;
    assert( uint2cstr( z32 ) == (string)"1234567890" );
  uint64_t z64 = 1234567890;
    assert( uint2cstr( z64 ) == (string)"1234567890" );
  
  z32 = 12345678901234567890;
    assert( uint2cstr( z32 ) != (string)"12345678901234567890" );
  z64 = 12345678901234567890;
    assert( uint2cstr( z64 ) == (string)"12345678901234567890" );
  
  // data writing to file test 1
    USER_CONFIG *user_config = NULL, *readed = NULL;
    user_config = new USER_CONFIG;
    readed = new USER_CONFIG;
      strcpy( user_config->user_name, "dmilith" );
      strcpy( user_config->user_password, "alaniemakota_nieszyfrowane!");
      strcpy( user_config->user_sip, "sip:dmilith@drak.kill.pl");
      strcpy( user_config->user_sip_server, "ekiga.net");
    FILE* config_file;
      config_file = fopen( CONFIG_FILE, "wb" );
      fwrite( user_config, sizeof( USER_CONFIG ), 1, config_file );
      fclose( config_file );
      config_file = fopen( CONFIG_FILE, "rb" );
      fread( readed, sizeof( USER_CONFIG ), 1, config_file );
      fclose( config_file );
      assert( (string)user_config->user_name == (string)readed->user_name );
      assert( (string)user_config->user_password == (string)readed->user_password );
  
    // removing spaces from string (utils.h):
      assert( strip( " V er   tic es ", ' ' ) == (string)"Vertices" );
      assert( strip( " v d f  ", ' ' ) == (string)"vdf" );
      assert( strip( " z***ło s,23*(%^&#  *", '*') == (string)" zło s,23(%^&#  " );
      assert( strip( "  ", ' ') == (string)"" );
      assert( strip( "123", '*') == (string)"123" );
      assert( strip( "% % %", '%') == (string)"  " );

  return 0;
}

