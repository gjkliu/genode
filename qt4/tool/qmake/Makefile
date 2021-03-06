#
# \brief  Makefile for building QMake for Genode
# \author Christian Prochaska
# \author Norman Feske
# \date   2009-05-12
#
# This file is based on the generated Makefile created by qt4's configure.
#

CC_1 =  gcc
CC = $(CC_1)
CXX_1 =  g++
CXX = $(CXX_1)
QMAKE_CFLAGS_1 = -pipe
QMAKE_CFLAGS = $(QMAKE_CFLAGS_1) $(QMAKE_CFLAGS_2)
QMAKE_CXXFLAGS_1 = $(QMAKE_CFLAGS)
QMAKE_CXXFLAGS = $(QMAKE_CXXFLAGS_1) $(QMAKE_CXXFLAGS_2)
QMAKE_LFLAGS_1 = 
QMAKE_LFLAGS = $(QMAKE_LFLAGS_1)

# Genode repository
REP_DIR := ../..

include $(REP_DIR)/lib/mk/qt_version.inc

# root of Qt4 source tree
CONTRIB_DIR := $(REP_DIR)/contrib/$(QT4)

# tell make where to look for source codes
vpath %.h   $(CONTRIB_DIR)/qmake
vpath %.cpp $(CONTRIB_DIR)/qmake
vpath %.cpp $(CONTRIB_DIR)/qmake/generators
vpath %.cpp $(CONTRIB_DIR)/qmake/generators/mac
vpath %.cpp $(CONTRIB_DIR)/qmake/generators/unix
vpath %.cpp $(CONTRIB_DIR)/qmake/generators/win32
vpath %.cpp $(CONTRIB_DIR)/qmake/generators/symbian
vpath %.cpp $(CONTRIB_DIR)/src/corelib/codecs
vpath %.cpp $(CONTRIB_DIR)/src/corelib/tools
vpath %.cpp $(CONTRIB_DIR)/src/corelib/global
vpath %.cpp $(CONTRIB_DIR)/src/corelib/kernel
vpath %.cpp $(CONTRIB_DIR)/src/corelib/plugin
vpath %.cpp $(CONTRIB_DIR)/src/corelib/io
vpath %.cpp $(CONTRIB_DIR)/src/corelib/xml
vpath %.cpp $(CONTRIB_DIR)/tools/shared/symbian
vpath %.cpp $(CONTRIB_DIR)/tools/shared/windows

SOURCE_PATH = $(CONTRIB_DIR)
BUILD_PATH = .
QCONFIG_CPP_PATH = ../../../../src/lib/qt4/src/corelib/global
QTOBJS = 
QTSRCS = 
+QMAKESPEC = ../../src/lib/qt4/mkspecs/qws/genode-x86-g++
LFLAGS = $(QMAKE_LFLAGS)

#qmake code
OBJS=project.o property.o main.o makefile.o unixmake2.o unixmake.o  \
     mingw_make.o option.o winmakefile.o projectgenerator.o \
     meta.o makefiledeps.o metamakefile.o xmloutput.o pbuilder_pbx.o \
     borland_bmake.o msvc_vcproj.o msvc_vcxproj.o msvc_nmake.o msvc_objectmodel.o msbuild_objectmodel.o \
     symmake.o initprojectdeploy_symbian.o symmake_abld.o symmake_sbsv2.o \
     symbiancommon.o registry.o epocroot.o

#qt code
QOBJS=qtextcodec.o qutfcodec.o qstring.o qtextstream.o qiodevice.o qmalloc.o qglobal.o \
      qbytearray.o qbytearraymatcher.o qdatastream.o qbuffer.o qlist.o qfile.o \
      qfsfileengine_unix.o qfsfileengine_iterator_unix.o qfsfileengine.o \
      qfsfileengine_iterator.o qregexp.o qvector.o qbitarray.o qdir.o qdiriterator.o quuid.o qhash.o \
      qfileinfo.o qdatetime.o qstringlist.o qabstractfileengine.o qtemporaryfile.o \
      qmap.o qmetatype.o qsettings.o qlibraryinfo.o qvariant.o qvsnprintf.o \
      qlocale.o qlinkedlist.o qurl.o qnumeric.o qcryptographichash.o qxmlstream.o qxmlutils.o \
      $(QTOBJS)




