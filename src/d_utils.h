/*
 * author: Daniel (dmilith) Dettlaff
 * email: dmilith at drakor.eu
 * released under GPL2 & LGPL license
 * © 2oo8
 */

#ifndef D_UTILS_H
#define D_UTILS_H

#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>

using namespace std;
 
typedef struct {
  uint32_t day, month, year;
  char str1[50000]; // XXX: 50KB per log. it's awful way but easiest
} LOG_ELEMENT;


// strips specified string from all ''sign'' chars 
  string
  strip( string s, char sign );
  
// integer to C string converter
  const char*
  uint2cstr( uint64_t i );

  void
	write_one_log_by_date( string log, uint32_t day, uint32_t month, uint32_t year, const char* filename );

	const string
  read_one_log_by_date( uint32_t day, uint32_t month, uint32_t year, const char* filename );

#endif /* D_UTILS_H */

