/* 
 * File:   utils.h
 * Author: dmilith
 *
 * Created on 30 lipiec 2008, 14:04
 */

#ifndef D_UTILS_H
#define D_UTILS_H

#include <iostream>
#include <algorithm>
#include <string.h>
#include <sstream>

using namespace std;
  
// strips specified string from all ''sign'' chars 
  string
  strip( string s, char sign );
  
// integer to C string converter
  const char*
  uint2cstr( uint64_t i );

#endif /* _UTILS_H */

