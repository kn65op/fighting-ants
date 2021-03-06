#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/src/Properties.o \
	${OBJECTDIR}/src/Colors.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/src/Food.o \
	${OBJECTDIR}/src/Field.o \
	${OBJECTDIR}/src/ApplicationControllerGtkmm.o \
	${OBJECTDIR}/src/EnginePropertiesDialog.o \
	${OBJECTDIR}/src/SimulationPropertiesDialog.o \
	${OBJECTDIR}/src/Ant.o \
	${OBJECTDIR}/src/MainWindow.o \
	${OBJECTDIR}/src/GroundArea.o \
	${OBJECTDIR}/src/Ground.o \
	${OBJECTDIR}/src/Nest.o \
	${OBJECTDIR}/src/Direction.o \
	${OBJECTDIR}/src/ApplicationController.o

# Test Directory
TESTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}/tests

# Test Files
TESTFILES= \
	${TESTDIR}/TestFiles/f2 \
	${TESTDIR}/TestFiles/f1

# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=-std=c++0x `pkg-config gtkmm-3.0 --cflags` 
CXXFLAGS=-std=c++0x `pkg-config gtkmm-3.0 --cflags` 

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=LibHelper/dist/Debug/GNU-Linux-x86/libHelper.so

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/fighting-ants

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/fighting-ants: LibHelper/dist/Debug/GNU-Linux-x86/libHelper.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/fighting-ants: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/fighting-ants  ${OBJECTFILES} ${LDLIBSOPTIONS} `pkg-config gtkmm-3.0 --libs`

${OBJECTDIR}/src/Properties.o: src/Properties.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -ILibHelper/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Properties.o src/Properties.cpp

${OBJECTDIR}/src/Colors.o: src/Colors.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -ILibHelper/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Colors.o src/Colors.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -ILibHelper/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/src/Food.o: src/Food.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -ILibHelper/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Food.o src/Food.cpp

${OBJECTDIR}/src/Field.o: src/Field.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -ILibHelper/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Field.o src/Field.cpp

${OBJECTDIR}/src/ApplicationControllerGtkmm.o: src/ApplicationControllerGtkmm.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -ILibHelper/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/ApplicationControllerGtkmm.o src/ApplicationControllerGtkmm.cpp

${OBJECTDIR}/src/EnginePropertiesDialog.o: src/EnginePropertiesDialog.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -ILibHelper/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/EnginePropertiesDialog.o src/EnginePropertiesDialog.cpp

${OBJECTDIR}/src/SimulationPropertiesDialog.o: src/SimulationPropertiesDialog.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -ILibHelper/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/SimulationPropertiesDialog.o src/SimulationPropertiesDialog.cpp

${OBJECTDIR}/src/Ant.o: src/Ant.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -ILibHelper/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Ant.o src/Ant.cpp

${OBJECTDIR}/src/MainWindow.o: src/MainWindow.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -ILibHelper/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/MainWindow.o src/MainWindow.cpp

${OBJECTDIR}/src/GroundArea.o: src/GroundArea.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -ILibHelper/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/GroundArea.o src/GroundArea.cpp

${OBJECTDIR}/src/Ground.o: src/Ground.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -ILibHelper/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Ground.o src/Ground.cpp

${OBJECTDIR}/src/Nest.o: src/Nest.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -ILibHelper/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Nest.o src/Nest.cpp

${OBJECTDIR}/src/Direction.o: src/Direction.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -ILibHelper/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Direction.o src/Direction.cpp

${OBJECTDIR}/src/ApplicationController.o: src/ApplicationController.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -ILibHelper/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/ApplicationController.o src/ApplicationController.cpp

# Subprojects
.build-subprojects:
	cd LibHelper && ${MAKE}  -f Makefile CONF=Debug

# Build Test Targets
.build-tests-conf: .build-conf ${TESTFILES}
${TESTDIR}/TestFiles/f2: ${TESTDIR}/tests/FindingAntsTest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc} -lpthread `pkg-config gtkmm-3.0 --libs`  -o ${TESTDIR}/TestFiles/f2 $^ ${LDLIBSOPTIONS} ../gtest-1.6.0/libgtest.a 

${TESTDIR}/TestFiles/f1: ${TESTDIR}/tests/DistanceToBorderTest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc} -lpthread `pkg-config gtkmm-3.0 --libs`  -o ${TESTDIR}/TestFiles/f1 $^ ${LDLIBSOPTIONS} ../gtest-1.6.0/libgtest.a 


${TESTDIR}/tests/FindingAntsTest.o: tests/FindingAntsTest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} $@.d
	$(COMPILE.cc) -g -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I../gtest-1.6.0/include -ILibHelper/include -MMD -MP -MF $@.d -o ${TESTDIR}/tests/FindingAntsTest.o tests/FindingAntsTest.cpp


${TESTDIR}/tests/DistanceToBorderTest.o: tests/DistanceToBorderTest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} $@.d
	$(COMPILE.cc) -g -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I. -I../gtest-1.6.0/include -ILibHelper/include -MMD -MP -MF $@.d -o ${TESTDIR}/tests/DistanceToBorderTest.o tests/DistanceToBorderTest.cpp


${OBJECTDIR}/src/Properties_nomain.o: ${OBJECTDIR}/src/Properties.o src/Properties.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/Properties.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -ILibHelper/include -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Properties_nomain.o src/Properties.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/Properties.o ${OBJECTDIR}/src/Properties_nomain.o;\
	fi

