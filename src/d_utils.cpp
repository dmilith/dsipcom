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
