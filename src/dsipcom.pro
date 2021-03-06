CONFIG += release
HEADERS += main.h \
	 version.h \
	 logger.h \
	 dsipcom_ui.h \
	 platform.h \
	 d_utils.h
   
SOURCES += dsipcom_ui.cpp \
	 logger.cpp \
	 d_utils.cpp \
	 platform.cpp \
	 main.cpp
					 
FORMS += dsipcom.ui \
	add_contact_dialog.ui \
	about.ui
  
RESOURCES += dsipcom.qrc
LIBS += -llinphone -lboost_filesystem

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
    error( "No logger.cpp file found" )
}

!exists( win_specification.h ) {
 		error( "Unable to find windows spec." )
}

!exists( unix_specification.h ) {
 		error( "Unable to find unix spec." )
}

# Release: QMAKE_CXXFLAGS += -std=c++0x -Os -w -march=athlon64
# Debug: QMAKE_CXXFLAGS += -std=c++0x -O0 -ggdb -W
QMAKE_CXXFLAGS += -O2 -w -march=athlon64
TARGET = ../dsipcom
target.path = ../
sources.files = $$SOURCES $$HEADERS $$RESOURCES $$FORMS *.pro
sources.path = .
INSTALLS += target sources
