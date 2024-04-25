#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/P2B_2.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/P2B_2.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS

else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=TTIMER.c LCD.c newmain.c TMENU.c TTECLAT.c TJOYSTICK.c SIO.c CURRENT_TIME.c TALTAVEU.c TRECORDING.c TEEPROM.c TPLAY_RECORDING.c TWIFI.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/TTIMER.p1 ${OBJECTDIR}/LCD.p1 ${OBJECTDIR}/newmain.p1 ${OBJECTDIR}/TMENU.p1 ${OBJECTDIR}/TTECLAT.p1 ${OBJECTDIR}/TJOYSTICK.p1 ${OBJECTDIR}/SIO.p1 ${OBJECTDIR}/CURRENT_TIME.p1 ${OBJECTDIR}/TALTAVEU.p1 ${OBJECTDIR}/TRECORDING.p1 ${OBJECTDIR}/TEEPROM.p1 ${OBJECTDIR}/TPLAY_RECORDING.p1 ${OBJECTDIR}/TWIFI.p1
POSSIBLE_DEPFILES=${OBJECTDIR}/TTIMER.p1.d ${OBJECTDIR}/LCD.p1.d ${OBJECTDIR}/newmain.p1.d ${OBJECTDIR}/TMENU.p1.d ${OBJECTDIR}/TTECLAT.p1.d ${OBJECTDIR}/TJOYSTICK.p1.d ${OBJECTDIR}/SIO.p1.d ${OBJECTDIR}/CURRENT_TIME.p1.d ${OBJECTDIR}/TALTAVEU.p1.d ${OBJECTDIR}/TRECORDING.p1.d ${OBJECTDIR}/TEEPROM.p1.d ${OBJECTDIR}/TPLAY_RECORDING.p1.d ${OBJECTDIR}/TWIFI.p1.d

# Object Files
OBJECTFILES=${OBJECTDIR}/TTIMER.p1 ${OBJECTDIR}/LCD.p1 ${OBJECTDIR}/newmain.p1 ${OBJECTDIR}/TMENU.p1 ${OBJECTDIR}/TTECLAT.p1 ${OBJECTDIR}/TJOYSTICK.p1 ${OBJECTDIR}/SIO.p1 ${OBJECTDIR}/CURRENT_TIME.p1 ${OBJECTDIR}/TALTAVEU.p1 ${OBJECTDIR}/TRECORDING.p1 ${OBJECTDIR}/TEEPROM.p1 ${OBJECTDIR}/TPLAY_RECORDING.p1 ${OBJECTDIR}/TWIFI.p1