${OBJECTDIR}/src/Colors_nomain.o: ${OBJECTDIR}/src/Colors.o src/Colors.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/Colors.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -ILibHelper/include -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Colors_nomain.o src/Colors.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/Colors.o ${OBJECTDIR}/src/Colors_nomain.o;\
	fi

${OBJECTDIR}/main_nomain.o: ${OBJECTDIR}/main.o main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/main.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -ILibHelper/include -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/main_nomain.o main.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/main.o ${OBJECTDIR}/main_nomain.o;\
	fi

${OBJECTDIR}/src/Food_nomain.o: ${OBJECTDIR}/src/Food.o src/Food.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/Food.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -ILibHelper/include -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Food_nomain.o src/Food.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/Food.o ${OBJECTDIR}/src/Food_nomain.o;\
	fi

${OBJECTDIR}/src/Field_nomain.o: ${OBJECTDIR}/src/Field.o src/Field.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/Field.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -ILibHelper/include -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Field_nomain.o src/Field.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/Field.o ${OBJECTDIR}/src/Field_nomain.o;\
	fi

${OBJECTDIR}/src/ApplicationControllerGtkmm_nomain.o: ${OBJECTDIR}/src/ApplicationControllerGtkmm.o src/ApplicationControllerGtkmm.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/ApplicationControllerGtkmm.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -ILibHelper/include -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/ApplicationControllerGtkmm_nomain.o src/ApplicationControllerGtkmm.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/ApplicationControllerGtkmm.o ${OBJECTDIR}/src/ApplicationControllerGtkmm_nomain.o;\
	fi

${OBJECTDIR}/src/EnginePropertiesDialog_nomain.o: ${OBJECTDIR}/src/EnginePropertiesDialog.o src/EnginePropertiesDialog.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/EnginePropertiesDialog.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -ILibHelper/include -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/EnginePropertiesDialog_nomain.o src/EnginePropertiesDialog.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/EnginePropertiesDialog.o ${OBJECTDIR}/src/EnginePropertiesDialog_nomain.o;\
	fi

${OBJECTDIR}/src/SimulationPropertiesDialog_nomain.o: ${OBJECTDIR}/src/SimulationPropertiesDialog.o src/SimulationPropertiesDialog.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/SimulationPropertiesDialog.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -ILibHelper/include -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/SimulationPropertiesDialog_nomain.o src/SimulationPropertiesDialog.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/SimulationPropertiesDialog.o ${OBJECTDIR}/src/SimulationPropertiesDialog_nomain.o;\
	fi

${OBJECTDIR}/src/Ant_nomain.o: ${OBJECTDIR}/src/Ant.o src/Ant.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/Ant.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -ILibHelper/include -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Ant_nomain.o src/Ant.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/Ant.o ${OBJECTDIR}/src/Ant_nomain.o;\
	fi

${OBJECTDIR}/src/MainWindow_nomain.o: ${OBJECTDIR}/src/MainWindow.o src/MainWindow.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/MainWindow.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -ILibHelper/include -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/MainWindow_nomain.o src/MainWindow.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/MainWindow.o ${OBJECTDIR}/src/MainWindow_nomain.o;\
	fi

${OBJECTDIR}/src/GroundArea_nomain.o: ${OBJECTDIR}/src/GroundArea.o src/GroundArea.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/GroundArea.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -ILibHelper/include -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/GroundArea_nomain.o src/GroundArea.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/GroundArea.o ${OBJECTDIR}/src/GroundArea_nomain.o;\
	fi

${OBJECTDIR}/src/Ground_nomain.o: ${OBJECTDIR}/src/Ground.o src/Ground.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/Ground.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -ILibHelper/include -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Ground_nomain.o src/Ground.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/Ground.o ${OBJECTDIR}/src/Ground_nomain.o;\
	fi

${OBJECTDIR}/src/Nest_nomain.o: ${OBJECTDIR}/src/Nest.o src/Nest.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/Nest.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -ILibHelper/include -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Nest_nomain.o src/Nest.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/Nest.o ${OBJECTDIR}/src/Nest_nomain.o;\
	fi

${OBJECTDIR}/src/Direction_nomain.o: ${OBJECTDIR}/src/Direction.o src/Direction.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/Direction.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -ILibHelper/include -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Direction_nomain.o src/Direction.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/Direction.o ${OBJECTDIR}/src/Direction_nomain.o;\
	fi

${OBJECTDIR}/src/ApplicationController_nomain.o: ${OBJECTDIR}/src/ApplicationController.o src/ApplicationController.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/ApplicationController.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -ILibHelper/include -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/ApplicationController_nomain.o src/ApplicationController.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/ApplicationController.o ${OBJECTDIR}/src/ApplicationController_nomain.o;\
	fi

# Run Test Targets
.test-conf:
	@if [ "${TEST}" = "" ]; \
	then  \
	    ${TESTDIR}/TestFiles/f2 || true; \
	    ${TESTDIR}/TestFiles/f1 || true; \
	else  \
	    ./${TEST} || true; \
	fi

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/fighting-ants

# Subprojects
.clean-subprojects:
	cd LibHelper && ${MAKE}  -f Makefile CONF=Debug clean

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
