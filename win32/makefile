# Make file for SciTE on Windows
# Copyright 1998-2010 by Neil Hodgson <neilh@scintilla.org>
# The License.txt file describes the conditions under which this software may be distributed.
# This makefile assumes the mingw32 version of GCC 4.x is used and changes will
# be needed to use other compilers.

.SUFFIXES: .cxx .properties
WINDRES ?= windres
ifeq (\,$(shell echo \\))
	SHELL_TYPE = sh
endif

ifdef CLANG
CXX = clang++
CC = clang
# Clang doesn't like omitting braces in array initialization but they just add noise,
# Microsoft headers are used so _CRT_SECURE_NO_DEPRECATE avoids warnings for standard library like strcat,
# public visibility avoids warnings like 'locally defined symbol __std_terminate imported'
CLANG_OPTS = -Wno-missing-braces -D_CRT_SECURE_NO_DEPRECATE=1 -Xclang -flto-visibility-public-std
CLANG_LIBS = -luser32 -lgdi32 -lshell32 -lcomdlg32
else
SUBSYSTEM_OPT = -Xlinker --subsystem -Xlinker windows
endif

ifeq ($(OS),Windows_NT)
	ifndef CLANG
		CC = gcc
	endif
	DEL = $(if $(wildcard $(dir $(SHELL))rm.exe), $(dir $(SHELL))rm.exe -f, del)
	COPY = $(if $(wildcard $(dir $(SHELL))cp.exe), $(dir $(SHELL))cp.exe -a, xcopy /Y)
	VER = cmd /c ver
	# Discover Windows version by running 'VER' command and parsing output
	# For Windows 2000 looks like:Microsoft Windows 2000 [Version 5.00.2195]
	WINVERWORDS:=$(wordlist 1,2,$(subst ., ,$(lastword $(shell $(VER)))))
	WINVER:=$(firstword $(WINVERWORDS)).$(lastword $(WINVERWORDS))
	# Windows NT 4 and Windows 2000 do not support themes so turn off
ifeq '$(WINVER)' '4.0'
	VERSION_DEFINES:=-DDISABLE_THEMES -DWIN_TARGET=0x0400
else
ifeq '$(WINVER)' '5.00'
	VERSION_DEFINES:=-DDISABLE_THEMES
else
	UXLIB:=-luxtheme
endif
endif
else
	DEL = rm -f
	COPY = cp -a
	UXLIB:=-luxtheme
endif

PROG	= ../bin/SciTE.exe
PROGSTATIC = ../bin/Sc1.exe
WIDEFLAGS=-DUNICODE -D_UNICODE

vpath %.h ../src ../../scintilla/include
vpath %.cxx ../src
vpath %.a ../../scintilla/bin

ifndef NO_LUA
LUA_CORE_OBJS = lapi.o lcode.o lctype.o ldebug.o ldo.o ldump.o lfunc.o lgc.o llex.o \
		lmem.o lobject.o lopcodes.o lparser.o lstate.o lstring.o \
		ltable.o ltm.o lundump.o lvm.o lzio.o

LUA_LIB_OBJS =	lauxlib.o lbaselib.o lbitlib.o lcorolib.o ldblib.o liolib.o lmathlib.o ltablib.o \
		lstrlib.o loadlib.o loslib.o linit.o lutf8lib.o

LUA_OBJS = LuaExtension.o $(LUA_CORE_OBJS) $(LUA_LIB_OBJS)

vpath %.c ../lua/src ../lua/src/lib

LUA_INCLUDES = -I ../lua/src
#LUA_SCRIPTS = ..\bin\SciTEExtension.lua ..\bin\SciTEStartup.lua
LUA_DEFINES = -DLUA_USER_H=\"scite_lua_win.h\"
else
LUA_DEFINES = -DNO_LUA
endif

INCLUDEDIRS=-I ../../scintilla/include -I ../src $(LUA_INCLUDES)
RCINCLUDEDIRS=--include-dir ../src

CBASEFLAGS = -Wall $(INCLUDEDIRS) $(LUA_DEFINES) $(WIDEFLAGS) $(VERSION_DEFINES) $(CLANG_OPTS)

ifdef DEBUG
CFLAGS=-DDEBUG -g $(CBASEFLAGS)
else
CFLAGS=-DNDEBUG -Os $(CBASEFLAGS)
ifndef CLANG
STRIPFLAG="-Wl,-s"
endif
endif

