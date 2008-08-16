/*
 * author: Daniel (dmilith) Dettlaff
 * email: dmilith at drakor.eu
 * released under GPL2 & LGPL license
 * (c) 2oo8
 *
 */

#include "d_utils.h"

using namespace std;

string strip( string s, char sign ) {
  string::iterator it = remove_if( s.begin(), s.end(),
  bind2nd( equal_to<char>(), sign ) );
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

void
write_one_log_by_date( string log, uint32_t day, uint32_t month, uint32_t year, std::string filename ) {
    FILE* test_file;
    LOG_ELEMENT str_test;
    str_test.day = day;
    str_test.month = month;
    str_test.year = year;
    str_test.str1_len = log.length();
    str_test.str1 = log;
    test_file = fopen( filename.c_str(), "ab" );
      fwrite( &str_test.day, sizeof( uint32_t ), 1, test_file );
      fwrite( &str_test.month, sizeof( uint32_t ), 1, test_file );
      fwrite( &str_test.year, sizeof( uint32_t ), 1, test_file );
      fwrite( &str_test.str1_len, sizeof( uint32_t ), 1, test_file );
      fwrite( str_test.str1.c_str(), str_test.str1_len + 1, 1, test_file );
    fclose( test_file );
}

const string
read_one_log_by_date( uint32_t day, uint32_t month, uint32_t year, std::string filename ) {
    FILE* test_file;
    char* result;
    LOG_ELEMENT str_result;
      test_file = fopen( filename.c_str(), "rb+" );
      //searching through elements in file
      while (! ( feof(test_file) ) ) {
        fread( &str_result.day, sizeof( uint32_t ), 1, test_file );
        fread( &str_result.month, sizeof( uint32_t ), 1, test_file );
        fread( &str_result.year, sizeof( uint32_t ), 1, test_file );
        fread( &str_result.str1_len, sizeof( uint32_t ), 1, test_file );
        fread( (void*)str_result.str1.c_str(), str_result.str1_len + 1, 1, test_file );
        result = new char[ str_result.str1_len ];
        if ( ( day == str_result.day ) && ( month == str_result.month ) && ( year == str_result.year ) ) {
          strncpy( result, str_result.str1.c_str(), str_result.str1_len );
          break;
        }
      }
      fclose( test_file );
    return result;
}

