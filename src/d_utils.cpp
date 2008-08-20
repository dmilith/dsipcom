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

