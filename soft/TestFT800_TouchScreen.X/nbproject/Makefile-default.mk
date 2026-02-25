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
FINAL_IMAGE=${DISTDIR}/TestFT800_TouchScreen.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/TestFT800_TouchScreen.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=Main_ExSpiLm70.c Mc32Delays.c Mc32SpiUtil.c Mc32gestSPiDac.c Mc32gestSPiLM70.c SK32MX795F512L_V16.c Mc32gestSPI_FT800.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/Main_ExSpiLm70.o ${OBJECTDIR}/Mc32Delays.o ${OBJECTDIR}/Mc32SpiUtil.o ${OBJECTDIR}/Mc32gestSPiDac.o ${OBJECTDIR}/Mc32gestSPiLM70.o ${OBJECTDIR}/SK32MX795F512L_V16.o ${OBJECTDIR}/Mc32gestSPI_FT800.o
POSSIBLE_DEPFILES=${OBJECTDIR}/Main_ExSpiLm70.o.d ${OBJECTDIR}/Mc32Delays.o.d ${OBJECTDIR}/Mc32SpiUtil.o.d ${OBJECTDIR}/Mc32gestSPiDac.o.d ${OBJECTDIR}/Mc32gestSPiLM70.o.d ${OBJECTDIR}/SK32MX795F512L_V16.o.d ${OBJECTDIR}/Mc32gestSPI_FT800.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/Main_ExSpiLm70.o ${OBJECTDIR}/Mc32Delays.o ${OBJECTDIR}/Mc32SpiUtil.o ${OBJECTDIR}/Mc32gestSPiDac.o ${OBJECTDIR}/Mc32gestSPiLM70.o ${OBJECTDIR}/SK32MX795F512L_V16.o ${OBJECTDIR}/Mc32gestSPI_FT800.o

# Source Files
SOURCEFILES=Main_ExSpiLm70.c Mc32Delays.c Mc32SpiUtil.c Mc32gestSPiDac.c Mc32gestSPiLM70.c SK32MX795F512L_V16.c Mc32gestSPI_FT800.c



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
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/TestFT800_TouchScreen.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=32MX795F512L
MP_LINKER_FILE_OPTION=
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
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/Main_ExSpiLm70.o: Main_ExSpiLm70.c  .generated_files/flags/default/eefce49cd4a48b0a2b41ba7adb8ef016a4e8f470 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Main_ExSpiLm70.o.d 
	@${RM} ${OBJECTDIR}/Main_ExSpiLm70.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Main_ExSpiLm70.o.d" -o ${OBJECTDIR}/Main_ExSpiLm70.o Main_ExSpiLm70.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Mc32Delays.o: Mc32Delays.c  .generated_files/flags/default/fecbfa30d4e28b97621e699ef3b889a3d934bb4d .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Mc32Delays.o.d 
	@${RM} ${OBJECTDIR}/Mc32Delays.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Mc32Delays.o.d" -o ${OBJECTDIR}/Mc32Delays.o Mc32Delays.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Mc32SpiUtil.o: Mc32SpiUtil.c  .generated_files/flags/default/18e75788db8f32b91bf74edda3134d7052fdfb0a .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Mc32SpiUtil.o.d 
	@${RM} ${OBJECTDIR}/Mc32SpiUtil.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Mc32SpiUtil.o.d" -o ${OBJECTDIR}/Mc32SpiUtil.o Mc32SpiUtil.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Mc32gestSPiDac.o: Mc32gestSPiDac.c  .generated_files/flags/default/848a45f748658fa45b61bbb2b6d93a3635ce13f9 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Mc32gestSPiDac.o.d 
	@${RM} ${OBJECTDIR}/Mc32gestSPiDac.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Mc32gestSPiDac.o.d" -o ${OBJECTDIR}/Mc32gestSPiDac.o Mc32gestSPiDac.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Mc32gestSPiLM70.o: Mc32gestSPiLM70.c  .generated_files/flags/default/83c16d434a9af176a476f95dcbd1815ea3fc8a89 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Mc32gestSPiLM70.o.d 
	@${RM} ${OBJECTDIR}/Mc32gestSPiLM70.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Mc32gestSPiLM70.o.d" -o ${OBJECTDIR}/Mc32gestSPiLM70.o Mc32gestSPiLM70.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/SK32MX795F512L_V16.o: SK32MX795F512L_V16.c  .generated_files/flags/default/94328c4b49e746e980f10cdc9918d2c7f379a969 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/SK32MX795F512L_V16.o.d 
	@${RM} ${OBJECTDIR}/SK32MX795F512L_V16.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/SK32MX795F512L_V16.o.d" -o ${OBJECTDIR}/SK32MX795F512L_V16.o SK32MX795F512L_V16.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Mc32gestSPI_FT800.o: Mc32gestSPI_FT800.c  .generated_files/flags/default/bc7adc877047314bcbac83491d60671fd30ef855 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Mc32gestSPI_FT800.o.d 
	@${RM} ${OBJECTDIR}/Mc32gestSPI_FT800.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Mc32gestSPI_FT800.o.d" -o ${OBJECTDIR}/Mc32gestSPI_FT800.o Mc32gestSPI_FT800.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
