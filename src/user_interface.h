/********************************************************************************
** Form generated from reading ui file 'dsipcom.ui'
**
** Created: Fri Apr 4 20:36:19 2008
**      by: Qt User Interface Compiler version 4.3.4
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef USER_INTERFACE_H
#define USER_INTERFACE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCalendarWidget>
#include <QtGui/QGroupBox>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTextBrowser>
#include <QtGui/QToolBar>
#include <QtGui/QToolBox>
#include <QtGui/QToolButton>
#include <QtGui/QTreeView>
#include <QtGui/QWidget>

class Ui_MainWindow: public QMainWindow
{
public:
    QAction *actionPo_cz_z_serwerem_SIP;
    QAction *actionRoz_cz_z_serwerem_SIP;
    QAction *actionPreferencje;
    QAction *actionOpis;
    QAction *actionPomoc;
    QAction *actionO_Programie;
    QAction *actionDodaj_Kontakt;
    QAction *actionUsu_kontakt_z_listy;
    QAction *actionZako_cz_dzia_anie_programu;
    QWidget *centralwidget;
    QPushButton *call_button;
    QPushButton *hang_button;
    QLabel *label;
    QLineEdit *number_entry;
    QToolBox *toolBox;
    QWidget *page_contacts;
    QTreeView *contacts_tree;
    QWidget *page_dialer;
    QGroupBox *groupBox;
    QToolButton *dial_7;
    QToolButton *dial_8;
    QToolButton *dial_9;
    QToolButton *dial_4;
    QToolButton *dial_6;
    QToolButton *dial_5;
    QToolButton *dial_2;
    QToolButton *dial_1;
    QToolButton *dial_3;
    QToolButton *dial_hash;
    QToolButton *dial_0;
    QToolButton *dial_star;
    QWidget *page_preferences;
    QLineEdit *user_sip;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *user_password;
    QLineEdit *user_user_name;
    QLabel *label_5;
    QWidget *page_raports;
    QCalendarWidget *calendar;
    QLabel *label_4;
    QTextBrowser *raport_viewer;
    QMenuBar *menubar;
    QMenu *menuDsipcom;
    QMenu *menuPomoc;
    QMenu *menuKontakty;
    QStatusBar *statusbar;
    QToolBar *toolBar;
    QToolBar *toolBar_2;
    QToolBar *toolBar_3;
    QToolBar *toolBar_4;
    QToolBar *toolBar_5;
    QToolBar *toolBar_6;
    QToolBar *toolBar_7;
    QToolBar *toolBar_8;
    QToolBar *toolBar_9;
    QToolBar *toolBar_10;
    QToolBar *toolBar_11;
    QToolBar *toolBar_12;

    void setupUi(QMainWindow *MainWindow)
    {
    if (MainWindow->objectName().isEmpty())
        MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
    MainWindow->resize(381, 813);
    MainWindow->setAcceptDrops(true);
    MainWindow->setWindowIcon(QIcon(QString::fromUtf8(":/images/images/shield_add.png")));
    actionPo_cz_z_serwerem_SIP = new QAction(MainWindow);
    actionPo_cz_z_serwerem_SIP->setObjectName(QString::fromUtf8("actionPo_cz_z_serwerem_SIP"));
    actionPo_cz_z_serwerem_SIP->setIcon(QIcon(QString::fromUtf8(":/images/images/connect.png")));
    actionRoz_cz_z_serwerem_SIP = new QAction(MainWindow);
    actionRoz_cz_z_serwerem_SIP->setObjectName(QString::fromUtf8("actionRoz_cz_z_serwerem_SIP"));
    actionRoz_cz_z_serwerem_SIP->setIcon(QIcon(QString::fromUtf8(":/images/images/disconnect.png")));
    actionPreferencje = new QAction(MainWindow);
    actionPreferencje->setObjectName(QString::fromUtf8("actionPreferencje"));
    actionOpis = new QAction(MainWindow);
    actionOpis->setObjectName(QString::fromUtf8("actionOpis"));
    actionPomoc = new QAction(MainWindow);
    actionPomoc->setObjectName(QString::fromUtf8("actionPomoc"));
    actionPomoc->setIcon(QIcon(QString::fromUtf8(":/images/images/information.png")));
    actionO_Programie = new QAction(MainWindow);
    actionO_Programie->setObjectName(QString::fromUtf8("actionO_Programie"));
    actionO_Programie->setIcon(QIcon(QString::fromUtf8(":/images/images/award_star_gold_2.png")));
    actionDodaj_Kontakt = new QAction(MainWindow);
    actionDodaj_Kontakt->setObjectName(QString::fromUtf8("actionDodaj_Kontakt"));
    actionDodaj_Kontakt->setIcon(QIcon(QString::fromUtf8(":/images/images/add.png")));
    actionUsu_kontakt_z_listy = new QAction(MainWindow);
    actionUsu_kontakt_z_listy->setObjectName(QString::fromUtf8("actionUsu_kontakt_z_listy"));
    actionUsu_kontakt_z_listy->setIcon(QIcon(QString::fromUtf8(":/images/images/delete.png")));
    actionZako_cz_dzia_anie_programu = new QAction(MainWindow);
    actionZako_cz_dzia_anie_programu->setObjectName(QString::fromUtf8("actionZako_cz_dzia_anie_programu"));
    actionZako_cz_dzia_anie_programu->setIcon(QIcon(QString::fromUtf8(":/images/images/exclamation.png")));
    centralwidget = new QWidget(MainWindow);
    centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
    call_button = new QPushButton(centralwidget);
    call_button->setObjectName(QString::fromUtf8("call_button"));
    call_button->setGeometry(QRect(40, 710, 100, 31));
    call_button->setCursor(QCursor(Qt::PointingHandCursor));
    call_button->setIcon(QIcon(QString::fromUtf8(":/images/images/phone_add.png")));
    call_button->setAutoDefault(true);
    hang_button = new QPushButton(centralwidget);
    hang_button->setObjectName(QString::fromUtf8("hang_button"));
    hang_button->setGeometry(QRect(230, 710, 113, 31));
    hang_button->setCursor(QCursor(Qt::PointingHandCursor));
    hang_button->setIcon(QIcon(QString::fromUtf8(":/images/images/phone_delete.png")));
    label = new QLabel(centralwidget);
    label->setObjectName(QString::fromUtf8("label"));
    label->setGeometry(QRect(70, 660, 237, 18));
    number_entry = new QLineEdit(centralwidget);
    number_entry->setObjectName(QString::fromUtf8("number_entry"));
    number_entry->setGeometry(QRect(40, 680, 301, 30));
    number_entry->setDragEnabled(true);
    toolBox = new QToolBox(centralwidget);
    toolBox->setObjectName(QString::fromUtf8("toolBox"));
    toolBox->setGeometry(QRect(0, 0, 381, 651));
    toolBox->setCursor(QCursor(Qt::ClosedHandCursor));
    toolBox->setAcceptDrops(true);
    toolBox->setFrameShape(QFrame::StyledPanel);
    toolBox->setFrameShadow(QFrame::Sunken);
    page_contacts = new QWidget();
    page_contacts->setObjectName(QString::fromUtf8("page_contacts"));
    page_contacts->setGeometry(QRect(0, 0, 365, 515));
    contacts_tree = new QTreeView(page_contacts);
    contacts_tree->setObjectName(QString::fromUtf8("contacts_tree"));
    contacts_tree->setGeometry(QRect(10, 0, 351, 521));
    contacts_tree->viewport()->setProperty("cursor", QVariant(QCursor(Qt::PointingHandCursor)));
    toolBox->addItem(page_contacts, QIcon(QString::fromUtf8(":/images/images/user_add.png")), QApplication::translate("MainWindow", "Lista kontakt\303\263w", 0, QApplication::UnicodeUTF8));
    page_dialer = new QWidget();
    page_dialer->setObjectName(QString::fromUtf8("page_dialer"));
    page_dialer->setGeometry(QRect(0, 0, 365, 515));
    groupBox = new QGroupBox(page_dialer);
    groupBox->setObjectName(QString::fromUtf8("groupBox"));
    groupBox->setGeometry(QRect(20, 10, 331, 441));
    dial_7 = new QToolButton(groupBox);
    dial_7->setObjectName(QString::fromUtf8("dial_7"));
    dial_7->setGeometry(QRect(40, 60, 71, 71));
    QFont font;
    font.setPointSize(23);
    font.setBold(true);
    font.setWeight(75);
    font.setKerning(true);
    font.setStyleStrategy(QFont::PreferAntialias);
    dial_7->setFont(font);
    dial_7->setCursor(QCursor(Qt::PointingHandCursor));
    dial_8 = new QToolButton(groupBox);
    dial_8->setObjectName(QString::fromUtf8("dial_8"));
    dial_8->setGeometry(QRect(130, 60, 71, 71));
    dial_8->setFont(font);
    dial_8->setCursor(QCursor(Qt::PointingHandCursor));
    dial_9 = new QToolButton(groupBox);
    dial_9->setObjectName(QString::fromUtf8("dial_9"));
    dial_9->setGeometry(QRect(220, 60, 71, 71));
    dial_9->setFont(font);
    dial_9->setCursor(QCursor(Qt::PointingHandCursor));
    dial_4 = new QToolButton(groupBox);
    dial_4->setObjectName(QString::fromUtf8("dial_4"));
    dial_4->setGeometry(QRect(40, 150, 71, 71));
    dial_4->setFont(font);
    dial_4->setCursor(QCursor(Qt::PointingHandCursor));
    dial_6 = new QToolButton(groupBox);
    dial_6->setObjectName(QString::fromUtf8("dial_6"));
    dial_6->setGeometry(QRect(220, 150, 71, 71));
    dial_6->setFont(font);
    dial_6->setCursor(QCursor(Qt::PointingHandCursor));
    dial_5 = new QToolButton(groupBox);
    dial_5->setObjectName(QString::fromUtf8("dial_5"));
    dial_5->setGeometry(QRect(130, 150, 71, 71));
    dial_5->setFont(font);
    dial_5->setCursor(QCursor(Qt::PointingHandCursor));
    dial_2 = new QToolButton(groupBox);
    dial_2->setObjectName(QString::fromUtf8("dial_2"));
    dial_2->setGeometry(QRect(130, 240, 71, 71));
    dial_2->setFont(font);
    dial_2->setCursor(QCursor(Qt::PointingHandCursor));
    dial_1 = new QToolButton(groupBox);
    dial_1->setObjectName(QString::fromUtf8("dial_1"));
    dial_1->setGeometry(QRect(40, 240, 71, 71));
    dial_1->setFont(font);
    dial_1->setCursor(QCursor(Qt::PointingHandCursor));
    dial_3 = new QToolButton(groupBox);
    dial_3->setObjectName(QString::fromUtf8("dial_3"));
    dial_3->setGeometry(QRect(220, 240, 71, 71));
    dial_3->setFont(font);
    dial_3->setCursor(QCursor(Qt::PointingHandCursor));
    dial_hash = new QToolButton(groupBox);
    dial_hash->setObjectName(QString::fromUtf8("dial_hash"));
    dial_hash->setGeometry(QRect(40, 330, 71, 71));
    dial_hash->setFont(font);
    dial_hash->setCursor(QCursor(Qt::PointingHandCursor));
    dial_0 = new QToolButton(groupBox);
    dial_0->setObjectName(QString::fromUtf8("dial_0"));
    dial_0->setGeometry(QRect(130, 330, 71, 71));
    dial_0->setFont(font);
    dial_0->setCursor(QCursor(Qt::PointingHandCursor));
    dial_star = new QToolButton(groupBox);
    dial_star->setObjectName(QString::fromUtf8("dial_star"));
    dial_star->setGeometry(QRect(220, 330, 71, 71));
    dial_star->setFont(font);
    dial_star->setCursor(QCursor(Qt::PointingHandCursor));
    toolBox->addItem(page_dialer, QIcon(QString::fromUtf8(":/images/images/telephone_add.png")), QApplication::translate("MainWindow", "Wybieranie numer\303\263w", 0, QApplication::UnicodeUTF8));
    page_preferences = new QWidget();
    page_preferences->setObjectName(QString::fromUtf8("page_preferences"));
    user_sip = new QLineEdit(page_preferences);
    user_sip->setObjectName(QString::fromUtf8("user_sip"));
    user_sip->setGeometry(QRect(10, 50, 241, 30));
    label_2 = new QLabel(page_preferences);
    label_2->setObjectName(QString::fromUtf8("label_2"));
    label_2->setGeometry(QRect(10, 30, 182, 18));
    label_3 = new QLabel(page_preferences);
    label_3->setObjectName(QString::fromUtf8("label_3"));
    label_3->setGeometry(QRect(10, 100, 243, 18));
    user_password = new QLineEdit(page_preferences);
    user_password->setObjectName(QString::fromUtf8("user_password"));
    user_password->setGeometry(QRect(10, 120, 241, 30));
    user_user_name = new QLineEdit(page_preferences);
    user_user_name->setObjectName(QString::fromUtf8("user_user_name"));
    user_user_name->setGeometry(QRect(10, 190, 241, 30));
    label_5 = new QLabel(page_preferences);
    label_5->setObjectName(QString::fromUtf8("label_5"));
    label_5->setGeometry(QRect(10, 170, 201, 18));
    toolBox->addItem(page_preferences, QIcon(QString::fromUtf8(":/images/images/vcard.png")), QApplication::translate("MainWindow", "Preferencje u\305\274ytkownika", 0, QApplication::UnicodeUTF8));
    page_raports = new QWidget();
    page_raports->setObjectName(QString::fromUtf8("page_raports"));
    calendar = new QCalendarWidget(page_raports);
    calendar->setObjectName(QString::fromUtf8("calendar"));
    calendar->setGeometry(QRect(10, 30, 352, 211));
    label_4 = new QLabel(page_raports);
    label_4->setObjectName(QString::fromUtf8("label_4"));
    label_4->setGeometry(QRect(10, 10, 221, 18));
    raport_viewer = new QTextBrowser(page_raports);
    raport_viewer->setObjectName(QString::fromUtf8("raport_viewer"));
    raport_viewer->setGeometry(QRect(10, 250, 351, 261));
    raport_viewer->viewport()->setProperty("cursor", QVariant(QCursor(Qt::PointingHandCursor)));
    raport_viewer->setOpenExternalLinks(true);
    toolBox->addItem(page_raports, QIcon(QString::fromUtf8(":/images/images/report_user.png")), QApplication::translate("MainWindow", "Raporty z po\305\202\304\205cze\305\204", 0, QApplication::UnicodeUTF8));
    MainWindow->setCentralWidget(centralwidget);
    menubar = new QMenuBar(MainWindow);
    menubar->setObjectName(QString::fromUtf8("menubar"));
    menubar->setGeometry(QRect(0, 0, 381, 26));
    menuDsipcom = new QMenu(menubar);
    menuDsipcom->setObjectName(QString::fromUtf8("menuDsipcom"));
    menuPomoc = new QMenu(menubar);
    menuPomoc->setObjectName(QString::fromUtf8("menuPomoc"));
    menuKontakty = new QMenu(menubar);
    menuKontakty->setObjectName(QString::fromUtf8("menuKontakty"));
    MainWindow->setMenuBar(menubar);
    statusbar = new QStatusBar(MainWindow);
    statusbar->setObjectName(QString::fromUtf8("statusbar"));
    MainWindow->setStatusBar(statusbar);
    toolBar = new QToolBar(MainWindow);
    toolBar->setObjectName(QString::fromUtf8("toolBar"));
    MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);
    toolBar_2 = new QToolBar(MainWindow);
    toolBar_2->setObjectName(QString::fromUtf8("toolBar_2"));
    MainWindow->addToolBar(Qt::TopToolBarArea, toolBar_2);
    toolBar_3 = new QToolBar(MainWindow);
    toolBar_3->setObjectName(QString::fromUtf8("toolBar_3"));
    MainWindow->addToolBar(Qt::TopToolBarArea, toolBar_3);
    toolBar_4 = new QToolBar(MainWindow);
    toolBar_4->setObjectName(QString::fromUtf8("toolBar_4"));
    MainWindow->addToolBar(Qt::TopToolBarArea, toolBar_4);
    toolBar_5 = new QToolBar(MainWindow);
    toolBar_5->setObjectName(QString::fromUtf8("toolBar_5"));
    MainWindow->addToolBar(Qt::TopToolBarArea, toolBar_5);
    toolBar_6 = new QToolBar(MainWindow);
    toolBar_6->setObjectName(QString::fromUtf8("toolBar_6"));
    MainWindow->addToolBar(Qt::TopToolBarArea, toolBar_6);
    toolBar_7 = new QToolBar(MainWindow);
    toolBar_7->setObjectName(QString::fromUtf8("toolBar_7"));
    MainWindow->addToolBar(Qt::TopToolBarArea, toolBar_7);
    toolBar_8 = new QToolBar(MainWindow);
    toolBar_8->setObjectName(QString::fromUtf8("toolBar_8"));
    MainWindow->addToolBar(Qt::TopToolBarArea, toolBar_8);
    toolBar_9 = new QToolBar(MainWindow);
    toolBar_9->setObjectName(QString::fromUtf8("toolBar_9"));
    MainWindow->addToolBar(Qt::TopToolBarArea, toolBar_9);
    toolBar_10 = new QToolBar(MainWindow);
    toolBar_10->setObjectName(QString::fromUtf8("toolBar_10"));
    MainWindow->addToolBar(Qt::TopToolBarArea, toolBar_10);
    toolBar_11 = new QToolBar(MainWindow);
    toolBar_11->setObjectName(QString::fromUtf8("toolBar_11"));
    MainWindow->addToolBar(Qt::TopToolBarArea, toolBar_11);
    toolBar_12 = new QToolBar(MainWindow);
    toolBar_12->setObjectName(QString::fromUtf8("toolBar_12"));
    MainWindow->addToolBar(Qt::TopToolBarArea, toolBar_12);

    menubar->addAction(menuDsipcom->menuAction());
    menubar->addAction(menuKontakty->menuAction());
    menubar->addAction(menuPomoc->menuAction());
    menuDsipcom->addAction(actionPo_cz_z_serwerem_SIP);
    menuDsipcom->addAction(actionRoz_cz_z_serwerem_SIP);
    menuDsipcom->addSeparator();
    menuDsipcom->addAction(actionZako_cz_dzia_anie_programu);
    menuPomoc->addAction(actionPomoc);
    menuPomoc->addAction(actionO_Programie);
    menuKontakty->addAction(actionDodaj_Kontakt);
    menuKontakty->addAction(actionUsu_kontakt_z_listy);

    retranslateUi(MainWindow);
    QObject::connect(actionZako_cz_dzia_anie_programu, SIGNAL(activated()), MainWindow, SLOT(close()));

    toolBox->setCurrentIndex(1);


    QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
    MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
    MainWindow->setWhatsThis(QApplication::translate("MainWindow", "<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">To jest aplikacja dSipCom.</p></body></html>", 0, QApplication::UnicodeUTF8));
    actionPo_cz_z_serwerem_SIP->setText(QApplication::translate("MainWindow", "po\305\202\304\205cz z serwerem SIP", 0, QApplication::UnicodeUTF8));
    actionRoz_cz_z_serwerem_SIP->setText(QApplication::translate("MainWindow", "roz\305\202\304\205cz z serwerem SIP", 0, QApplication::UnicodeUTF8));
    actionPreferencje->setText(QApplication::translate("MainWindow", "Preferencje", 0, QApplication::UnicodeUTF8));
    actionOpis->setText(QApplication::translate("MainWindow", "Opis", 0, QApplication::UnicodeUTF8));
    actionPomoc->setText(QApplication::translate("MainWindow", "Pomoc", 0, QApplication::UnicodeUTF8));
    actionO_Programie->setText(QApplication::translate("MainWindow", "O Programie", 0, QApplication::UnicodeUTF8));
    actionDodaj_Kontakt->setText(QApplication::translate("MainWindow", "Dodaj Kontakt", 0, QApplication::UnicodeUTF8));
    actionUsu_kontakt_z_listy->setText(QApplication::translate("MainWindow", "Usu\305\204 kontakt z listy", 0, QApplication::UnicodeUTF8));
    actionZako_cz_dzia_anie_programu->setText(QApplication::translate("MainWindow", "Zako\305\204cz dzia\305\202anie programu", 0, QApplication::UnicodeUTF8));
    call_button->setToolTip(QApplication::translate("MainWindow", "<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Nawi\304\205zuje po\305\202\304\205czenie z kontaktem SIP</p></body></html>", 0, QApplication::UnicodeUTF8));
    call_button->setText(QApplication::translate("MainWindow", "Zadzwo\305\204", 0, QApplication::UnicodeUTF8));
    hang_button->setToolTip(QApplication::translate("MainWindow", "<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Ko\305\204czy wybrane po\305\202\304\205czenie.</p></body></html>", 0, QApplication::UnicodeUTF8));
    hang_button->setText(QApplication::translate("MainWindow", "Roz\305\202\304\205cz", 0, QApplication::UnicodeUTF8));
    label->setText(QApplication::translate("MainWindow", "Podaj adres lub numer SIP rozm\303\263wcy ", 0, QApplication::UnicodeUTF8));
    number_entry->setText(QApplication::translate("MainWindow", "sip:", 0, QApplication::UnicodeUTF8));
    toolBox->setAccessibleName(QApplication::translate("MainWindow", "tab_contacts", 0, QApplication::UnicodeUTF8));
    toolBox->setItemText(toolBox->indexOf(page_contacts), QApplication::translate("MainWindow", "Lista kontakt\303\263w", 0, QApplication::UnicodeUTF8));
    groupBox->setTitle(QString());
    dial_7->setText(QApplication::translate("MainWindow", "7", 0, QApplication::UnicodeUTF8));
    dial_8->setText(QApplication::translate("MainWindow", "8", 0, QApplication::UnicodeUTF8));
    dial_9->setText(QApplication::translate("MainWindow", "9", 0, QApplication::UnicodeUTF8));
    dial_4->setText(QApplication::translate("MainWindow", "4", 0, QApplication::UnicodeUTF8));
    dial_6->setText(QApplication::translate("MainWindow", "6", 0, QApplication::UnicodeUTF8));
    dial_5->setText(QApplication::translate("MainWindow", "5", 0, QApplication::UnicodeUTF8));
    dial_2->setText(QApplication::translate("MainWindow", "2", 0, QApplication::UnicodeUTF8));
    dial_1->setText(QApplication::translate("MainWindow", "1", 0, QApplication::UnicodeUTF8));
    dial_3->setText(QApplication::translate("MainWindow", "3", 0, QApplication::UnicodeUTF8));
    dial_hash->setText(QApplication::translate("MainWindow", "#", 0, QApplication::UnicodeUTF8));
    dial_0->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
    dial_star->setText(QApplication::translate("MainWindow", "*", 0, QApplication::UnicodeUTF8));
    toolBox->setItemText(toolBox->indexOf(page_dialer), QApplication::translate("MainWindow", "Wybieranie numer\303\263w", 0, QApplication::UnicodeUTF8));
    user_sip->setText(QApplication::translate("MainWindow", "sip:", 0, QApplication::UnicodeUTF8));
    label_2->setText(QApplication::translate("MainWindow", "Tu wprowad\305\272 sw\303\263j adres SIP", 0, QApplication::UnicodeUTF8));
    label_3->setText(QApplication::translate("MainWindow", "Tu wprowad\305\272 has\305\202o swojego konta SIP", 0, QApplication::UnicodeUTF8));
    label_5->setText(QApplication::translate("MainWindow", "Podaj swoj\304\205 nazw\304\231 u\305\274ytkownika", 0, QApplication::UnicodeUTF8));
    toolBox->setItemText(toolBox->indexOf(page_preferences), QApplication::translate("MainWindow", "Preferencje u\305\274ytkownika", 0, QApplication::UnicodeUTF8));
    label_4->setText(QApplication::translate("MainWindow", "Wybierz dzie\305\204 by zobaczy\304\207 raporty", 0, QApplication::UnicodeUTF8));
    toolBox->setItemText(toolBox->indexOf(page_raports), QApplication::translate("MainWindow", "Raporty z po\305\202\304\205cze\305\204", 0, QApplication::UnicodeUTF8));
    menuDsipcom->setTitle(QApplication::translate("MainWindow", "dSipCom", 0, QApplication::UnicodeUTF8));
    menuPomoc->setTitle(QApplication::translate("MainWindow", "Pomoc", 0, QApplication::UnicodeUTF8));
    menuKontakty->setTitle(QApplication::translate("MainWindow", "Kontakty", 0, QApplication::UnicodeUTF8));
    toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0, QApplication::UnicodeUTF8));
    toolBar_2->setWindowTitle(QApplication::translate("MainWindow", "toolBar_2", 0, QApplication::UnicodeUTF8));
    toolBar_3->setWindowTitle(QApplication::translate("MainWindow", "toolBar_3", 0, QApplication::UnicodeUTF8));
    toolBar_4->setWindowTitle(QApplication::translate("MainWindow", "toolBar_4", 0, QApplication::UnicodeUTF8));
    toolBar_5->setWindowTitle(QApplication::translate("MainWindow", "toolBar_5", 0, QApplication::UnicodeUTF8));
    toolBar_6->setWindowTitle(QApplication::translate("MainWindow", "toolBar_6", 0, QApplication::UnicodeUTF8));
    toolBar_7->setWindowTitle(QApplication::translate("MainWindow", "toolBar_7", 0, QApplication::UnicodeUTF8));
    toolBar_8->setWindowTitle(QApplication::translate("MainWindow", "toolBar_8", 0, QApplication::UnicodeUTF8));
    toolBar_9->setWindowTitle(QApplication::translate("MainWindow", "toolBar_9", 0, QApplication::UnicodeUTF8));
    toolBar_10->setWindowTitle(QApplication::translate("MainWindow", "toolBar_10", 0, QApplication::UnicodeUTF8));
    toolBar_11->setWindowTitle(QApplication::translate("MainWindow", "toolBar_11", 0, QApplication::UnicodeUTF8));
    toolBar_12->setWindowTitle(QApplication::translate("MainWindow", "toolBar_12", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

#endif // USER_INTERFACE_H
