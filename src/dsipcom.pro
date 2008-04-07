HEADERS += main.h \
					 version.h \
					 logger.h \
					 dsipcom_ui.h \
           sip_main.h
SOURCES += dsipcom_ui.cpp \
					 logger.cpp \
           sip_main.cpp \
					 main.cpp
					 
FORMS = dsipcom.ui
RESOURCES += dsipcom.qrc

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

TARGET = ../dsipcom
target.path = ../
sources.files = $$SOURCES $$HEADERS $$RESOURCES $$FORMS *.pro
sources.path = .
INSTALLS += target sources

