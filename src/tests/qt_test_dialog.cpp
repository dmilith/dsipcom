/*
 * author: Daniel (dmilith) Dettlaff
 * email: dmilith at drakor.eu
 * released under GPL2 & LGPL license
 * (c) 2oo8
 *
 */

#include <qt4/QtCore/Qt>
#include <qt4/QtCore/QFile>
#include <qt4/QtGui/QDialog>
#include <qt4/QtCore/QQueue>
#include <string>

using namespace std;

class TestDialog : QDialog {
   Q_OBJECT
public:
    TestDialog( string something );
};

TestDialog::TestDialog( string something ) {
    puts "Test Dialog constructor."
    
}