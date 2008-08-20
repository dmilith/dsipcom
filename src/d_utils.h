/*
 
    This is OpenSource Project;
    It's licensed on GPL/ LGPL public license;
    It's written by Daniel (dmilith) Dettlaff since August 2oo8.
    You can redistribute this project only with this header.
    
*/

#ifndef D_UTILS_H
#define D_UTILS_H

#include <iostream>
#include <algorithm>
#include <string.h>
#include <sstream>
#include <vector>
#include <fstream>

using namespace std;
 
typedef struct {
  uint32_t day, month, year;
  char str1[50000]; // 50KB per log. it's awful way but easiest
} LOG_ELEMENT;


// strips specified string from all ''sign'' chars 
  string
  strip( string s, char sign );
  
// integer to C string converter
  const char*
  uint2cstr( uint64_t i );

  void
	write_one_log_by_date( std::string log, uint32_t day, uint32_t month, uint32_t year, const char* filename );

	const
	std::string read_one_log_by_date( uint32_t day, uint32_t month, uint32_t year, const char* filename );

#endif /* _UTILS_H */

