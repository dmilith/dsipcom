#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;

typedef struct {
  uint32_t day, month, year;
  string str1;
  uint32_t str1_len;
} LOG_ELEMENT;

void write_this_log( string& log, uint32_t day, std::string& filename ) {
}

const string read_one_log_by_date( uint32_t day, uint32_t month, uint32_t year, std::string filename ) {
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
 
    //assert( str_result.str1 == result );
    return result;
}

int main() {
// data writing to file test 2 ( strings )
    LOG_ELEMENT str_test;
    
    str_test.str1 = "Ala ma kota, a mąż Ali ma kolejne\ndwa\npołączenia\nSformatowane po swojemu.";
    str_test.str1_len = str_test.str1.length();
    str_test.day = 5;
    str_test.month = 6;
    str_test.year = 7;

    FILE* test_file;
    test_file = fopen( "test_Logs", "wb+" );
      fwrite( &str_test.day, sizeof( uint32_t ), 1, test_file );
      fwrite( &str_test.month, sizeof( uint32_t ), 1, test_file );
      fwrite( &str_test.year, sizeof( uint32_t ), 1, test_file );
      fwrite( &str_test.str1_len, sizeof( uint32_t ), 1, test_file );
      fwrite( str_test.str1.c_str(), str_test.str1_len + 1, 1, test_file );
      
    str_test.str1 = "Już dawno nie zrobiłem się tak pozytywnie po jejego.";
    str_test.str1_len = str_test.str1.length();
    str_test.day = 1;
    str_test.month = 2;
    str_test.year = 3;
      fwrite( &str_test.day, sizeof( uint32_t ), 1, test_file );
      fwrite( &str_test.month, sizeof( uint32_t ), 1, test_file );
      fwrite( &str_test.year, sizeof( uint32_t ), 1, test_file );
      fwrite( &str_test.str1_len, sizeof( uint32_t ), 1, test_file );
      fwrite( str_test.str1.c_str(), str_test.str1_len + 1, 1, test_file );
    fclose( test_file );


    cout << "Wynik1: ";
    cout << read_one_log_by_date( 1, 2, 3, "test_Logs" ) << endl;
    cout.flush();
    
    cout << "Wynik2: ";
    cout << read_one_log_by_date( 5, 6, 7, "test_Logs" ) << endl;
    cout.flush();
      
  return 0;
}
