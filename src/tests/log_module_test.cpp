//#include <cstdio>
//#include <cstdlib>
#include <string.h>
#include <assert.h>
#include <algorithm>
#include <sstream>
#include <vector>

#include <fstream>
#include <iostream>


#define DEBUG

using namespace std;

typedef struct {
  uint32_t day, month, year;
  char str1[50000];
} LOG_ELEMENT;

void write_one_log_by_date( std::string log, uint32_t day, uint32_t month, uint32_t year, const char* filename ) {
    std::ofstream file( filename, ios_base::out | ios_base::binary | ios_base::app );
    LOG_ELEMENT *log_n = new LOG_ELEMENT;
		log_n->day = day;
    log_n->month = month;
    log_n->year = year;
    strcpy( log_n->str1, log.c_str() );
		file.write( (char*)log_n, sizeof( LOG_ELEMENT ) );
		file.close();
		delete log_n;
		return;
}

const std::string read_one_log_by_date( uint32_t day, uint32_t month, uint32_t year, const char* filename ) {
		std::ifstream file( filename, ios_base::in | ios_base::binary );
    LOG_ELEMENT *str_result = new LOG_ELEMENT;
		std::string result = "";
	 	if ( !file ) return "";
		while ( file.good() ) {
			file.read( (char*)str_result, sizeof( LOG_ELEMENT ) );
			if ( file.eof() ) {
#ifdef DEBUG
	std::cout << "EOF" << std::endl;
	std::cout.flush();
#endif
				break;
			}
			if ( ( day == str_result->day) && ( month == str_result->month ) && ( year == str_result->year ) ) result += str_result->str1;
		}
		file.close();
		delete str_result;
		return result;
}


/*
void write_one_log_by_date( string log, uint32_t day, uint32_t month, uint32_t year, std::string filename ) {
    FILE* test_file;
    LOG_ELEMENT str_test;
    str_test.day = day;
    str_test.month = month;
    str_test.year = year;
    str_test.str1_len = log.length();
    str_test.str1 = log;
    -test_file = fopen( filename.c_str(), "ab" );
      fwrite( &str_test.day, sizeof( uint32_t ), 1, test_file );
      fwrite( &str_test.month, sizeof( uint32_t ), 1, test_file );
      fwrite( &str_test.year, sizeof( uint32_t ), 1, test_file );
      fwrite( &str_test.str1_len, sizeof( uint32_t ), 1, test_file );
      fwrite( str_test.str1.c_str(), str_test.str1_len + 1, 1, test_file );
    fclose( test_file );
}

const string read_one_log_by_date( uint32_t day, uint32_t month, uint32_t year, const char* filename ) {
    FILE* test_file;
    string log = "";
    vector<string> z;
    char* result;
    LOG_ELEMENT str_result;
      test_file = fopen( filename, "rb" );
      if ( test_file == 0 ) return "";
      //searching through elements in file
      while (! ( feof(test_file) ) ) {
        fread( &str_result.day, sizeof( uint32_t ), 1, test_file );
        fread( &str_result.month, sizeof( uint32_t ), 1, test_file );
        fread( &str_result.year, sizeof( uint32_t ), 1, test_file );
        fread( &str_result.str1_len, sizeof( uint32_t ), 1, test_file );
        fread( (void*)( (str_result.str1) ), str_result.str1_len + 1, 1, test_file );
        result = new char[ str_result.str1_len + 1 ];
        if ( ( day == str_result.day ) && ( month == str_result.month ) && ( year == str_result.year ) ) {
          strncpy( result, str_result.str1, str_result.str1_len + 1 );
          log = (string)result;
          if ( z.empty() ) z.push_back( log ); else
            if ( (string)z.at( z.size() - 1 ) != log ) z.push_back( log );
          delete[] result;
        }
      }
      fclose( test_file );
      log = "";
      for ( uint32_t i = 0; i < z.size(); i++ ) {
        log += (string)z.at( i );
      }
  #ifdef DEBUG
      cout << "\nXXX\n" << log << "\nZZZ\n";
      cout.flush();
  #endif
    return log;
}
*/

int main() {
// data writing to file test 2 ( strings )
    
		assert( read_one_log_by_date( 8, 2, 35, "test_Logs" ) == "" );
   
    write_one_log_by_date( "jakas tresc\ndruga.", 1,2,3, "test_Logs" );
    write_one_log_by_date( "ABC.", 6,6,6, "test_Logs" );
    write_one_log_by_date( "DEF.", 6,6,6, "test_Logs" );
    write_one_log_by_date( "GHI..", 6,6,6, "test_Logs" );
    
    // loading and checking values
    assert( read_one_log_by_date( 1, 2, 3, "test_Logs" ) == "jakas tresc\ndruga." );
		std::string z = read_one_log_by_date( 1, 2, 3, "test_Logs" );
    assert( read_one_log_by_date( 1, 2, 3, "test_Logs" ) != "jakas tresc\ndruga ." );
    assert( read_one_log_by_date( 1, 2, 3, "test_Logs" ) != "jakas  tresc\ndruga." );
    assert( read_one_log_by_date( 6, 6, 6, "test_Logs" ) ==
           ( "ABC.DEF.GHI.." ) );
    assert( read_one_log_by_date( 4, 2, 99, "test_Logs" ) == "" );
    assert( read_one_log_by_date( 4, 2, 99, "test_Logs" ) != " " );
    
  return 0;
}
