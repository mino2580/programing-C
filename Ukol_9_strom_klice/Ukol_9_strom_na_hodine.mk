##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Ukol_9_strom_na_hodine
ConfigurationName      :=Debug
WorkspacePath          :="D:/1rocnik Letny/Disk Google 1/codeline/codeline/Skola_ukoly"
ProjectPath            :="D:/1rocnik Letny/Disk Google 1/codeline/codeline/Skola_ukoly/Ukol_9_strom_na_hodine"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Mino
Date                   :=10.06.2019
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
ObjectsFileList        :="Ukol_9_strom_na_hodine.txt"
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
CodeLiteDir:=C:\Users\Mino\Downloads\CodeLite\CodeLite
Objects0=$(IntermediateDirectory)/data.c$(ObjectSuffix) $(IntermediateDirectory)/tree.c$(ObjectSuffix) $(IntermediateDirectory)/ioutils.c$(ObjectSuffix) $(IntermediateDirectory)/mymalloc.c$(ObjectSuffix) $(IntermediateDirectory)/main.c$(ObjectSuffix) 



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
$(IntermediateDirectory)/data.c$(ObjectSuffix): data.c $(IntermediateDirectory)/data.c$(DependSuffix)
	$(CC) $(SourceSwitch) "D:/1rocnik Letny/Disk Google 1/codeline/codeline/Skola_ukoly/Ukol_9_strom_na_hodine/data.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/data.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/data.c$(DependSuffix): data.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/data.c$(ObjectSuffix) -MF$(IntermediateDirectory)/data.c$(DependSuffix) -MM data.c

$(IntermediateDirectory)/data.c$(PreprocessSuffix): data.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/data.c$(PreprocessSuffix) data.c

$(IntermediateDirectory)/tree.c$(ObjectSuffix): tree.c $(IntermediateDirectory)/tree.c$(DependSuffix)
	$(CC) $(SourceSwitch) "D:/1rocnik Letny/Disk Google 1/codeline/codeline/Skola_ukoly/Ukol_9_strom_na_hodine/tree.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/tree.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/tree.c$(DependSuffix): tree.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/tree.c$(ObjectSuffix) -MF$(IntermediateDirectory)/tree.c$(DependSuffix) -MM tree.c

$(IntermediateDirectory)/tree.c$(PreprocessSuffix): tree.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/tree.c$(PreprocessSuffix) tree.c

$(IntermediateDirectory)/ioutils.c$(ObjectSuffix): ioutils.c $(IntermediateDirectory)/ioutils.c$(DependSuffix)
	$(CC) $(SourceSwitch) "D:/1rocnik Letny/Disk Google 1/codeline/codeline/Skola_ukoly/Ukol_9_strom_na_hodine/ioutils.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ioutils.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ioutils.c$(DependSuffix): ioutils.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ioutils.c$(ObjectSuffix) -MF$(IntermediateDirectory)/ioutils.c$(DependSuffix) -MM ioutils.c

$(IntermediateDirectory)/ioutils.c$(PreprocessSuffix): ioutils.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ioutils.c$(PreprocessSuffix) ioutils.c

$(IntermediateDirectory)/mymalloc.c$(ObjectSuffix): mymalloc.c $(IntermediateDirectory)/mymalloc.c$(DependSuffix)
	$(CC) $(SourceSwitch) "D:/1rocnik Letny/Disk Google 1/codeline/codeline/Skola_ukoly/Ukol_9_strom_na_hodine/mymalloc.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/mymalloc.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/mymalloc.c$(DependSuffix): mymalloc.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/mymalloc.c$(ObjectSuffix) -MF$(IntermediateDirectory)/mymalloc.c$(DependSuffix) -MM mymalloc.c

$(IntermediateDirectory)/mymalloc.c$(PreprocessSuffix): mymalloc.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/mymalloc.c$(PreprocessSuffix) mymalloc.c

$(IntermediateDirectory)/main.c$(ObjectSuffix): main.c $(IntermediateDirectory)/main.c$(DependSuffix)
	$(CC) $(SourceSwitch) "D:/1rocnik Letny/Disk Google 1/codeline/codeline/Skola_ukoly/Ukol_9_strom_na_hodine/main.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.c$(DependSuffix): main.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.c$(ObjectSuffix) -MF$(IntermediateDirectory)/main.c$(DependSuffix) -MM main.c

$(IntermediateDirectory)/main.c$(PreprocessSuffix): main.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.c$(PreprocessSuffix) main.c


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


