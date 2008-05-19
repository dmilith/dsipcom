#include <stdio.h>

typedef struct {
  char[50] contact_name;
  char[50] contact_sip_address;

} USER_LIST;

typedef struct {
  char[50] user_sip_server;
  char[50] user_sip;
  char[50] user_password;
  char[50] user_name;

} USER_CONFIG;


#define CONFIG_FILE "test.dcnf"

int main() {
  
  
  USER_CONFIG *user_config = NULL, *readed = NULL;
  user_config = new USER_CONFIG;
  readed = new USER_CONFIG;
  
  user_config->user_name = "dmilith";
  // TODO: make crypted passwords 
  user_config->user_password = "alaniemakota_nieszyfrowane!";
  user_config->user_sip = "sip:dmilith@drak.kill.pl";
  user_config->user_sip_server = "ekiga.net";
  
  printf( "zapis\n" );
  FILE* config_file;
  config_file = fopen( CONFIG_FILE, "wb" );
  fwrite( user_config, sizeof( USER_CONFIG ), 1, config_file );
  fclose( config_file );
  
  printf( "odczyt\n" );
  config_file = fopen( CONFIG_FILE, "rb" );
  fread( readed, sizeof( USER_CONFIG ), 1, config_file );
  fclose( config_file );
  
  printf( "%s\n%s\n\n", readed->user_name, readed->user_password );
  
  return 0;
}
