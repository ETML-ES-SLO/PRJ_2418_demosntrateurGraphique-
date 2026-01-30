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
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/TestFT800_TouchScreen.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/TestFT800_TouchScreen.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
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
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/TestFT800_TouchScreen.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

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
${OBJECTDIR}/Main_ExSpiLm70.o: Main_ExSpiLm70.c  .generated_files/flags/default/cb2f5db3087e6be0aaa531f2f6fb850be44d2c36 .generated_files/flags/default/9482caba2dc1e17ca639a65609d3577e06590893
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Main_ExSpiLm70.o.d 
	@${RM} ${OBJECTDIR}/Main_ExSpiLm70.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Main_ExSpiLm70.o.d" -o ${OBJECTDIR}/Main_ExSpiLm70.o Main_ExSpiLm70.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Mc32Delays.o: Mc32Delays.c  .generated_files/flags/default/d61fc3851e98fa8aae0ff6a098b27fb634d2c613 .generated_files/flags/default/9482caba2dc1e17ca639a65609d3577e06590893
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Mc32Delays.o.d 
	@${RM} ${OBJECTDIR}/Mc32Delays.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Mc32Delays.o.d" -o ${OBJECTDIR}/Mc32Delays.o Mc32Delays.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Mc32SpiUtil.o: Mc32SpiUtil.c  .generated_files/flags/default/bd227b82185af14c85766a9c0f16acbbaa2d0538 .generated_files/flags/default/9482caba2dc1e17ca639a65609d3577e06590893
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Mc32SpiUtil.o.d 
	@${RM} ${OBJECTDIR}/Mc32SpiUtil.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Mc32SpiUtil.o.d" -o ${OBJECTDIR}/Mc32SpiUtil.o Mc32SpiUtil.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Mc32gestSPiDac.o: Mc32gestSPiDac.c  .generated_files/flags/default/422032b43189c22d5b65c9249bb1855e97aebfd5 .generated_files/flags/default/9482caba2dc1e17ca639a65609d3577e06590893
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Mc32gestSPiDac.o.d 
	@${RM} ${OBJECTDIR}/Mc32gestSPiDac.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Mc32gestSPiDac.o.d" -o ${OBJECTDIR}/Mc32gestSPiDac.o Mc32gestSPiDac.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Mc32gestSPiLM70.o: Mc32gestSPiLM70.c  .generated_files/flags/default/4653b17e479b1b9217cd196f01feda852f272984 .generated_files/flags/default/9482caba2dc1e17ca639a65609d3577e06590893
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Mc32gestSPiLM70.o.d 
	@${RM} ${OBJECTDIR}/Mc32gestSPiLM70.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Mc32gestSPiLM70.o.d" -o ${OBJECTDIR}/Mc32gestSPiLM70.o Mc32gestSPiLM70.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/SK32MX795F512L_V16.o: SK32MX795F512L_V16.c  .generated_files/flags/default/b4a2cb5cd32d5baf4725cd944e8b6266caabffbe .generated_files/flags/default/9482caba2dc1e17ca639a65609d3577e06590893
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/SK32MX795F512L_V16.o.d 
	@${RM} ${OBJECTDIR}/SK32MX795F512L_V16.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/SK32MX795F512L_V16.o.d" -o ${OBJECTDIR}/SK32MX795F512L_V16.o SK32MX795F512L_V16.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Mc32gestSPI_FT800.o: Mc32gestSPI_FT800.c  .generated_files/flags/default/e6233ccd46eb4f73fd9026accec966c180621cc5 .generated_files/flags/default/9482caba2dc1e17ca639a65609d3577e06590893
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Mc32gestSPI_FT800.o.d 
	@${RM} ${OBJECTDIR}/Mc32gestSPI_FT800.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Mc32gestSPI_FT800.o.d" -o ${OBJECTDIR}/Mc32gestSPI_FT800.o Mc32gestSPI_FT800.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
