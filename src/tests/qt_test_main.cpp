/*
 * author: Daniel (dmilith) Dettlaff
 * email: dmilith at drakor.eu
 * released under GPL2 & LGPL license
 * (c) 2oo8
 *
 */
#include <qt4/QtGui/QApplication>

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <string>
#include "qt_test_dialog.cpp"

int main( int argc, char *argv[] ) {

    QApplication app( argc, argv );
    new TestDialog("Test Dialog 1");
    assert( 0==0 );

  return 0;
}
