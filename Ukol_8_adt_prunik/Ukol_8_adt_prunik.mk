##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Ukol_8_adt_prunik
ConfigurationName      :=Debug
WorkspacePath          :="C:/Users/milan/Disk Google/codeline/codeline/Skola_ukoly"
ProjectPath            :="C:/Users/milan/Disk Google/codeline/codeline/Skola_ukoly/Ukol_8_adt_prunik"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=milan
Date                   :=18.06.2019
CodeLitePath           :="C:/Program Files/CodeLite"
LinkerName             :=C:/TDM-GCC-64/bin/g++.exe
SharedObjectLinkerName :=C:/TDM-GCC-64/bin/g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="Ukol_8_adt_prunik.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=C:/TDM-GCC-64/bin/windres.exe
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := C:/TDM-GCC-64/bin/ar.exe rcu
CXX      := C:/TDM-GCC-64/bin/g++.exe
CC       := C:/TDM-GCC-64/bin/gcc.exe
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/TDM-GCC-64/bin/as.exe


##
## User defined environment variables
##
Objects0=$(IntermediateDirectory)/mymalloc.c$(ObjectSuffix) $(IntermediateDirectory)/list.c$(ObjectSuffix) $(IntermediateDirectory)/main.c$(ObjectSuffix) $(IntermediateDirectory)/ioutils.c$(ObjectSuffix) $(IntermediateDirectory)/data.c$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@$(MakeDirCommand) "./Debug"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/mymalloc.c$(ObjectSuffix): mymalloc.c $(IntermediateDirectory)/mymalloc.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/milan/Disk Google/codeline/codeline/Skola_ukoly/Ukol_8_adt_prunik/mymalloc.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/mymalloc.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/mymalloc.c$(DependSuffix): mymalloc.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/mymalloc.c$(ObjectSuffix) -MF$(IntermediateDirectory)/mymalloc.c$(DependSuffix) -MM mymalloc.c

$(IntermediateDirectory)/mymalloc.c$(PreprocessSuffix): mymalloc.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/mymalloc.c$(PreprocessSuffix) mymalloc.c

$(IntermediateDirectory)/list.c$(ObjectSuffix): list.c $(IntermediateDirectory)/list.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/milan/Disk Google/codeline/codeline/Skola_ukoly/Ukol_8_adt_prunik/list.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/list.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/list.c$(DependSuffix): list.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/list.c$(ObjectSuffix) -MF$(IntermediateDirectory)/list.c$(DependSuffix) -MM list.c

$(IntermediateDirectory)/list.c$(PreprocessSuffix): list.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/list.c$(PreprocessSuffix) list.c

$(IntermediateDirectory)/main.c$(ObjectSuffix): main.c $(IntermediateDirectory)/main.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/milan/Disk Google/codeline/codeline/Skola_ukoly/Ukol_8_adt_prunik/main.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.c$(DependSuffix): main.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.c$(ObjectSuffix) -MF$(IntermediateDirectory)/main.c$(DependSuffix) -MM main.c

$(IntermediateDirectory)/main.c$(PreprocessSuffix): main.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.c$(PreprocessSuffix) main.c

$(IntermediateDirectory)/ioutils.c$(ObjectSuffix): ioutils.c $(IntermediateDirectory)/ioutils.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/milan/Disk Google/codeline/codeline/Skola_ukoly/Ukol_8_adt_prunik/ioutils.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ioutils.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ioutils.c$(DependSuffix): ioutils.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ioutils.c$(ObjectSuffix) -MF$(IntermediateDirectory)/ioutils.c$(DependSuffix) -MM ioutils.c

$(IntermediateDirectory)/ioutils.c$(PreprocessSuffix): ioutils.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ioutils.c$(PreprocessSuffix) ioutils.c

$(IntermediateDirectory)/data.c$(ObjectSuffix): data.c $(IntermediateDirectory)/data.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/milan/Disk Google/codeline/codeline/Skola_ukoly/Ukol_8_adt_prunik/data.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/data.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/data.c$(DependSuffix): data.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/data.c$(ObjectSuffix) -MF$(IntermediateDirectory)/data.c$(DependSuffix) -MM data.c

$(IntermediateDirectory)/data.c$(PreprocessSuffix): data.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/data.c$(PreprocessSuffix) data.c


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


