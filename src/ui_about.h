/********************************************************************************
** Form generated from reading ui file 'about.ui'
**
** Created: Sun Sep 14 18:44:43 2008
**      by: Qt User Interface Compiler version 4.4.0
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_ABOUT_H
#define UI_ABOUT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AboutWindow
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *version_label;
    QLabel *label_4;
    QLabel *label_5;
    QPushButton *pushButton;

    void setupUi(QWidget *AboutWindow)
    {
    if (AboutWindow->objectName().isEmpty())
        AboutWindow->setObjectName(QString::fromUtf8("AboutWindow"));
    AboutWindow->resize(465, 242);
    AboutWindow->setCursor(QCursor(Qt::PointingHandCursor));
    label = new QLabel(AboutWindow);
    label->setObjectName(QString::fromUtf8("label"));
    label->setGeometry(QRect(50, 30, 141, 41));
    QFont font;
    font.setFamily(QString::fromUtf8("Lucida Sans"));
    font.setPointSize(23);
    font.setBold(true);
    font.setWeight(75);
    label->setFont(font);
    label_2 = new QLabel(AboutWindow);
    label_2->setObjectName(QString::fromUtf8("label_2"));
    label_2->setGeometry(QRect(10, 80, 221, 18));
    label_3 = new QLabel(AboutWindow);
    label_3->setObjectName(QString::fromUtf8("label_3"));
    label_3->setGeometry(QRect(65, 100, 41, 18));
    QFont font1;
    font1.setPointSize(9);
    label_3->setFont(font1);
    version_label = new QLabel(AboutWindow);
    version_label->setObjectName(QString::fromUtf8("version_label"));
    version_label->setGeometry(QRect(100, 100, 62, 18));
    version_label->setFont(font1);
    version_label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
    label_4 = new QLabel(AboutWindow);
    label_4->setObjectName(QString::fromUtf8("label_4"));
    label_4->setGeometry(QRect(25, 160, 191, 26));
    label_5 = new QLabel(AboutWindow);
    label_5->setObjectName(QString::fromUtf8("label_5"));
    label_5->setGeometry(QRect(10, 210, 226, 18));
    pushButton = new QPushButton(AboutWindow);
    pushButton->setObjectName(QString::fromUtf8("pushButton"));
    pushButton->setEnabled(true);
    pushButton->setGeometry(QRect(250, 30, 201, 201));
    QIcon icon;
    icon.addPixmap(QPixmap(QString::fromUtf8(":/images/images/headphone.gif")), QIcon::Normal, QIcon::Off);
    pushButton->setIcon(icon);
    pushButton->setIconSize(QSize(192, 192));
    pushButton->setFlat(false);

    retranslateUi(AboutWindow);

    QMetaObject::connectSlotsByName(AboutWindow);
    } // setupUi

    void retranslateUi(QWidget *AboutWindow)
    {
    AboutWindow->setWindowTitle(QApplication::translate("AboutWindow", "O programie dSipCom", 0, QApplication::UnicodeUTF8));
    label->setText(QApplication::translate("AboutWindow", "dSipCom", 0, QApplication::UnicodeUTF8));
    label_2->setText(QApplication::translate("AboutWindow", "Multiplatformowy komunikator VoIP", 0, QApplication::UnicodeUTF8));
    label_3->setText(QApplication::translate("AboutWindow", "wersja", 0, QApplication::UnicodeUTF8));
    version_label->setText(QApplication::translate("AboutWindow", "0.0.0", 0, QApplication::UnicodeUTF8));
    label_4->setText(QApplication::translate("AboutWindow", "Autor: Daniel (dmilith) Dettlaff", 0, QApplication::UnicodeUTF8));
    label_5->setText(QApplication::translate("AboutWindow", "Program na licencji: GPLv2 i LGPL", 0, QApplication::UnicodeUTF8));
    pushButton->setText(QString());
    Q_UNUSED(AboutWindow);
    } // retranslateUi

};

namespace Ui {
    class AboutWindow: public Ui_AboutWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUT_H
