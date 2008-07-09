/* 
 * File:   varsizes_test_32.cpp
 * Author: dmilith
 *
 * Created on 25 maj 2008, 18:38
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main(int argc, char** argv) {
  
  int variable = 123;
  printf( "\nint size: %d\n", sizeof( variable ) );

  long int variable2 = 123;
  printf( "\nlong int size: %d\n", sizeof( variable2 ) );
  
  short int variable3 = 123;
  printf( "\nshort int size: %d\n", sizeof( variable3 ) );
  
  char user_list_header[] = "dulf0";
  printf( "\ndulf0 size: %d", sizeof( user_list_header -1 ) );
  
  char* HOME = getenv( "HOME" );
  assert( getenv( "HOME" ) == HOME );
  
    return (EXIT_SUCCESS);
}