# Source Files
SOURCEFILES=TTIMER.c LCD.c newmain.c TMENU.c TTECLAT.c TJOYSTICK.c SIO.c CURRENT_TIME.c TALTAVEU.c TRECORDING.c TEEPROM.c TPLAY_RECORDING.c TWIFI.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/P2B_2.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=18F4321
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/TTIMER.p1: TTIMER.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/TTIMER.p1.d 
	@${RM} ${OBJECTDIR}/TTIMER.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1    -fno-short-double -fno-short-float -memi=wordwrite -Os -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/TTIMER.p1 TTIMER.c 
	@-${MV} ${OBJECTDIR}/TTIMER.d ${OBJECTDIR}/TTIMER.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/TTIMER.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/LCD.p1: LCD.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/LCD.p1.d 
	@${RM} ${OBJECTDIR}/LCD.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1    -fno-short-double -fno-short-float -memi=wordwrite -Os -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/LCD.p1 LCD.c 
	@-${MV} ${OBJECTDIR}/LCD.d ${OBJECTDIR}/LCD.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/LCD.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/newmain.p1: newmain.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/newmain.p1.d 
	@${RM} ${OBJECTDIR}/newmain.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1    -fno-short-double -fno-short-float -memi=wordwrite -Os -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/newmain.p1 newmain.c 
	@-${MV} ${OBJECTDIR}/newmain.d ${OBJECTDIR}/newmain.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/newmain.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/TMENU.p1: TMENU.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/TMENU.p1.d 
	@${RM} ${OBJECTDIR}/TMENU.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1    -fno-short-double -fno-short-float -memi=wordwrite -Os -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/TMENU.p1 TMENU.c 
	@-${MV} ${OBJECTDIR}/TMENU.d ${OBJECTDIR}/TMENU.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/TMENU.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/TTECLAT.p1: TTECLAT.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/TTECLAT.p1.d 
	@${RM} ${OBJECTDIR}/TTECLAT.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1    -fno-short-double -fno-short-float -memi=wordwrite -Os -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/TTECLAT.p1 TTECLAT.c 
	@-${MV} ${OBJECTDIR}/TTECLAT.d ${OBJECTDIR}/TTECLAT.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/TTECLAT.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/TJOYSTICK.p1: TJOYSTICK.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/TJOYSTICK.p1.d 
	@${RM} ${OBJECTDIR}/TJOYSTICK.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1    -fno-short-double -fno-short-float -memi=wordwrite -Os -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/TJOYSTICK.p1 TJOYSTICK.c 
	@-${MV} ${OBJECTDIR}/TJOYSTICK.d ${OBJECTDIR}/TJOYSTICK.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/TJOYSTICK.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/SIO.p1: SIO.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/SIO.p1.d 
	@${RM} ${OBJECTDIR}/SIO.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1    -fno-short-double -fno-short-float -memi=wordwrite -Os -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/SIO.p1 SIO.c 
	@-${MV} ${OBJECTDIR}/SIO.d ${OBJECTDIR}/SIO.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/SIO.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/CURRENT_TIME.p1: CURRENT_TIME.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/CURRENT_TIME.p1.d 
	@${RM} ${OBJECTDIR}/CURRENT_TIME.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1    -fno-short-double -fno-short-float -memi=wordwrite -Os -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/CURRENT_TIME.p1 CURRENT_TIME.c 
	@-${MV} ${OBJECTDIR}/CURRENT_TIME.d ${OBJECTDIR}/CURRENT_TIME.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/CURRENT_TIME.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/TALTAVEU.p1: TALTAVEU.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/TALTAVEU.p1.d 
	@${RM} ${OBJECTDIR}/TALTAVEU.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1    -fno-short-double -fno-short-float -memi=wordwrite -Os -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/TALTAVEU.p1 TALTAVEU.c 
	@-${MV} ${OBJECTDIR}/TALTAVEU.d ${OBJECTDIR}/TALTAVEU.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/TALTAVEU.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/TRECORDING.p1: TRECORDING.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/TRECORDING.p1.d 
	@${RM} ${OBJECTDIR}/TRECORDING.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1    -fno-short-double -fno-short-float -memi=wordwrite -Os -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/TRECORDING.p1 TRECORDING.c 
	@-${MV} ${OBJECTDIR}/TRECORDING.d ${OBJECTDIR}/TRECORDING.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/TRECORDING.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/TEEPROM.p1: TEEPROM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/TEEPROM.p1.d 
	@${RM} ${OBJECTDIR}/TEEPROM.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1    -fno-short-double -fno-short-float -memi=wordwrite -Os -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/TEEPROM.p1 TEEPROM.c 
	@-${MV} ${OBJECTDIR}/TEEPROM.d ${OBJECTDIR}/TEEPROM.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/TEEPROM.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/TPLAY_RECORDING.p1: TPLAY_RECORDING.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/TPLAY_RECORDING.p1.d 
	@${RM} ${OBJECTDIR}/TPLAY_RECORDING.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1    -fno-short-double -fno-short-float -memi=wordwrite -Os -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/TPLAY_RECORDING.p1 TPLAY_RECORDING.c 
	@-${MV} ${OBJECTDIR}/TPLAY_RECORDING.d ${OBJECTDIR}/TPLAY_RECORDING.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/TPLAY_RECORDING.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/TWIFI.p1: TWIFI.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/TWIFI.p1.d 
	@${RM} ${OBJECTDIR}/TWIFI.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1    -fno-short-double -fno-short-float -memi=wordwrite -Os -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/TWIFI.p1 TWIFI.c 
	@-${MV} ${OBJECTDIR}/TWIFI.d ${OBJECTDIR}/TWIFI.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/TWIFI.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