#all sources, used for the depend target
DEPEND_SRC=project.cpp property.cpp meta.cpp main.cpp generators/makefile.cpp generators/unix/unixmake2.cpp \
	   generators/unix/unixmake.cpp generators/win32/winmakefile.cpp generators/projectgenerator.cpp \
	   generators/mac/pbuilder_pbx.cpp generators/mac/xmloutput.cpp generators/metamakefile.cpp \
	   generators/makefiledeps.cpp option.cpp generators/win32/mingw_make.cpp generators/makefile.cpp \
	   generators/win32/msvc_vcproj.cpp generators/win32/msvc_vcxproj.cpp generators/win32/msvc_objectmodel.cpp generators/win32/msbuild_objectmodel.cpp generators/win32/msbuild_objectmodel.cpp generators/win32/msvc_nmake.cpp generators/win32/borland_bmake.cpp \
	   generators/symbian/symmake.cpp generators/symbian/initprojectdeploy_symbian.cpp \
	   $(SOURCE_PATH)/tools/shared/windows/registry.cpp \
	   $(SOURCE_PATH)/tools/shared/symbian/epocroot.cpp \
	   generators/symbian/symmake_abld.cpp generators/symbian/symmake_sbsv2.cpp \
           generaters/symbian/symbiancommon.cpp \
	   $(SOURCE_PATH)/src/corelib/codecs/qtextcodec.cpp $(SOURCE_PATH)/src/corelib/codecs/qutfcodec.cpp \
	   $(SOURCE_PATH)/src/corelib/tools/qstring.cpp $(SOURCE_PATH)/src/corelib/io/qfile.cpp \
	   $(SOURCE_PATH)/src/corelib/io/qtextstream.cpp $(SOURCE_PATH)/src/corelib/io/qiodevice.cpp \
	   $(SOURCE_PATH)/src/corelib/global/qmalloc.cpp \
	   $(SOURCE_PATH)/src/corelib/global/qglobal.cpp $(SOURCE_PATH)/src/corelib/tools/qregexp.cpp \
	   $(SOURCE_PATH)/src/corelib/tools/qbytearray.cpp $(SOURCE_PATH)/src/corelib/tools/qbytearraymatcher.cpp \
	   $(SOURCE_PATH)/src/corelib/io/qdatastream.cpp $(SOURCE_PATH)/src/corelib/io/qbuffer.cpp \
	   $(SOURCE_PATH)/src/corelib/io/qfsfileengine_unix.cpp $(SOURCE_PATH)/src/corelib/io/qabstractfileengine.cpp \
	   $(SOURCE_PATH)/src/corelib/io/qfsfileengine_iterator_unix.cpp $(SOURCE_PATH)/src/corelib/io/qfsfileengine_iterator.cpp \
	   $(SOURCE_PATH)/src/corelib/io/qfsfileengine.cpp $(SOURCE_PATH)/src/corelib/tools/qlist.cpp \
	   $(SOURCE_PATH)/src/corelib/tools/qvector.cpp $(SOURCE_PATH)/src/corelib/tools/qbitarray.cpp \
	   $(SOURCE_PATH)/src/corelib/io/qdiriterator.cpp \
	   $(SOURCE_PATH)/src/corelib/io/qdir.cpp $(SOURCE_PATH)/src/corelib/plugin/quuid.cpp \
	   $(SOURCE_PATH)/src/corelib/io/qfileinfo.cpp $(SOURCE_PATH)/src/corelib/tools/qdatetime.cpp \
	   $(SOURCE_PATH)/src/corelib/tools/qstringlist.cpp $(SOURCE_PATH)/src/corelib/tools/qmap.cpp \
	   $(SOURCE_PATH)/src/corelib/global/qconfig.cpp $(SOURCE_PATH)/src/corelib/io/qurl.cpp \
	   $(SOURCE_PATH)/src/corelib/tools/qlocale.cpp $(SOURCE_PATH)/src/corelib/tools/qlinkedlist.cpp \
	   $(SOURCE_PATH)/src/corelib/tools/qhash.cpp $(SOURCE_PATH)/src/corelib/kernel/qcore_mac.cpp \
	   $(SOURCE_PATH)/src/corelib/io/qtemporaryfile.cpp $(SOURCE_PATH)/src/corelib/kernel/qmetatype.cpp \
	   $(SOURCE_PATH)/src/corelib/io/qsettings.cpp $(SOURCE_PATH)/src/corelib/kernel/qvariant.cpp \
	   $(SOURCE_PATH)/src/corelib/global/qlibraryinfo.cpp $(SOURCE_PATH)/src/corelib/tools/qcryptographichash.cpp \
	   $(SOURCE_PATH)/src/corelib/tools/qvsnprintf.cpp $(SOURCE_PATH)/src/corelib/global/qnumeric.cpp \
	   $(SOURCE_PATH)/src/corelib/xml/qxmlstream.cpp \
	   $(SOURCE_PATH)/src/corelib/xml/qxmlutils.cpp \
	   $(QTSRCS)