else
${OBJECTDIR}/Main_ExSpiLm70.o: Main_ExSpiLm70.c  .generated_files/flags/default/e58cc802a55d2544c4e2f9b943a24fc40c4eaf29 .generated_files/flags/default/9482caba2dc1e17ca639a65609d3577e06590893
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Main_ExSpiLm70.o.d 
	@${RM} ${OBJECTDIR}/Main_ExSpiLm70.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Main_ExSpiLm70.o.d" -o ${OBJECTDIR}/Main_ExSpiLm70.o Main_ExSpiLm70.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Mc32Delays.o: Mc32Delays.c  .generated_files/flags/default/ff47bf0347445297e95ed93c9045d2b5219fde0 .generated_files/flags/default/9482caba2dc1e17ca639a65609d3577e06590893
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Mc32Delays.o.d 
	@${RM} ${OBJECTDIR}/Mc32Delays.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Mc32Delays.o.d" -o ${OBJECTDIR}/Mc32Delays.o Mc32Delays.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Mc32SpiUtil.o: Mc32SpiUtil.c  .generated_files/flags/default/afbc3aee8988b76c80117389a99212becf407626 .generated_files/flags/default/9482caba2dc1e17ca639a65609d3577e06590893
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Mc32SpiUtil.o.d 
	@${RM} ${OBJECTDIR}/Mc32SpiUtil.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Mc32SpiUtil.o.d" -o ${OBJECTDIR}/Mc32SpiUtil.o Mc32SpiUtil.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Mc32gestSPiDac.o: Mc32gestSPiDac.c  .generated_files/flags/default/524c45e10d8fd000c555200e399e264d68fe0729 .generated_files/flags/default/9482caba2dc1e17ca639a65609d3577e06590893
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Mc32gestSPiDac.o.d 
	@${RM} ${OBJECTDIR}/Mc32gestSPiDac.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Mc32gestSPiDac.o.d" -o ${OBJECTDIR}/Mc32gestSPiDac.o Mc32gestSPiDac.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Mc32gestSPiLM70.o: Mc32gestSPiLM70.c  .generated_files/flags/default/9322c87040108f16b91e31398194d8349fe28b45 .generated_files/flags/default/9482caba2dc1e17ca639a65609d3577e06590893
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Mc32gestSPiLM70.o.d 
	@${RM} ${OBJECTDIR}/Mc32gestSPiLM70.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Mc32gestSPiLM70.o.d" -o ${OBJECTDIR}/Mc32gestSPiLM70.o Mc32gestSPiLM70.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/SK32MX795F512L_V16.o: SK32MX795F512L_V16.c  .generated_files/flags/default/c860d2994d3288020d10e0bf1e9875567767dd7a .generated_files/flags/default/9482caba2dc1e17ca639a65609d3577e06590893
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/SK32MX795F512L_V16.o.d 
	@${RM} ${OBJECTDIR}/SK32MX795F512L_V16.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/SK32MX795F512L_V16.o.d" -o ${OBJECTDIR}/SK32MX795F512L_V16.o SK32MX795F512L_V16.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Mc32gestSPI_FT800.o: Mc32gestSPI_FT800.c  .generated_files/flags/default/9f89bd08504c770bc55f3eba6956e8c9979f660e .generated_files/flags/default/9482caba2dc1e17ca639a65609d3577e06590893
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
dist/${CND_CONF}/${IMAGE_TYPE}/TestFT800_TouchScreen.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -g -mdebugger -D__MPLAB_DEBUGGER_ICD3=1 -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/TestFT800_TouchScreen.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)   -mreserve=data@0x0:0x1FC -mreserve=boot@0x1FC02000:0x1FC02FEF -mreserve=boot@0x1FC02000:0x1FC024FF  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D=__DEBUG_D,--defsym=__MPLAB_DEBUGGER_ICD3=1,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -mdfp="${DFP_DIR}"
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/TestFT800_TouchScreen.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/TestFT800_TouchScreen.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -mdfp="${DFP_DIR}"
	${MP_CC_DIR}\\xc32-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/TestFT800_TouchScreen.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
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
