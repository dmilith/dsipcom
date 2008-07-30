CONFIG += debug
HEADERS += main.h \
	 version.h \
	 logger.h \
	 dsipcom_ui.h \
	 platform.h
SOURCES += dsipcom_ui.cpp \
	 logger.cpp \
	 platform.cpp \
	 main.cpp
					 
FORMS += dsipcom.ui \
	add_contact_dialog.ui \
	about.ui
RESOURCES += dsipcom.qrc

LIBS += -llinphone -lboost_filesystem

#old libs:
#LIBS += -lspeex -llinphone -losipparser2 -lasound -leXosip2 -lboost_filesystem

win32 {
     HEADERS += win_specification.h
}

unix {
     HEADERS += unix_specification.h
}
 
!exists( main.h ) {
 		error( "No main.h file found" )
}

!exists( main.cpp ) {
    error( "No main.cpp file found" )
}

!exists( logger.cpp ) {
    error( "No main.cpp file found" )
}

!exists( win_specification.h ) {
 		error( "Unable to find windows spec." )
}

!exists( unix_specification.h ) {
 		error( "Unable to find unix spec." )
}

QMAKE_CXXFLAGS += -w -pg
# old: QMAKE_CXXFLAGS += -w
TARGET = ../dsipcom
target.path = ../
sources.files = $$SOURCES $$HEADERS $$RESOURCES $$FORMS *.pro
sources.path = .
INSTALLS += target sources
