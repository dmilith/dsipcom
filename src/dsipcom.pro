TEMPLATE = app
LANGUAGE  = C++
TARGET = dSipCom
CONFIGS += qt x11 debug
HEADERS += main.h \
					 ui_icons.h \
           user_interface.h \
					 version.h
SOURCES += main.cpp \
					 
INCLUDEPATH += /usr/include/qt4
unix:OBJECTS_DIR = ./.tmp
win32:OBJECTS_DIR = c:/windows/temp
unix:LIBS += -losip2 -L/usr/local/lib -L/usr/lib
win32:LIBS += c:\mylibs\math.lib

DESTDIR += ../

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

!exists( win_specification.h ) {
 		error( "Unable to find windows spec." )
}

!exists( unix_specification.h ) {
 		error( "Unable to find unix spec." )
}


