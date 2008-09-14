/****************************************************************************
** Meta object code from reading C++ file 'dsipcom_ui.h'
**
** Created: Sun Sep 14 18:45:11 2008
**      by: The Qt Meta Object Compiler version 59 (Qt 4.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "dsipcom_ui.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dsipcom_ui.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Ui__AddContactWindow[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // signals: signature, parameters, type, tag, flags
      22,   21,   21,   21, 0x05,

 // slots: signature, parameters, type, tag, flags
      32,   21,   21,   21, 0x0a,
      46,   21,   21,   21, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Ui__AddContactWindow[] = {
    "Ui::AddContactWindow\0\0clicked()\0"
    "action_done()\0action_cancel()\0"
};

const QMetaObject Ui::AddContactWindow::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Ui__AddContactWindow,
      qt_meta_data_Ui__AddContactWindow, 0 }
};

const QMetaObject *Ui::AddContactWindow::metaObject() const
{
    return &staticMetaObject;
}

void *Ui::AddContactWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Ui__AddContactWindow))
	return static_cast<void*>(const_cast< AddContactWindow*>(this));
    if (!strcmp(_clname, "Ui::addUserDialog"))
	return static_cast< Ui::addUserDialog*>(const_cast< AddContactWindow*>(this));
    return QDialog::qt_metacast(_clname);
}

int Ui::AddContactWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: clicked(); break;
        case 1: action_done(); break;
        case 2: action_cancel(); break;
        }
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void Ui::AddContactWindow::clicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
static const uint qt_meta_data_Ui__AboutBox[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets

       0        // eod
};

static const char qt_meta_stringdata_Ui__AboutBox[] = {
    "Ui::AboutBox\0"
};

const QMetaObject Ui::AboutBox::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Ui__AboutBox,
      qt_meta_data_Ui__AboutBox, 0 }
};

const QMetaObject *Ui::AboutBox::metaObject() const
{
    return &staticMetaObject;
}

void *Ui::AboutBox::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Ui__AboutBox))
	return static_cast<void*>(const_cast< AboutBox*>(this));
    if (!strcmp(_clname, "Ui::AboutWindow"))
	return static_cast< Ui::AboutWindow*>(const_cast< AboutBox*>(this));
    return QDialog::qt_metacast(_clname);
}

int Ui::AboutBox::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_Ui__DSipCom[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
      28,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // signals: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
      23,   12,   12,   12, 0x0a,
      45,   12,   12,   12, 0x0a,
      64,   12,   12,   12, 0x0a,
      83,   12,   12,   12, 0x0a,
     104,   12,   12,   12, 0x0a,
     122,   12,   12,   12, 0x0a,
     142,   12,   12,   12, 0x0a,
     168,   12,   12,   12, 0x0a,
     197,   12,   12,   12, 0x0a,
     233,   12,   12,   12, 0x0a,
     274,   12,   12,   12, 0x0a,
     291,   12,   12,   12, 0x0a,
     308,   12,   12,   12, 0x0a,
     325,   12,   12,   12, 0x0a,
     342,   12,   12,   12, 0x0a,
     359,   12,   12,   12, 0x0a,
     376,   12,   12,   12, 0x0a,
     393,   12,   12,   12, 0x0a,
     410,   12,   12,   12, 0x0a,
     427,   12,   12,   12, 0x0a,
     444,   12,   12,   12, 0x0a,
     464,   12,   12,   12, 0x0a,
     484,   12,   12,   12, 0x0a,
     510,   12,   12,   12, 0x0a,
     536,   12,   12,   12, 0x0a,
     560,   12,   12,   12, 0x0a,
     584,   12,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Ui__DSipCom[] = {
    "Ui::DSipCom\0\0clicked()\0linphonec_main_loop()\0"
    "reset_status_bar()\0action_help_func()\0"
    "action_make_a_call()\0action_end_call()\0"
    "action_about_func()\0action_add_contact_func()\0"
    "action_remove_contact_func()\0"
    "action_connect_to_sip_server_func()\0"
    "action_disconnect_from_sip_server_func()\0"
    "action_enter_0()\0action_enter_1()\0"
    "action_enter_2()\0action_enter_3()\0"
    "action_enter_4()\0action_enter_5()\0"
    "action_enter_6()\0action_enter_7()\0"
    "action_enter_8()\0action_enter_9()\0"
    "action_enter_star()\0action_enter_hash()\0"
    "action_save_user_config()\0"
    "action_load_user_config()\0"
    "action_save_user_list()\0action_load_user_list()\0"
    "action_get_log_func()\0"
};

const QMetaObject Ui::DSipCom::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Ui__DSipCom,
      qt_meta_data_Ui__DSipCom, 0 }
};

const QMetaObject *Ui::DSipCom::metaObject() const
{
    return &staticMetaObject;
}

void *Ui::DSipCom::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Ui__DSipCom))
	return static_cast<void*>(const_cast< DSipCom*>(this));
    if (!strcmp(_clname, "Ui::MainWindow"))
	return static_cast< Ui::MainWindow*>(const_cast< DSipCom*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int Ui::DSipCom::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: clicked(); break;
        case 1: linphonec_main_loop(); break;
        case 2: reset_status_bar(); break;
        case 3: action_help_func(); break;
        case 4: action_make_a_call(); break;
        case 5: action_end_call(); break;
        case 6: action_about_func(); break;
        case 7: action_add_contact_func(); break;
        case 8: action_remove_contact_func(); break;
        case 9: action_connect_to_sip_server_func(); break;
        case 10: action_disconnect_from_sip_server_func(); break;
        case 11: action_enter_0(); break;
        case 12: action_enter_1(); break;
        case 13: action_enter_2(); break;
        case 14: action_enter_3(); break;
        case 15: action_enter_4(); break;
        case 16: action_enter_5(); break;
        case 17: action_enter_6(); break;
        case 18: action_enter_7(); break;
        case 19: action_enter_8(); break;
        case 20: action_enter_9(); break;
        case 21: action_enter_star(); break;
        case 22: action_enter_hash(); break;
        case 23: action_save_user_config(); break;
        case 24: action_load_user_config(); break;
        case 25: action_save_user_list(); break;
        case 26: action_load_user_list(); break;
        case 27: action_get_log_func(); break;
        }
        _id -= 28;
    }
    return _id;
}

// SIGNAL 0
void Ui::DSipCom::clicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