CPPFLAGS = -I. -Igenerators -Igenerators/unix -Igenerators/win32 -Igenerators/mac -Igenerators/symbian \
	   -I$(BUILD_PATH)/include -I$(BUILD_PATH)/include/QtCore \
	   -I$(REP_DIR)/include/qt4 -I$(REP_DIR)/include/qt4/QtCore \
	   -I$(SOURCE_PATH)/include -I$(SOURCE_PATH)/include/QtCore \
	   -I$(BUILD_PATH)/src/corelib/global -I$(BUILD_PATH)/src/corelib/xml \
	   -I$(SOURCE_PATH)/tools/shared \
	   -I$(QCONFIG_CPP_PATH) \
	   -DQT_NO_PCRE \
	   -DQT_BUILD_QMAKE -DQT_BOOTSTRAPPED \
	   -DQT_NO_TEXTCODEC -DQT_NO_UNICODETABLES -DQT_NO_COMPONENT -DQT_NO_STL \
	   -DQT_NO_COMPRESS -I$(QMAKESPEC) -DHAVE_QCONFIG_CPP -DQT_NO_THREAD -DQT_NO_QOBJECT \
           -DQT_NO_GEOM_VARIANT $(OPENSOURCE_CXXFLAGS)

# extensions of the CPPFLAGS needed for the out-of-tree build
CPPFLAGS += -I$(CONTRIB_DIR)/qmake
CPPFLAGS += $(addprefix -I$(CONTRIB_DIR)/qmake/, generators generators/symbian generators/unix generators/win32 generators/mac)
CPPFLAGS += -I$(REP_DIR)/src/lib/qt4/src/corelib/global

# enable automatic dependency generation
CPPFLAGS += -MMD

CXXFLAGS = $(QMAKE_CXXFLAGS) -DQMAKE_OPENSOURCE_EDITION $(CPPFLAGS)

first all: qmake

qmake: $(OBJS) $(QOBJS)
	$(CXX) -o "$@" $(OBJS) $(QOBJS) $(LFLAGS)

clean::
	rm -f qmake $(OBJS) $(QOBJS) $(OBJS:.o=.d) $(QOBJS:.o=.d)

distclean:: clean

-include *.d

#default rules
.cpp.o:
	$(CXX) -c -o $@ $(CXXFLAGS) $<

# DO NOT DELETE THIS LINE -- make depend depends on it
