/* 
 * File:   varsizes_test_32.cpp
 * Author: dmilith
 *
 * Created on 25 maj 2008, 18:38
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
  
  int variable = 123;
  printf( "int size: %d\n", sizeof( variable ) );

  long int variable2 = 123;
  printf( "long int size: %d\n", sizeof( variable2 ) );
  
  short int variable3 = 123;
  printf( "short int size: %d\n", sizeof( variable3 ) );
  
    return (EXIT_SUCCESS);
}

