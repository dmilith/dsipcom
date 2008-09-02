/*
 * author: Daniel (dmilith) Dettlaff
 * email: dmilith at drakor . eu
 * released under GPL2 & LGPL license
 * (c) 2oo8
 *
 */

#include <cstring>
#include <cassert>
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

void
write_one_log_by_date( string log, uint32_t day, uint32_t month, uint32_t year, const char* filename ) {
  ofstream file( filename, ios_base::out | ios_base::binary | ios_base::app );
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

const string
read_one_log_by_date( uint32_t day, uint32_t month, uint32_t year, const char* filename ) {
	ifstream file( filename, ios_base::in | ios_base::binary );
  LOG_ELEMENT *str_result = new LOG_ELEMENT;
	string result = "";
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
			  if ( ( day == str_result->day) && ( month == str_result->month ) &&
            ( year == str_result->year ) ) result += str_result->str1;
		  }
	file.close();
	delete str_result;
	return result;
}


int
main() {

	assert( read_one_log_by_date( 8, 2, 35, "test_Logs" ) == "" );
  write_one_log_by_date( "jakas tresc\ndruga.", 1,2,3, "test_Logs" );
  write_one_log_by_date( "ABC.", 6,6,6, "test_Logs" );
  write_one_log_by_date( "DEF.", 6,6,6, "test_Logs" );
  write_one_log_by_date( "GHI..", 6,6,6, "test_Logs" );
    
  assert( read_one_log_by_date( 1, 2, 3, "test_Logs" ) == "jakas tresc\ndruga." );
	string z = read_one_log_by_date( 1, 2, 3, "test_Logs" );
  assert( read_one_log_by_date( 1, 2, 3, "test_Logs" ) != "jakas tresc\ndruga ." );
  assert( read_one_log_by_date( 1, 2, 3, "test_Logs" ) != "jakas  tresc\ndruga." );
  assert( read_one_log_by_date( 6, 6, 6, "test_Logs" ) == ( "ABC.DEF.GHI.." ) );
  assert( read_one_log_by_date( 4, 2, 99, "test_Logs" ) == "" );
  assert( read_one_log_by_date( 4, 2, 99, "test_Logs" ) != " " );
    
  return 0;
}

