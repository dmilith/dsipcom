/*
 * author: Daniel (dmilith) Dettlaff
 * email: dmilith at drakor . eu
 * released under GPL2 & LGPL license
 * (c) 2oo8
 *
 */

#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <iostream>
#include <string>
#include <cstdint>

using namespace std;

int
main( int argc, char** argv ) {
  
    if ( sizeof( void * ) == 8 ) { // 64bit
        assert( sizeof( int ) == 4 );
        assert( sizeof( long int ) == 8 );
        assert( sizeof( short int ) == 2 );
        assert( sizeof( double ) == 8);
      char a[] = "dulf0";
        assert( sizeof( a ) == 5+1 );
        string b = "dulf0";
        assert( sizeof( b ) == 8 );
      char* HOME = getenv( "HOME" );
        assert( getenv( "HOME" ) == HOME );
        string HOME2 = getenv( "HOME" );
        assert( getenv( "HOME" ) == HOME2 );
      uint64_t number = 123;
        assert( sizeof( number ) == 8 );
        assert( sizeof( char ) == 1 );
        assert( sizeof( char[5] ) == 5 );
    }
    
    if ( sizeof( void * ) == 4 ) { // 32bit
        assert( sizeof( int ) == 4 );
        assert( sizeof( long int ) == 4 );
        assert( sizeof( short int ) == 2 );
        assert( sizeof( double ) == 8);
      char a[] = "dulf0";
        assert( sizeof( a ) == 5 + 1 );
        string b = "dulf0";
        assert( sizeof( b ) == 4 );
      char* HOME = getenv( "HOME" );
        assert( getenv( "HOME" ) == HOME );
        string HOME2 = getenv( "HOME" );
        assert( getenv( "HOME" ) == HOME2 );
      uint64_t liczba = 123;
        assert( sizeof( liczba ) == 8 );
        assert( sizeof( char ) == 1 );
        assert( sizeof( char[5] ) == 5 );
    }
    return (EXIT_SUCCESS);
}

