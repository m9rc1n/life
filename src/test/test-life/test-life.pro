#-------------------------------------------------
#
# Project created by QtCreator 2013-06-02T17:23:10
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

TARGET = tst_lifetest
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += tst_lifetest.cpp \
    ../../server/AwarenessDetector.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"