CXXFLAGS = $(CFLAGS) -pedantic --std=c++17

LDFLAGS=-mwindows $(CLANG_LIBS) -lmsimg32 -lcomctl32 -limm32 -lole32 -luuid -loleaut32 $(UXLIB) $(LUA_LDFLAGS)

.cxx.o:
	$(CXX) $(CXXFLAGS) -c $< -o $@

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

SHAREDOBJS=\
	Cookie.o \
	DirectorExtension.o \
	EditorConfig.o \
	ExportHTML.o \
	ExportPDF.o \
	ExportRTF.o \
	ExportTEX.o \
	ExportXML.o \
	FilePath.o \
	FileWorker.o \
	GUIWin.o \
	IFaceTable.o \
	JobQueue.o \
	MatchMarker.o \
	MultiplexExtension.o \
	PropSetFile.o \
	ScintillaWindow.o \
	SciTEBase.o \
	SciTEBuffers.o \
	SciTEIO.o \
	SciTEProps.o \
	SciTEWinBar.o \
	SciTEWinDlg.o \
	StringHelpers.o \
	StringList.o \
	Strips.o \
	StyleDefinition.o \
	StyleWriter.o \
	UniqueInstance.o \
	Utf8_16.o \
	WinMutex.o

OTHER_OBJS = $(SHAREDOBJS) $(LUA_OBJS) SciTERes.o SciTEWin.o

OBJS = Credits.o $(OTHER_OBJS)

DLLS=../bin/Scintilla.dll ../bin/SciLexer.dll

NOTBINPROPS=SciTE.properties Embedded.properties
PROPS=$(addprefix ../bin/,$(filter-out $(NOTBINPROPS), $(notdir $(wildcard ../src/*.properties))))

ALL:	$(PROG) $(PROGSTATIC) $(DLLS) $(PROPS) $(LUA_SCRIPTS)

clean:
	$(DEL) *.exe *.o *.obj *.dll *.res *.map *.plist

analyze:
	clang --analyze $(CXXFLAGS) *.cxx ../src/*.cxx

deps:
	$(CXX) -MM $(CXXFLAGS) *.cxx ../src/*.cxx ../lua/src/*.c >deps.mak

../bin/%.dll:	../../scintilla/bin/%.dll
ifneq (sh,$(SHELL_TYPE))
	$(COPY) $(subst /,\, $< $(@D))
else
	$(COPY) $^ $(@D)
endif

# Using '/' rather than '\' as that allows make to match the next rule
../bin/%.properties:	../src/%.properties
ifneq (sh,$(SHELL_TYPE))
	$(COPY) $(subst /,\, $< $(@D))
else
	$(COPY) $^ $(@D)
endif

$(PROG): $(OBJS)
	$(CXX) $(STRIPFLAG) $(SUBSYSTEM_OPT) -o  $@ $^ $(LDFLAGS)

OBJSSTATIC = \
	$(SHAREDOBJS) \
	Credits.o \
	Sc1.o \
	Sc1Res.o \
	libscintilla.a \
	$(LUA_OBJS)

$(PROGSTATIC): $(OBJSSTATIC)
	$(CXX) $(STRIPFLAG) $(SUBSYSTEM_OPT) -static -o $@ $^ $(LDFLAGS)

# Automatically generate dependencies for most files with "make deps"
include deps.mak

Sc1.o: SciTEWin.cxx SciTEWin.h SciTE.h PropSetFile.h \
 Scintilla.h Extender.h FilePath.h SciTEBase.h FileWorker.h JobQueue.h
	$(CXX) $(CXXFLAGS) -D STATIC_BUILD -c $< -o $@

SciTERes.o:	SciTERes.rc SciTE.h SciTE.exe.manifest
	$(WINDRES) $(RCINCLUDEDIRS) SciTERes.rc $@

# Also depends on ../src/Embedded.properties but may not want to build everywhere
# so must explicitly ask to build it.
Sc1Res.o:	SciTERes.rc SciTE.h SciTE.exe.manifest
	$(WINDRES) $(RCINCLUDEDIRS) SciTERes.rc --define STATIC_BUILD $@

# Make sure Credits gets rebuilt (so its about box gets a new
# date stamp) when any of the other objects are updated.
Credits.o: $(OTHER_OBJS)