else
${OBJECTDIR}/Main_ExSpiLm70.o: Main_ExSpiLm70.c  .generated_files/flags/default/818a7ad7eaefc0e6852dcc2b20f31ae05a78128e .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Main_ExSpiLm70.o.d 
	@${RM} ${OBJECTDIR}/Main_ExSpiLm70.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Main_ExSpiLm70.o.d" -o ${OBJECTDIR}/Main_ExSpiLm70.o Main_ExSpiLm70.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Mc32Delays.o: Mc32Delays.c  .generated_files/flags/default/3f13e59a1dd0fc221c1657987dd452f8a6567e0d .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Mc32Delays.o.d 
	@${RM} ${OBJECTDIR}/Mc32Delays.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Mc32Delays.o.d" -o ${OBJECTDIR}/Mc32Delays.o Mc32Delays.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Mc32SpiUtil.o: Mc32SpiUtil.c  .generated_files/flags/default/51515ef26eefe4e0425def29fd9744825aa4ac94 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Mc32SpiUtil.o.d 
	@${RM} ${OBJECTDIR}/Mc32SpiUtil.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Mc32SpiUtil.o.d" -o ${OBJECTDIR}/Mc32SpiUtil.o Mc32SpiUtil.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Mc32gestSPiDac.o: Mc32gestSPiDac.c  .generated_files/flags/default/6e7c6c5cda57694915cc145015f7fc557503875b .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Mc32gestSPiDac.o.d 
	@${RM} ${OBJECTDIR}/Mc32gestSPiDac.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Mc32gestSPiDac.o.d" -o ${OBJECTDIR}/Mc32gestSPiDac.o Mc32gestSPiDac.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Mc32gestSPiLM70.o: Mc32gestSPiLM70.c  .generated_files/flags/default/31a3ec7c167f1be090d81ba53a46ce17b08dc94d .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Mc32gestSPiLM70.o.d 
	@${RM} ${OBJECTDIR}/Mc32gestSPiLM70.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Mc32gestSPiLM70.o.d" -o ${OBJECTDIR}/Mc32gestSPiLM70.o Mc32gestSPiLM70.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/SK32MX795F512L_V16.o: SK32MX795F512L_V16.c  .generated_files/flags/default/6e3658f707ca8b852f16a2fe67f0a1fbcdb3b7c1 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/SK32MX795F512L_V16.o.d 
	@${RM} ${OBJECTDIR}/SK32MX795F512L_V16.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/SK32MX795F512L_V16.o.d" -o ${OBJECTDIR}/SK32MX795F512L_V16.o SK32MX795F512L_V16.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Mc32gestSPI_FT800.o: Mc32gestSPI_FT800.c  .generated_files/flags/default/d93eda64a9f120f3f31c900f802b0b38d490e8c3 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Mc32gestSPI_FT800.o.d 
	@${RM} ${OBJECTDIR}/Mc32gestSPI_FT800.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Mc32gestSPI_FT800.o.d" -o ${OBJECTDIR}/Mc32gestSPI_FT800.o Mc32gestSPI_FT800.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/TestFT800_TouchScreen.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -g -mdebugger -D__MPLAB_DEBUGGER_ICD3=1 -mprocessor=$(MP_PROCESSOR_OPTION)  -o ${DISTDIR}/TestFT800_TouchScreen.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)   -mreserve=data@0x0:0x1FC -mreserve=boot@0x1FC02000:0x1FC02FEF -mreserve=boot@0x1FC02000:0x1FC024FF  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D=__DEBUG_D,--defsym=__MPLAB_DEBUGGER_ICD3=1,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,${DISTDIR}/memoryfile.xml -mdfp="${DFP_DIR}"
	
else
${DISTDIR}/TestFT800_TouchScreen.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION)  -o ${DISTDIR}/TestFT800_TouchScreen.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,${DISTDIR}/memoryfile.xml -mdfp="${DFP_DIR}"
	${MP_CC_DIR}\\xc32-bin2hex ${DISTDIR}/TestFT800_TouchScreen.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(wildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