else
${OBJECTDIR}/TTIMER.p1: TTIMER.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/TTIMER.p1.d 
	@${RM} ${OBJECTDIR}/TTIMER.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c    -fno-short-double -fno-short-float -memi=wordwrite -Os -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/TTIMER.p1 TTIMER.c 
	@-${MV} ${OBJECTDIR}/TTIMER.d ${OBJECTDIR}/TTIMER.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/TTIMER.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/LCD.p1: LCD.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/LCD.p1.d 
	@${RM} ${OBJECTDIR}/LCD.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c    -fno-short-double -fno-short-float -memi=wordwrite -Os -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/LCD.p1 LCD.c 
	@-${MV} ${OBJECTDIR}/LCD.d ${OBJECTDIR}/LCD.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/LCD.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/newmain.p1: newmain.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/newmain.p1.d 
	@${RM} ${OBJECTDIR}/newmain.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c    -fno-short-double -fno-short-float -memi=wordwrite -Os -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/newmain.p1 newmain.c 
	@-${MV} ${OBJECTDIR}/newmain.d ${OBJECTDIR}/newmain.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/newmain.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/TMENU.p1: TMENU.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/TMENU.p1.d 
	@${RM} ${OBJECTDIR}/TMENU.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c    -fno-short-double -fno-short-float -memi=wordwrite -Os -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/TMENU.p1 TMENU.c 
	@-${MV} ${OBJECTDIR}/TMENU.d ${OBJECTDIR}/TMENU.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/TMENU.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/TTECLAT.p1: TTECLAT.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/TTECLAT.p1.d 
	@${RM} ${OBJECTDIR}/TTECLAT.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c    -fno-short-double -fno-short-float -memi=wordwrite -Os -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/TTECLAT.p1 TTECLAT.c 
	@-${MV} ${OBJECTDIR}/TTECLAT.d ${OBJECTDIR}/TTECLAT.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/TTECLAT.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/TJOYSTICK.p1: TJOYSTICK.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/TJOYSTICK.p1.d 
	@${RM} ${OBJECTDIR}/TJOYSTICK.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c    -fno-short-double -fno-short-float -memi=wordwrite -Os -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/TJOYSTICK.p1 TJOYSTICK.c 
	@-${MV} ${OBJECTDIR}/TJOYSTICK.d ${OBJECTDIR}/TJOYSTICK.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/TJOYSTICK.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/SIO.p1: SIO.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/SIO.p1.d 
	@${RM} ${OBJECTDIR}/SIO.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c    -fno-short-double -fno-short-float -memi=wordwrite -Os -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/SIO.p1 SIO.c 
	@-${MV} ${OBJECTDIR}/SIO.d ${OBJECTDIR}/SIO.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/SIO.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/CURRENT_TIME.p1: CURRENT_TIME.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/CURRENT_TIME.p1.d 
	@${RM} ${OBJECTDIR}/CURRENT_TIME.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c    -fno-short-double -fno-short-float -memi=wordwrite -Os -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/CURRENT_TIME.p1 CURRENT_TIME.c 
	@-${MV} ${OBJECTDIR}/CURRENT_TIME.d ${OBJECTDIR}/CURRENT_TIME.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/CURRENT_TIME.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/TALTAVEU.p1: TALTAVEU.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/TALTAVEU.p1.d 
	@${RM} ${OBJECTDIR}/TALTAVEU.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c    -fno-short-double -fno-short-float -memi=wordwrite -Os -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/TALTAVEU.p1 TALTAVEU.c 
	@-${MV} ${OBJECTDIR}/TALTAVEU.d ${OBJECTDIR}/TALTAVEU.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/TALTAVEU.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/TRECORDING.p1: TRECORDING.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/TRECORDING.p1.d 
	@${RM} ${OBJECTDIR}/TRECORDING.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c    -fno-short-double -fno-short-float -memi=wordwrite -Os -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/TRECORDING.p1 TRECORDING.c 
	@-${MV} ${OBJECTDIR}/TRECORDING.d ${OBJECTDIR}/TRECORDING.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/TRECORDING.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/TEEPROM.p1: TEEPROM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/TEEPROM.p1.d 
	@${RM} ${OBJECTDIR}/TEEPROM.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c    -fno-short-double -fno-short-float -memi=wordwrite -Os -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/TEEPROM.p1 TEEPROM.c 
	@-${MV} ${OBJECTDIR}/TEEPROM.d ${OBJECTDIR}/TEEPROM.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/TEEPROM.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/TPLAY_RECORDING.p1: TPLAY_RECORDING.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/TPLAY_RECORDING.p1.d 
	@${RM} ${OBJECTDIR}/TPLAY_RECORDING.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c    -fno-short-double -fno-short-float -memi=wordwrite -Os -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/TPLAY_RECORDING.p1 TPLAY_RECORDING.c 
	@-${MV} ${OBJECTDIR}/TPLAY_RECORDING.d ${OBJECTDIR}/TPLAY_RECORDING.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/TPLAY_RECORDING.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/TWIFI.p1: TWIFI.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/TWIFI.p1.d 
	@${RM} ${OBJECTDIR}/TWIFI.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c    -fno-short-double -fno-short-float -memi=wordwrite -Os -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/TWIFI.p1 TWIFI.c 
	@-${MV} ${OBJECTDIR}/TWIFI.d ${OBJECTDIR}/TWIFI.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/TWIFI.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/P2B_2.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=dist/${CND_CONF}/${IMAGE_TYPE}/P2B_2.X.${IMAGE_TYPE}.map  -D__DEBUG=1  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1    -fno-short-double -fno-short-float -memi=wordwrite -Os -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -mrom=default,-1dc0-1fff -mram=default,-1f4-1ff,-f9c-f9c,-fd4-fd4,-fdb-fdf,-fe3-fe7,-feb-fef,-ffd-fff  $(COMPARISON_BUILD) -Wl,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -o dist/${CND_CONF}/${IMAGE_TYPE}/P2B_2.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	@${RM} dist/${CND_CONF}/${IMAGE_TYPE}/P2B_2.X.${IMAGE_TYPE}.hex 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/P2B_2.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=dist/${CND_CONF}/${IMAGE_TYPE}/P2B_2.X.${IMAGE_TYPE}.map  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1    -fno-short-double -fno-short-float -memi=wordwrite -Os -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     $(COMPARISON_BUILD) -Wl,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -o dist/${CND_CONF}/${IMAGE_TYPE}/P2B_2.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
