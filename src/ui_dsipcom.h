/********************************************************************************
** Form generated from reading ui file 'dsipcom.ui'
**
** Created: Sun Sep 14 18:44:43 2008
**      by: Qt User Interface Compiler version 4.4.0
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_DSIPCOM_H
#define UI_DSIPCOM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCalendarWidget>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QGroupBox>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSlider>
#include <QtGui/QStatusBar>
#include <QtGui/QTextBrowser>
#include <QtGui/QToolBox>
#include <QtGui/QToolButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_connect_to_sip_server;
    QAction *action_disconnect_from_sip_server;
    QAction *actionPreferencje;
    QAction *actionOpis;
    QAction *action_help;
    QAction *action_about;
    QAction *action_add_contact_to_list;
    QAction *action_remove_contact_from_list;
    QAction *action_close_application;
    QWidget *centralwidget;
    QPushButton *call_button;
    QPushButton *hang_button;
    QToolBox *toolBox;
    QWidget *page_contacts;
    QListWidget *contacts_list;
    QPushButton *save_contact_list_button;
    QPushButton *load_contact_list_button;
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
    QLineEdit *number_entry;
    QLabel *label;
    QLabel *label_14;
    QWidget *page_preferences;
    QLabel *label_3;
    QLineEdit *user_password;
    QLineEdit *user_name;
    QLabel *label_5;
    QLineEdit *user_sip_server;
    QLabel *label_6;
    QCheckBox *auto_login;
    QPushButton *load_config_button;
    QPushButton *save_config_button;
    QWidget *page_advanced;
    QGroupBox *groupBox_2;
    QLabel *label_15;
    QLabel *label_16;
    QSlider *output_volume;
    QSlider *microphone_volume;
    QGroupBox *groupBox_3;
    QComboBox *in_soundcard;
    QComboBox *recording_source;
    QComboBox *ring_sound;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QComboBox *out_soundcard;
    QGroupBox *groupBox_4;
    QRadioButton *no_firewall;
    QLineEdit *default_port;
    QLabel *label_12;
    QRadioButton *use_stun_server;
    QRadioButton *manual_firewall_address;
    QLineEdit *stun_address;
    QLineEdit *firewall_address;
    QWidget *page_raports;
    QCalendarWidget *calendar;
    QLabel *label_4;
    QTextBrowser *raport_viewer;
    QLabel *label_7;
    QGroupBox *status_box;
    QLabel *status_bar;
    QComboBox *comboBox;
    QMenuBar *menubar;
    QMenu *menuDsipcom;
    QMenu *menuPomoc;
    QMenu *menuKontakty;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
    if (MainWindow->objectName().isEmpty())
        MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
    MainWindow->resize(382, 845);
    MainWindow->setMinimumSize(QSize(382, 845));
    MainWindow->setMaximumSize(QSize(382, 845));
    MainWindow->setAcceptDrops(true);
    QIcon icon;
    icon.addPixmap(QPixmap(QString::fromUtf8(":/images/images/phone_sound.png")), QIcon::Normal, QIcon::Off);
    MainWindow->setWindowIcon(icon);
    MainWindow->setDockOptions(QMainWindow::AllowNestedDocks|QMainWindow::AllowTabbedDocks|QMainWindow::AnimatedDocks);
    action_connect_to_sip_server = new QAction(MainWindow);
    action_connect_to_sip_server->setObjectName(QString::fromUtf8("action_connect_to_sip_server"));
    QIcon icon1;
    icon1.addPixmap(QPixmap(QString::fromUtf8(":/images/images/connect.png")), QIcon::Normal, QIcon::Off);
    action_connect_to_sip_server->setIcon(icon1);
    action_disconnect_from_sip_server = new QAction(MainWindow);
    action_disconnect_from_sip_server->setObjectName(QString::fromUtf8("action_disconnect_from_sip_server"));
    QIcon icon2;
    icon2.addPixmap(QPixmap(QString::fromUtf8(":/images/images/disconnect.png")), QIcon::Normal, QIcon::Off);
    action_disconnect_from_sip_server->setIcon(icon2);
    actionPreferencje = new QAction(MainWindow);
    actionPreferencje->setObjectName(QString::fromUtf8("actionPreferencje"));
    actionOpis = new QAction(MainWindow);
    actionOpis->setObjectName(QString::fromUtf8("actionOpis"));
    action_help = new QAction(MainWindow);
    action_help->setObjectName(QString::fromUtf8("action_help"));
    QIcon icon3;
    icon3.addPixmap(QPixmap(QString::fromUtf8(":/images/images/information.png")), QIcon::Normal, QIcon::Off);
    action_help->setIcon(icon3);
    action_about = new QAction(MainWindow);
    action_about->setObjectName(QString::fromUtf8("action_about"));
    QIcon icon4;
    icon4.addPixmap(QPixmap(QString::fromUtf8(":/images/images/award_star_gold_2.png")), QIcon::Normal, QIcon::Off);
    action_about->setIcon(icon4);
    action_add_contact_to_list = new QAction(MainWindow);
    action_add_contact_to_list->setObjectName(QString::fromUtf8("action_add_contact_to_list"));
    QIcon icon5;
    icon5.addPixmap(QPixmap(QString::fromUtf8(":/images/images/add.png")), QIcon::Normal, QIcon::Off);
    action_add_contact_to_list->setIcon(icon5);
    action_remove_contact_from_list = new QAction(MainWindow);
    action_remove_contact_from_list->setObjectName(QString::fromUtf8("action_remove_contact_from_list"));
    QIcon icon6;
    icon6.addPixmap(QPixmap(QString::fromUtf8(":/images/images/delete.png")), QIcon::Normal, QIcon::Off);
    action_remove_contact_from_list->setIcon(icon6);
    action_close_application = new QAction(MainWindow);
    action_close_application->setObjectName(QString::fromUtf8("action_close_application"));
    QIcon icon7;
    icon7.addPixmap(QPixmap(QString::fromUtf8(":/images/images/exclamation.png")), QIcon::Normal, QIcon::Off);
    action_close_application->setIcon(icon7);
    centralwidget = new QWidget(MainWindow);
    centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
    centralwidget->setGeometry(QRect(0, 23, 382, 800));
    call_button = new QPushButton(centralwidget);
    call_button->setObjectName(QString::fromUtf8("call_button"));
    call_button->setGeometry(QRect(10, 670, 191, 51));
    call_button->setCursor(QCursor(Qt::PointingHandCursor));
    QIcon icon8;
    icon8.addPixmap(QPixmap(QString::fromUtf8(":/images/images/phone_add.png")), QIcon::Normal, QIcon::Off);
    call_button->setIcon(icon8);
    call_button->setAutoDefault(true);
    hang_button = new QPushButton(centralwidget);
    hang_button->setObjectName(QString::fromUtf8("hang_button"));
    hang_button->setEnabled(false);
    hang_button->setGeometry(QRect(205, 670, 161, 51));
    hang_button->setCursor(QCursor(Qt::PointingHandCursor));
    QIcon icon9;
    icon9.addPixmap(QPixmap(QString::fromUtf8(":/images/images/phone_delete.png")), QIcon::Normal, QIcon::Off);
    hang_button->setIcon(icon9);
    toolBox = new QToolBox(centralwidget);
    toolBox->setObjectName(QString::fromUtf8("toolBox"));
    toolBox->setGeometry(QRect(4, 0, 376, 666));
    toolBox->setCursor(QCursor(Qt::PointingHandCursor));
    toolBox->setAcceptDrops(true);
    toolBox->setAutoFillBackground(false);
    toolBox->setFrameShape(QFrame::StyledPanel);
    toolBox->setFrameShadow(QFrame::Sunken);
    page_contacts = new QWidget();
    page_contacts->setObjectName(QString::fromUtf8("page_contacts"));
    page_contacts->setGeometry(QRect(0, 0, 376, 541));
    contacts_list = new QListWidget(page_contacts);
    contacts_list->setObjectName(QString::fromUtf8("contacts_list"));
    contacts_list->setGeometry(QRect(5, 0, 361, 466));
    QFont font;
    font.setPointSize(12);
    font.setBold(true);
    font.setWeight(75);
    font.setStyleStrategy(QFont::PreferDefault);
    contacts_list->setFont(font);
    contacts_list->viewport()->setProperty("cursor", QVariant(QCursor(Qt::PointingHandCursor)));
    contacts_list->setMouseTracking(true);
    contacts_list->setLineWidth(1);
    contacts_list->setMovement(QListView::Static);
    contacts_list->setProperty("isWrapping", QVariant(false));
    contacts_list->setSpacing(1);
    contacts_list->setWordWrap(true);
    contacts_list->setSelectionRectVisible(true);
    save_contact_list_button = new QPushButton(page_contacts);
    save_contact_list_button->setObjectName(QString::fromUtf8("save_contact_list_button"));
    save_contact_list_button->setGeometry(QRect(10, 480, 171, 28));
    QIcon icon10;
    icon10.addPixmap(QPixmap(QString::fromUtf8(":/images/images/folder_add.png")), QIcon::Normal, QIcon::Off);
    save_contact_list_button->setIcon(icon10);
    load_contact_list_button = new QPushButton(page_contacts);
    load_contact_list_button->setObjectName(QString::fromUtf8("load_contact_list_button"));
    load_contact_list_button->setGeometry(QRect(185, 480, 171, 28));
    QIcon icon11;
    icon11.addPixmap(QPixmap(QString::fromUtf8(":/images/images/folder_bell.png")), QIcon::Normal, QIcon::Off);
    load_contact_list_button->setIcon(icon11);
    QIcon icon12;
    icon12.addPixmap(QPixmap(QString::fromUtf8(":/images/images/user_add.png")), QIcon::Normal, QIcon::Off);
    toolBox->addItem(page_contacts, icon12, QApplication::translate("MainWindow", "Lista kontakt\303\263w", 0, QApplication::UnicodeUTF8));
    page_dialer = new QWidget();
    page_dialer->setObjectName(QString::fromUtf8("page_dialer"));
    page_dialer->setGeometry(QRect(0, 0, 376, 541));
    groupBox = new QGroupBox(page_dialer);
    groupBox->setObjectName(QString::fromUtf8("groupBox"));
    groupBox->setGeometry(QRect(0, -5, 371, 526));
    dial_7 = new QToolButton(groupBox);
    dial_7->setObjectName(QString::fromUtf8("dial_7"));
    dial_7->setGeometry(QRect(55, 35, 71, 71));
    QFont font1;
    font1.setPointSize(20);
    font1.setBold(true);
    font1.setWeight(75);
    font1.setKerning(true);
    font1.setStyleStrategy(QFont::PreferAntialias);
    dial_7->setFont(font1);
    dial_7->setCursor(QCursor(Qt::PointingHandCursor));
    dial_8 = new QToolButton(groupBox);
    dial_8->setObjectName(QString::fromUtf8("dial_8"));
    dial_8->setGeometry(QRect(145, 35, 71, 71));
    dial_8->setFont(font1);
    dial_8->setCursor(QCursor(Qt::PointingHandCursor));
    dial_9 = new QToolButton(groupBox);
    dial_9->setObjectName(QString::fromUtf8("dial_9"));
    dial_9->setGeometry(QRect(235, 35, 71, 71));
    dial_9->setFont(font1);
    dial_9->setCursor(QCursor(Qt::PointingHandCursor));
    dial_4 = new QToolButton(groupBox);
    dial_4->setObjectName(QString::fromUtf8("dial_4"));
    dial_4->setGeometry(QRect(55, 125, 71, 71));
    dial_4->setFont(font1);
    dial_4->setCursor(QCursor(Qt::PointingHandCursor));
    dial_6 = new QToolButton(groupBox);
    dial_6->setObjectName(QString::fromUtf8("dial_6"));
    dial_6->setGeometry(QRect(235, 125, 71, 71));
    dial_6->setFont(font1);
    dial_6->setCursor(QCursor(Qt::PointingHandCursor));
    dial_5 = new QToolButton(groupBox);
    dial_5->setObjectName(QString::fromUtf8("dial_5"));
    dial_5->setGeometry(QRect(145, 125, 71, 71));
    dial_5->setFont(font1);
    dial_5->setCursor(QCursor(Qt::PointingHandCursor));
    dial_2 = new QToolButton(groupBox);
    dial_2->setObjectName(QString::fromUtf8("dial_2"));
    dial_2->setGeometry(QRect(145, 215, 71, 71));
    dial_2->setFont(font1);
    dial_2->setCursor(QCursor(Qt::PointingHandCursor));
    dial_1 = new QToolButton(groupBox);
    dial_1->setObjectName(QString::fromUtf8("dial_1"));
    dial_1->setGeometry(QRect(55, 215, 71, 71));
    dial_1->setFont(font1);
    dial_1->setCursor(QCursor(Qt::PointingHandCursor));
    dial_3 = new QToolButton(groupBox);
    dial_3->setObjectName(QString::fromUtf8("dial_3"));
    dial_3->setGeometry(QRect(235, 215, 71, 71));
    dial_3->setFont(font1);
    dial_3->setCursor(QCursor(Qt::PointingHandCursor));
    dial_hash = new QToolButton(groupBox);
    dial_hash->setObjectName(QString::fromUtf8("dial_hash"));
    dial_hash->setGeometry(QRect(55, 305, 71, 71));
    dial_hash->setFont(font1);
    dial_hash->setCursor(QCursor(Qt::PointingHandCursor));
    dial_0 = new QToolButton(groupBox);
    dial_0->setObjectName(QString::fromUtf8("dial_0"));
    dial_0->setGeometry(QRect(145, 305, 71, 71));
    dial_0->setFont(font1);
    dial_0->setCursor(QCursor(Qt::PointingHandCursor));
    dial_star = new QToolButton(groupBox);
    dial_star->setObjectName(QString::fromUtf8("dial_star"));
    dial_star->setGeometry(QRect(235, 305, 71, 71));
    dial_star->setFont(font1);
    dial_star->setCursor(QCursor(Qt::PointingHandCursor));
    number_entry = new QLineEdit(groupBox);
    number_entry->setObjectName(QString::fromUtf8("number_entry"));
    number_entry->setGeometry(QRect(85, 420, 216, 30));
    number_entry->setDragEnabled(true);
    label = new QLabel(groupBox);
    label->setObjectName(QString::fromUtf8("label"));
    label->setGeometry(QRect(65, 400, 237, 18));
    label_14 = new QLabel(groupBox);
    label_14->setObjectName(QString::fromUtf8("label_14"));
    label_14->setGeometry(QRect(60, 425, 26, 21));
    QIcon icon13;
    icon13.addPixmap(QPixmap(QString::fromUtf8(":/images/images/telephone_add.png")), QIcon::Normal, QIcon::Off);
    toolBox->addItem(page_dialer, icon13, QApplication::translate("MainWindow", "Wybieranie numer\303\263w", 0, QApplication::UnicodeUTF8));
    page_preferences = new QWidget();
    page_preferences->setObjectName(QString::fromUtf8("page_preferences"));
    page_preferences->setGeometry(QRect(0, 0, 376, 541));
    label_3 = new QLabel(page_preferences);
    label_3->setObjectName(QString::fromUtf8("label_3"));
    label_3->setGeometry(QRect(40, 225, 243, 18));
    user_password = new QLineEdit(page_preferences);
    user_password->setObjectName(QString::fromUtf8("user_password"));
    user_password->setGeometry(QRect(65, 245, 266, 30));
    user_password->setEchoMode(QLineEdit::Password);
    user_name = new QLineEdit(page_preferences);
    user_name->setObjectName(QString::fromUtf8("user_name"));
    user_name->setGeometry(QRect(65, 160, 266, 30));
    label_5 = new QLabel(page_preferences);
    label_5->setObjectName(QString::fromUtf8("label_5"));
    label_5->setGeometry(QRect(40, 140, 201, 18));
    user_sip_server = new QLineEdit(page_preferences);
    user_sip_server->setObjectName(QString::fromUtf8("user_sip_server"));
    user_sip_server->setGeometry(QRect(65, 70, 266, 30));
    label_6 = new QLabel(page_preferences);
    label_6->setObjectName(QString::fromUtf8("label_6"));
    label_6->setGeometry(QRect(40, 50, 240, 18));
    auto_login = new QCheckBox(page_preferences);
    auto_login->setObjectName(QString::fromUtf8("auto_login"));
    auto_login->setGeometry(QRect(40, 305, 256, 21));
    auto_login->setAutoFillBackground(false);
    auto_login->setChecked(true);
    load_config_button = new QPushButton(page_preferences);
    load_config_button->setObjectName(QString::fromUtf8("load_config_button"));
    load_config_button->setGeometry(QRect(195, 410, 166, 36));
    QIcon icon14;
    icon14.addPixmap(QPixmap(QString::fromUtf8(":/images/images/cd_burn.png")), QIcon::Normal, QIcon::Off);
    load_config_button->setIcon(icon14);
    save_config_button = new QPushButton(page_preferences);
    save_config_button->setObjectName(QString::fromUtf8("save_config_button"));
    save_config_button->setGeometry(QRect(10, 410, 171, 36));
    QIcon icon15;
    icon15.addPixmap(QPixmap(QString::fromUtf8(":/images/images/bug_add.png")), QIcon::Normal, QIcon::Off);
    save_config_button->setIcon(icon15);
    QIcon icon16;
    icon16.addPixmap(QPixmap(QString::fromUtf8(":/images/images/vcard.png")), QIcon::Normal, QIcon::Off);
    toolBox->addItem(page_preferences, icon16, QApplication::translate("MainWindow", "Preferencje u\305\274ytkownika", 0, QApplication::UnicodeUTF8));
    page_advanced = new QWidget();
    page_advanced->setObjectName(QString::fromUtf8("page_advanced"));
    page_advanced->setGeometry(QRect(0, 0, 376, 541));
    groupBox_2 = new QGroupBox(page_advanced);
    groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
    groupBox_2->setGeometry(QRect(10, 155, 351, 156));
    label_15 = new QLabel(groupBox_2);
    label_15->setObjectName(QString::fromUtf8("label_15"));
    label_15->setGeometry(QRect(35, 40, 106, 18));
    label_16 = new QLabel(groupBox_2);
    label_16->setObjectName(QString::fromUtf8("label_16"));
    label_16->setGeometry(QRect(35, 85, 116, 18));
    output_volume = new QSlider(groupBox_2);
    output_volume->setObjectName(QString::fromUtf8("output_volume"));
    output_volume->setGeometry(QRect(179, 40, 156, 25));
    output_volume->setCursor(QCursor(Qt::ArrowCursor));
    output_volume->setMaximum(10);
    output_volume->setSliderPosition(5);
    output_volume->setOrientation(Qt::Horizontal);
    microphone_volume = new QSlider(groupBox_2);
    microphone_volume->setObjectName(QString::fromUtf8("microphone_volume"));
    microphone_volume->setGeometry(QRect(180, 85, 156, 25));
    microphone_volume->setCursor(QCursor(Qt::ArrowCursor));
    microphone_volume->setMaximum(10);
    microphone_volume->setValue(5);
    microphone_volume->setOrientation(Qt::Horizontal);
    groupBox_3 = new QGroupBox(page_advanced);
    groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
    groupBox_3->setGeometry(QRect(10, 5, 351, 141));
    in_soundcard = new QComboBox(groupBox_3);
    QIcon icon17;
    icon17.addPixmap(QPixmap(QString::fromUtf8(":/images/images/sound.png")), QIcon::Normal, QIcon::Off);
    in_soundcard->addItem(icon17, QString());
    in_soundcard->addItem(icon17, QString());
    in_soundcard->setObjectName(QString::fromUtf8("in_soundcard"));
    in_soundcard->setGeometry(QRect(135, 55, 206, 24));
    recording_source = new QComboBox(groupBox_3);
    recording_source->addItem(icon1, QString());
    recording_source->addItem(icon1, QString());
    recording_source->setObjectName(QString::fromUtf8("recording_source"));
    recording_source->setGeometry(QRect(135, 85, 206, 24));
    ring_sound = new QComboBox(groupBox_3);
    ring_sound->addItem(icon7, QString());
    ring_sound->setObjectName(QString::fromUtf8("ring_sound"));
    ring_sound->setGeometry(QRect(135, 115, 206, 24));
    label_8 = new QLabel(groupBox_3);
    label_8->setObjectName(QString::fromUtf8("label_8"));
    label_8->setGeometry(QRect(25, 30, 62, 18));
    label_9 = new QLabel(groupBox_3);
    label_9->setObjectName(QString::fromUtf8("label_9"));
    label_9->setGeometry(QRect(25, 60, 62, 18));
    label_10 = new QLabel(groupBox_3);
    label_10->setObjectName(QString::fromUtf8("label_10"));
    label_10->setGeometry(QRect(25, 90, 101, 18));
    label_11 = new QLabel(groupBox_3);
    label_11->setObjectName(QString::fromUtf8("label_11"));
    label_11->setGeometry(QRect(25, 120, 111, 18));
    out_soundcard = new QComboBox(groupBox_3);
    out_soundcard->addItem(icon17, QString());
    out_soundcard->addItem(icon17, QString());
    out_soundcard->setObjectName(QString::fromUtf8("out_soundcard"));
    out_soundcard->setGeometry(QRect(135, 25, 206, 24));
    groupBox_4 = new QGroupBox(page_advanced);
    groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
    groupBox_4->setGeometry(QRect(10, 315, 351, 211));
    no_firewall = new QRadioButton(groupBox_4);
    no_firewall->setObjectName(QString::fromUtf8("no_firewall"));
    no_firewall->setGeometry(QRect(30, 55, 231, 23));
    no_firewall->setChecked(true);
    default_port = new QLineEdit(groupBox_4);
    default_port->setObjectName(QString::fromUtf8("default_port"));
    default_port->setGeometry(QRect(160, 30, 51, 24));
    default_port->setMaxLength(5);
    label_12 = new QLabel(groupBox_4);
    label_12->setObjectName(QString::fromUtf8("label_12"));
    label_12->setGeometry(QRect(35, 30, 121, 18));
    use_stun_server = new QRadioButton(groupBox_4);
    use_stun_server->setObjectName(QString::fromUtf8("use_stun_server"));
    use_stun_server->setGeometry(QRect(30, 85, 261, 23));
    manual_firewall_address = new QRadioButton(groupBox_4);
    manual_firewall_address->setObjectName(QString::fromUtf8("manual_firewall_address"));
    manual_firewall_address->setGeometry(QRect(30, 145, 246, 23));
    stun_address = new QLineEdit(groupBox_4);
    stun_address->setObjectName(QString::fromUtf8("stun_address"));
    stun_address->setGeometry(QRect(160, 110, 176, 24));
    firewall_address = new QLineEdit(groupBox_4);
    firewall_address->setObjectName(QString::fromUtf8("firewall_address"));
    firewall_address->setGeometry(QRect(160, 170, 176, 24));
    QIcon icon18;
    icon18.addPixmap(QPixmap(QString::fromUtf8(":/images/images/picture_key.png")), QIcon::Normal, QIcon::Off);
    toolBox->addItem(page_advanced, icon18, QApplication::translate("MainWindow", "Ustawienia zaawansowane", 0, QApplication::UnicodeUTF8));
    page_raports = new QWidget();
    page_raports->setObjectName(QString::fromUtf8("page_raports"));
    page_raports->setGeometry(QRect(0, 0, 376, 541));
    calendar = new QCalendarWidget(page_raports);
    calendar->setObjectName(QString::fromUtf8("calendar"));
    calendar->setGeometry(QRect(6, 30, 361, 211));
    calendar->setMouseTracking(true);
    calendar->setGridVisible(false);
    label_4 = new QLabel(page_raports);
    label_4->setObjectName(QString::fromUtf8("label_4"));
    label_4->setGeometry(QRect(5, 10, 221, 18));
    raport_viewer = new QTextBrowser(page_raports);
    raport_viewer->setObjectName(QString::fromUtf8("raport_viewer"));
    raport_viewer->setEnabled(true);
    raport_viewer->setGeometry(QRect(5, 280, 361, 226));
    raport_viewer->viewport()->setProperty("cursor", QVariant(QCursor(Qt::PointingHandCursor)));
    raport_viewer->setOpenExternalLinks(true);
    label_7 = new QLabel(page_raports);
    label_7->setObjectName(QString::fromUtf8("label_7"));
    label_7->setGeometry(QRect(5, 260, 211, 18));
    QIcon icon19;
    icon19.addPixmap(QPixmap(QString::fromUtf8(":/images/images/report.png")), QIcon::Normal, QIcon::Off);
    toolBox->addItem(page_raports, icon19, QApplication::translate("MainWindow", "Raporty z po\305\202\304\205cze\305\204", 0, QApplication::UnicodeUTF8));
    status_box = new QGroupBox(centralwidget);
    status_box->setObjectName(QString::fromUtf8("status_box"));
    status_box->setGeometry(QRect(10, 725, 361, 66));
    status_bar = new QLabel(status_box);
    status_bar->setObjectName(QString::fromUtf8("status_bar"));
    status_bar->setEnabled(true);
    status_bar->setGeometry(QRect(135, 45, 221, 21));
    QFont font2;
    font2.setPointSize(8);
    font2.setBold(false);
    font2.setWeight(50);
    status_bar->setFont(font2);
    status_bar->setLayoutDirection(Qt::RightToLeft);
    comboBox = new QComboBox(status_box);
    QIcon icon20;
    icon20.addPixmap(QPixmap(QString::fromUtf8(":/images/images/user_green.png")), QIcon::Normal, QIcon::Off);
    comboBox->addItem(icon20, QString());
    QIcon icon21;
    icon21.addPixmap(QPixmap(QString::fromUtf8(":/images/images/user_edit.png")), QIcon::Normal, QIcon::Off);
    comboBox->addItem(icon21, QString());
    QIcon icon22;
    icon22.addPixmap(QPixmap(QString::fromUtf8(":/images/images/user_delete.png")), QIcon::Normal, QIcon::Off);
    comboBox->addItem(icon22, QString());
    QIcon icon23;
    icon23.addPixmap(QPixmap(QString::fromUtf8(":/images/images/user_red.png")), QIcon::Normal, QIcon::Off);
    comboBox->addItem(icon23, QString());
    comboBox->setObjectName(QString::fromUtf8("comboBox"));
    comboBox->setGeometry(QRect(5, 15, 156, 31));
    QFont font3;
    font3.setPointSize(7);
    comboBox->setFont(font3);
    MainWindow->setCentralWidget(centralwidget);
    menubar = new QMenuBar(MainWindow);
    menubar->setObjectName(QString::fromUtf8("menubar"));
    menubar->setGeometry(QRect(0, 0, 382, 23));
    menuDsipcom = new QMenu(menubar);
    menuDsipcom->setObjectName(QString::fromUtf8("menuDsipcom"));
    menuPomoc = new QMenu(menubar);
    menuPomoc->setObjectName(QString::fromUtf8("menuPomoc"));
    menuKontakty = new QMenu(menubar);
    menuKontakty->setObjectName(QString::fromUtf8("menuKontakty"));
    MainWindow->setMenuBar(menubar);
    statusbar = new QStatusBar(MainWindow);
    statusbar->setObjectName(QString::fromUtf8("statusbar"));
    statusbar->setGeometry(QRect(0, 823, 382, 22));
    MainWindow->setStatusBar(statusbar);
    QWidget::setTabOrder(user_sip_server, user_name);
    QWidget::setTabOrder(user_name, user_password);
    QWidget::setTabOrder(user_password, auto_login);
    QWidget::setTabOrder(auto_login, save_config_button);
    QWidget::setTabOrder(save_config_button, load_config_button);
    QWidget::setTabOrder(load_config_button, recording_source);
    QWidget::setTabOrder(recording_source, ring_sound);
    QWidget::setTabOrder(ring_sound, default_port);
    QWidget::setTabOrder(default_port, no_firewall);
    QWidget::setTabOrder(no_firewall, use_stun_server);
    QWidget::setTabOrder(use_stun_server, stun_address);
    QWidget::setTabOrder(stun_address, manual_firewall_address);
    QWidget::setTabOrder(manual_firewall_address, firewall_address);
    QWidget::setTabOrder(firewall_address, calendar);
    QWidget::setTabOrder(calendar, raport_viewer);
    QWidget::setTabOrder(raport_viewer, call_button);
    QWidget::setTabOrder(call_button, hang_button);
    QWidget::setTabOrder(hang_button, comboBox);
    QWidget::setTabOrder(comboBox, contacts_list);
    QWidget::setTabOrder(contacts_list, save_contact_list_button);
    QWidget::setTabOrder(save_contact_list_button, load_contact_list_button);
    QWidget::setTabOrder(load_contact_list_button, dial_7);
    QWidget::setTabOrder(dial_7, dial_8);
    QWidget::setTabOrder(dial_8, dial_9);
    QWidget::setTabOrder(dial_9, dial_4);
    QWidget::setTabOrder(dial_4, dial_5);
    QWidget::setTabOrder(dial_5, dial_6);
    QWidget::setTabOrder(dial_6, dial_1);
    QWidget::setTabOrder(dial_1, dial_2);
    QWidget::setTabOrder(dial_2, dial_3);
    QWidget::setTabOrder(dial_3, dial_hash);
    QWidget::setTabOrder(dial_hash, dial_0);
    QWidget::setTabOrder(dial_0, dial_star);
    QWidget::setTabOrder(dial_star, number_entry);
    QWidget::setTabOrder(number_entry, in_soundcard);
    QWidget::setTabOrder(in_soundcard, out_soundcard);
    QWidget::setTabOrder(out_soundcard, output_volume);
    QWidget::setTabOrder(output_volume, microphone_volume);

    menubar->addAction(menuDsipcom->menuAction());
    menubar->addAction(menuKontakty->menuAction());
    menubar->addAction(menuPomoc->menuAction());
    menuDsipcom->addAction(action_connect_to_sip_server);
    menuDsipcom->addAction(action_disconnect_from_sip_server);
    menuDsipcom->addSeparator();
    menuDsipcom->addAction(action_close_application);
    menuPomoc->addAction(action_help);
    menuPomoc->addAction(action_about);
    menuKontakty->addAction(action_add_contact_to_list);
    menuKontakty->addAction(action_remove_contact_from_list);

    retranslateUi(MainWindow);
    QObject::connect(action_close_application, SIGNAL(activated()), MainWindow, SLOT(close()));

    toolBox->setCurrentIndex(0);
    comboBox->setCurrentIndex(0);


    QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
    MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));

#ifndef QT_NO_WHATSTHIS
    MainWindow->setWhatsThis(QApplication::translate("MainWindow", "<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">To jest aplikacja dSipCom.</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS

    action_connect_to_sip_server->setText(QApplication::translate("MainWindow", "Po\305\202\304\205cz z serwerem SIP proxy", 0, QApplication::UnicodeUTF8));
    action_disconnect_from_sip_server->setText(QApplication::translate("MainWindow", "Roz\305\202\304\205cz z serwerem SIP proxy", 0, QApplication::UnicodeUTF8));
    actionPreferencje->setText(QApplication::translate("MainWindow", "Preferencje", 0, QApplication::UnicodeUTF8));
    actionOpis->setText(QApplication::translate("MainWindow", "Opis", 0, QApplication::UnicodeUTF8));
    action_help->setText(QApplication::translate("MainWindow", "Pomoc", 0, QApplication::UnicodeUTF8));
    action_about->setText(QApplication::translate("MainWindow", "O Programie", 0, QApplication::UnicodeUTF8));
    action_add_contact_to_list->setText(QApplication::translate("MainWindow", "Dodaj Kontakt do listy", 0, QApplication::UnicodeUTF8));
    action_remove_contact_from_list->setText(QApplication::translate("MainWindow", "Usu\305\204 kontakt z listy", 0, QApplication::UnicodeUTF8));
    action_close_application->setText(QApplication::translate("MainWindow", "Zako\305\204cz dzia\305\202anie programu", 0, QApplication::UnicodeUTF8));

#ifndef QT_NO_TOOLTIP
    call_button->setToolTip(QApplication::translate("MainWindow", "<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Nawi\304\205zuje po\305\202\304\205czenie z kontaktem SIP</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP

    call_button->setText(QApplication::translate("MainWindow", "Po\305\202\304\205cz", 0, QApplication::UnicodeUTF8));

#ifndef QT_NO_TOOLTIP
    hang_button->setToolTip(QApplication::translate("MainWindow", "<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Ko\305\204czy wybrane po\305\202\304\205czenie.</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP

    hang_button->setText(QApplication::translate("MainWindow", "Roz\305\202\304\205cz", 0, QApplication::UnicodeUTF8));

#ifndef QT_NO_ACCESSIBILITY
    toolBox->setAccessibleName(QApplication::translate("MainWindow", "tab_contacts", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_ACCESSIBILITY

    save_contact_list_button->setText(QApplication::translate("MainWindow", "Zapisz list\304\231 do pliku", 0, QApplication::UnicodeUTF8));
    load_contact_list_button->setText(QApplication::translate("MainWindow", "Odczytaj list\304\231 z pliku", 0, QApplication::UnicodeUTF8));
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
    number_entry->setText(QString());
    label->setText(QApplication::translate("MainWindow", "Podaj adres lub numer SIP rozm\303\263wcy ", 0, QApplication::UnicodeUTF8));
    label_14->setText(QApplication::translate("MainWindow", "sip:", 0, QApplication::UnicodeUTF8));
    toolBox->setItemText(toolBox->indexOf(page_dialer), QApplication::translate("MainWindow", "Wybieranie numer\303\263w", 0, QApplication::UnicodeUTF8));
    label_3->setText(QApplication::translate("MainWindow", "Has\305\202o konta SIP", 0, QApplication::UnicodeUTF8));
    user_password->setInputMask(QString());
    label_5->setText(QApplication::translate("MainWindow", "Nazwa u\305\274ytkownika", 0, QApplication::UnicodeUTF8));
    user_sip_server->setText(QString());
    label_6->setText(QApplication::translate("MainWindow", "Adres serwera SIP proxy", 0, QApplication::UnicodeUTF8));
    auto_login->setText(QApplication::translate("MainWindow", "Logowanie automatyczne przy starcie ", 0, QApplication::UnicodeUTF8));
    load_config_button->setText(QApplication::translate("MainWindow", "Wczytaj konfiguracj\304\231", 0, QApplication::UnicodeUTF8));
    save_config_button->setText(QApplication::translate("MainWindow", "Zapisz konfiguracj\304\231", 0, QApplication::UnicodeUTF8));
    toolBox->setItemText(toolBox->indexOf(page_preferences), QApplication::translate("MainWindow", "Preferencje u\305\274ytkownika", 0, QApplication::UnicodeUTF8));
    groupBox_2->setTitle(QApplication::translate("MainWindow", "Ustawienia g\305\202o\305\233no\305\233ci", 0, QApplication::UnicodeUTF8));
    label_15->setText(QApplication::translate("MainWindow", "G\305\202osno\305\233\304\207 wyj\305\233cia", 0, QApplication::UnicodeUTF8));
    label_16->setText(QApplication::translate("MainWindow", "Czu\305\202o\305\233\304\207 mikrofonu", 0, QApplication::UnicodeUTF8));
    groupBox_3->setTitle(QApplication::translate("MainWindow", "Ustawienia karty d\305\272wi\304\231kowej", 0, QApplication::UnicodeUTF8));
    in_soundcard->setItemText(0, QApplication::translate("MainWindow", "OSS 4", 0, QApplication::UnicodeUTF8));
    in_soundcard->setItemText(1, QApplication::translate("MainWindow", "ALSA 10.x", 0, QApplication::UnicodeUTF8));

    recording_source->setItemText(0, QApplication::translate("MainWindow", "mikrofon", 0, QApplication::UnicodeUTF8));
    recording_source->setItemText(1, QApplication::translate("MainWindow", "wej\305\233cie liniowe", 0, QApplication::UnicodeUTF8));

    ring_sound->setItemText(0, QApplication::translate("MainWindow", "sounds/oldphone.wav", 0, QApplication::UnicodeUTF8));

    label_8->setText(QApplication::translate("MainWindow", "Wyj\305\233cie", 0, QApplication::UnicodeUTF8));
    label_9->setText(QApplication::translate("MainWindow", "Wej\305\233cie", 0, QApplication::UnicodeUTF8));
    label_10->setText(QApplication::translate("MainWindow", "\305\271r\303\263d\305\202o d\305\272wi\304\231ku", 0, QApplication::UnicodeUTF8));
    label_11->setText(QApplication::translate("MainWindow", "Sygna\305\202 dzwonka", 0, QApplication::UnicodeUTF8));
    out_soundcard->setItemText(0, QApplication::translate("MainWindow", "OSS 4", 0, QApplication::UnicodeUTF8));
    out_soundcard->setItemText(1, QApplication::translate("MainWindow", "ALSA 10.x", 0, QApplication::UnicodeUTF8));

    groupBox_4->setTitle(QApplication::translate("MainWindow", "Ustawienia sieciowe", 0, QApplication::UnicodeUTF8));
    no_firewall->setText(QApplication::translate("MainWindow", "Brak zapory ogniowej ( FireWall )", 0, QApplication::UnicodeUTF8));
    default_port->setText(QApplication::translate("MainWindow", "5060", 0, QApplication::UnicodeUTF8));
    label_12->setText(QApplication::translate("MainWindow", "Domy\305\233lny port SIP", 0, QApplication::UnicodeUTF8));
    use_stun_server->setText(QApplication::translate("MainWindow", "U\305\274yj podanego adresu serwera STUN", 0, QApplication::UnicodeUTF8));
    manual_firewall_address->setText(QApplication::translate("MainWindow", "Wprowad\305\272 r\304\231cznie adres FireWall'a", 0, QApplication::UnicodeUTF8));
    toolBox->setItemText(toolBox->indexOf(page_advanced), QApplication::translate("MainWindow", "Ustawienia zaawansowane", 0, QApplication::UnicodeUTF8));
    label_4->setText(QApplication::translate("MainWindow", "Wybierz dzie\305\204 by zobaczy\304\207 raporty", 0, QApplication::UnicodeUTF8));
    raport_viewer->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'DejaVu Sans'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Sans Serif'; font-size:10pt;\">Brak raport\303\263w z wybranego dnia.</p></body></html>", 0, QApplication::UnicodeUTF8));
    label_7->setText(QApplication::translate("MainWindow", "Lista po\305\202\304\205cze\305\204 z wybranego dnia", 0, QApplication::UnicodeUTF8));
    toolBox->setItemText(toolBox->indexOf(page_raports), QApplication::translate("MainWindow", "Raporty z po\305\202\304\205cze\305\204", 0, QApplication::UnicodeUTF8));
    status_box->setTitle(QApplication::translate("MainWindow", "status:", 0, QApplication::UnicodeUTF8));
    status_bar->setText(QApplication::translate("MainWindow", "Program nie wykonuje \305\274adnej akcji", 0, QApplication::UnicodeUTF8));
    comboBox->setItemText(0, QApplication::translate("MainWindow", "Dost\304\231pny", 0, QApplication::UnicodeUTF8));
    comboBox->setItemText(1, QApplication::translate("MainWindow", "Zaj\304\231ty", 0, QApplication::UnicodeUTF8));
    comboBox->setItemText(2, QApplication::translate("MainWindow", "Nie przeszkadza\304\207", 0, QApplication::UnicodeUTF8));
    comboBox->setItemText(3, QApplication::translate("MainWindow", "Niedost\304\231pny", 0, QApplication::UnicodeUTF8));

    menuDsipcom->setTitle(QApplication::translate("MainWindow", "dSipCom", 0, QApplication::UnicodeUTF8));
    menuPomoc->setTitle(QApplication::translate("MainWindow", "Pomoc", 0, QApplication::UnicodeUTF8));
    menuKontakty->setTitle(QApplication::translate("MainWindow", "Kontakty", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DSIPCOM_H
