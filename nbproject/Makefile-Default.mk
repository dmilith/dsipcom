#
# Gererated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran

# Include project Makefile
include dsipcom-public-Makefile3.mk

# Object Directory
OBJECTDIR=build/Default/GNU-Linux-x86

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/home/dmilith/Private_1/Programowanie/INŻYNIERKA/dsipcom-public/src/logger.o \
	${OBJECTDIR}/_ext/home/dmilith/Private_1/Programowanie/INŻYNIERKA/dsipcom-public/src/dsipcom_ui.o \
	${OBJECTDIR}/_ext/home/dmilith/Projects/dsipcom-public/../../../../Projects/dsipcom-public/src/tests/varsizes_test.o \
	${OBJECTDIR}/_ext/home/dmilith/Private_1/Programowanie/INŻYNIERKA/dsipcom-public/src/platform.o \
	${OBJECTDIR}/_ext/home/dmilith/Private_1/Programowanie/INŻYNIERKA/dsipcom-public/src/main.o \
	${OBJECTDIR}/_ext/home/dmilith/Projects/dsipcom-public/../../../../Projects/dsipcom-public/src/tests/IO_file_test.o \
	${OBJECTDIR}/_ext/home/dmilith/Projects/dsipcom-public/../../../../Projects/dsipcom-public/src/tests/varsizes_test.o

# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS} dist/Default/GNU-Linux-x86/dsipcom-public

dist/Default/GNU-Linux-x86/dsipcom-public: ${OBJECTFILES}
	${MKDIR} -p dist/Default/GNU-Linux-x86
	${LINK.cc} -o dist/Default/GNU-Linux-x86/dsipcom-public ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/_ext/home/dmilith/Private_1/Programowanie/INŻYNIERKA/dsipcom-public/src/logger.o: ../../../../Projects/dsipcom-public/src/logger.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/home/dmilith/Private_1/Programowanie/INŻYNIERKA/dsipcom-public/src
	$(COMPILE.cc) -g -o ${OBJECTDIR}/_ext/home/dmilith/Private_1/Programowanie/INŻYNIERKA/dsipcom-public/src/logger.o ../../../../Projects/dsipcom-public/src/logger.cpp

${OBJECTDIR}/_ext/home/dmilith/Private_1/Programowanie/INŻYNIERKA/dsipcom-public/src/dsipcom_ui.o: ../../../../Projects/dsipcom-public/src/dsipcom_ui.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/home/dmilith/Private_1/Programowanie/INŻYNIERKA/dsipcom-public/src
	$(COMPILE.cc) -g -o ${OBJECTDIR}/_ext/home/dmilith/Private_1/Programowanie/INŻYNIERKA/dsipcom-public/src/dsipcom_ui.o ../../../../Projects/dsipcom-public/src/dsipcom_ui.cpp

${OBJECTDIR}/_ext/home/dmilith/Projects/dsipcom-public/../../../../Projects/dsipcom-public/src/tests/varsizes_test.o: ../../../../Projects/dsipcom-public/src/tests/varsizes_test.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/home/dmilith/Projects/dsipcom-public/../../../../Projects/dsipcom-public/src/tests
	$(COMPILE.cc) -g -o ${OBJECTDIR}/_ext/home/dmilith/Projects/dsipcom-public/../../../../Projects/dsipcom-public/src/tests/varsizes_test.o ../../../../Projects/dsipcom-public/src/tests/varsizes_test.cpp

${OBJECTDIR}/_ext/home/dmilith/Private_1/Programowanie/INŻYNIERKA/dsipcom-public/src/platform.o: ../../../../Projects/dsipcom-public/src/platform.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/home/dmilith/Private_1/Programowanie/INŻYNIERKA/dsipcom-public/src
	$(COMPILE.cc) -g -o ${OBJECTDIR}/_ext/home/dmilith/Private_1/Programowanie/INŻYNIERKA/dsipcom-public/src/platform.o ../../../../Projects/dsipcom-public/src/platform.cpp

${OBJECTDIR}/_ext/home/dmilith/Private_1/Programowanie/INŻYNIERKA/dsipcom-public/src/main.o: ../../../../Projects/dsipcom-public/src/main.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/home/dmilith/Private_1/Programowanie/INŻYNIERKA/dsipcom-public/src
	$(COMPILE.cc) -g -o ${OBJECTDIR}/_ext/home/dmilith/Private_1/Programowanie/INŻYNIERKA/dsipcom-public/src/main.o ../../../../Projects/dsipcom-public/src/main.cpp

${OBJECTDIR}/_ext/home/dmilith/Projects/dsipcom-public/../../../../Projects/dsipcom-public/src/tests/IO_file_test.o: ../../../../Projects/dsipcom-public/src/tests/IO_file_test.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/home/dmilith/Projects/dsipcom-public/../../../../Projects/dsipcom-public/src/tests
	$(COMPILE.cc) -g -o ${OBJECTDIR}/_ext/home/dmilith/Projects/dsipcom-public/../../../../Projects/dsipcom-public/src/tests/IO_file_test.o ../../../../Projects/dsipcom-public/src/tests/IO_file_test.cpp

${OBJECTDIR}/_ext/home/dmilith/Projects/dsipcom-public/../../../../Projects/dsipcom-public/src/tests/varsizes_test.o: ../../../../Projects/dsipcom-public/src/tests/varsizes_test.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/home/dmilith/Projects/dsipcom-public/../../../../Projects/dsipcom-public/src/tests
	$(COMPILE.cc) -g -o ${OBJECTDIR}/_ext/home/dmilith/Projects/dsipcom-public/../../../../Projects/dsipcom-public/src/tests/varsizes_test.o ../../../../Projects/dsipcom-public/src/tests/varsizes_test.c

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf:
	${RM} -r build/Default
	${RM} dist/Default/GNU-Linux-x86/dsipcom-public

# Subprojects
.clean-subprojects:
