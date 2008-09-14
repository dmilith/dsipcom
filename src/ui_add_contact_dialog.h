/********************************************************************************
** Form generated from reading ui file 'add_contact_dialog.ui'
**
** Created: Sun Sep 14 18:44:43 2008
**      by: Qt User Interface Compiler version 4.4.0
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_ADD_CONTACT_DIALOG_H
#define UI_ADD_CONTACT_DIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_addUserDialog
{
public:
    QLineEdit *contact_sip_address;
    QLabel *label_2;
    QPushButton *add_button;
    QLabel *label;
    QLineEdit *contact_name;
    QPushButton *cancel_button;
    QLabel *label_13;

    void setupUi(QDialog *addUserDialog)
    {
    if (addUserDialog->objectName().isEmpty())
        addUserDialog->setObjectName(QString::fromUtf8("addUserDialog"));
    addUserDialog->resize(345, 215);
    contact_sip_address = new QLineEdit(addUserDialog);
    contact_sip_address->setObjectName(QString::fromUtf8("contact_sip_address"));
    contact_sip_address->setGeometry(QRect(40, 110, 291, 24));
    label_2 = new QLabel(addUserDialog);
    label_2->setObjectName(QString::fromUtf8("label_2"));
    label_2->setGeometry(QRect(10, 90, 281, 18));
    add_button = new QPushButton(addUserDialog);
    add_button->setObjectName(QString::fromUtf8("add_button"));
    add_button->setGeometry(QRect(10, 160, 176, 41));
    QIcon icon;
    icon.addPixmap(QPixmap(QString::fromUtf8(":/images/images/accept.png")), QIcon::Normal, QIcon::Off);
    add_button->setIcon(icon);
    label = new QLabel(addUserDialog);
    label->setObjectName(QString::fromUtf8("label"));
    label->setGeometry(QRect(10, 20, 126, 18));
    contact_name = new QLineEdit(addUserDialog);
    contact_name->setObjectName(QString::fromUtf8("contact_name"));
    contact_name->setGeometry(QRect(40, 40, 291, 24));
    cancel_button = new QPushButton(addUserDialog);
    cancel_button->setObjectName(QString::fromUtf8("cancel_button"));
    cancel_button->setGeometry(QRect(195, 160, 136, 41));
    QIcon icon1;
    icon1.addPixmap(QPixmap(QString::fromUtf8(":/images/images/cancel.png")), QIcon::Normal, QIcon::Off);
    cancel_button->setIcon(icon1);
    label_13 = new QLabel(addUserDialog);
    label_13->setObjectName(QString::fromUtf8("label_13"));
    label_13->setGeometry(QRect(15, 110, 26, 21));

    retranslateUi(addUserDialog);

    QMetaObject::connectSlotsByName(addUserDialog);
    } // setupUi

    void retranslateUi(QDialog *addUserDialog)
    {
    addUserDialog->setWindowTitle(QApplication::translate("addUserDialog", "Dialog", 0, QApplication::UnicodeUTF8));
    contact_sip_address->setText(QString());
    label_2->setText(QApplication::translate("addUserDialog", "Adres SIP u\305\274ytkownika ( username@realm )", 0, QApplication::UnicodeUTF8));
    add_button->setText(QApplication::translate("addUserDialog", "Dodaj kontakt", 0, QApplication::UnicodeUTF8));
    label->setText(QApplication::translate("addUserDialog", "Nazwa u\305\274ytkownika", 0, QApplication::UnicodeUTF8));
    cancel_button->setText(QApplication::translate("addUserDialog", "Anuluj", 0, QApplication::UnicodeUTF8));
    label_13->setText(QApplication::translate("addUserDialog", "sip:", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(addUserDialog);
    } // retranslateUi

};

namespace Ui {
    class addUserDialog: public Ui_addUserDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADD_CONTACT_DIALOG_H
