######################################################################
# Automatically generated by qmake (3.1) Sat Oct 22 02:59:37 2022
######################################################################

TEMPLATE = app
TARGET = qt_troll
INCLUDEPATH += .
QT += widgets

# The following define makes your compiler warn you if you use any
# feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS
DEFINES += QT_IS_AVAILABLE
CONFIG += QT_IS_AVAILABLE
QMAKE_CXXFLAGS += -pthread
LIBS += -pthread -L../QtTrollLib/ -lQtTrollLib
#DEFINES += MAKE_TEST_LIB
# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Input
HEADERS += ../QtTrollLib/qt_troll.h
SOURCES += main.cpp
