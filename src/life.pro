#-------------------------------------------------
#
# Project created by QtCreator 2013-05-25T21:45:31
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = life
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    client/client.cpp \
    common/Predator.cpp \
    common/MapObject.cpp \
    common/Map.cpp \
    common/Herbivore.cpp \
    common/Creature.cpp \
    init/init.cpp \
    server/server.cpp

HEADERS  += mainwindow.hpp \
    include.hpp \
    client/drawingQT.hpp \
    client/drawingAPI.hpp \
    client/client.hpp \
    common/Waterhole.hpp \
    common/Visitor.hpp \
    common/Tree.hpp \
    common/Predator.hpp \
    common/MapObject.hpp \
    common/Map.hpp \
    common/Lair.hpp \
    common/Herbivore.hpp \
    common/Creature.hpp \
    common/Config.hpp \
    init/init.hpp \
    server/server.hpp \
    server/Map.hpp

OTHER_FILES += \
    makefile \
    life.pro.user \
    client/makefile \
    common/makefile \
    init/makefile \
    server/makefile

QMAKE_CXXFLAGS += -std=c++11

LIBS += -lboost_system -lboost_filesystem -lboost_asio
