HEADERS += main.h \
					 ui_icons.h \
					 version.h \
					 logger.h \
					 dsipcom_ui.h
SOURCES += dsipcom_ui.cpp \
					 logger.cpp \
					 main.cpp
					 
FORMS = dsipcom.ui
RCC += dsipcom.qrc

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
sources.files = $$SOURCES $$HEADERS $$RESOURCES $$FORMS *.pro
sources.path = .
INSTALLS += target sources

