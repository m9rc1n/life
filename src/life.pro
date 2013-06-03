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
    client/client.cpp \
    common/Predator.cpp \
    common/MapObject.cpp \
    common/Map.cpp \
    common/Herbivore.cpp \
    common/Creature.cpp \
    init/init.cpp \
    server/server.cpp \
    common/Visitor.cpp \
    common/Waterhole.cpp \
    common/Tree.cpp \
    common/Lair.cpp \
    init/init_ui.cpp \
    client/client_ui.cpp \
    client/StatisticsVisitor.cpp \
    client/PaintingVisitor.cpp \
    common/MaslovPyramid.cpp \
    common/GeneticEquation.cpp \
    server/SimulationVisitor.cpp \
    server/InternalSimulationVisitor.cpp \
    server/AwarenessDetector.cpp \
    server/MapGenerator.cpp \
    server/actions/Action.cpp \
    server/actions/EatingAction.cpp \
    server/actions/RunningAction.cpp \
    server/actions/DrinkingAction.cpp \
    server/actions/SleepingAction.cpp \
    server/actions/HuntingAction.cpp \
    server/actions/ProcreatingAction.cpp \
    server/ActionPerformVisitor.cpp \
    client/Statistics.cpp \
    server/genetics/Genetics.cpp \
    server/genetics/Genome.cpp

HEADERS  += \
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
    init/init_ui.hpp \
    client/client_ui.hpp \
    client/PaintingVisitor.hpp \
    client/StatisticsVisitor.hpp \
    common/MaslovPyramid.hpp \
    common/GeneticEquation.hpp \
    server/genetics/Genome.hpp \
    server/SimulationVisitor.hpp \
    server/InternalSimulationVisitor.hpp \
    server/AwarenessDetector.hpp \
    server/MapGenerator.hpp \
    server/actions/Action.hpp \
    server/actions/EatingAction.hpp \
    server/actions/RunningAction.hpp \
    server/actions/DrinkingAction.hpp \
    server/actions/SleepingAction.hpp \
    server/actions/HuntingAction.hpp \
    server/actions/ProcreatingAction.hpp \
    server/ActionPerformVisitor.hpp \
    client/Statistics.hpp \
    server/genetics/Genetics.hpp

OTHER_FILES += \
    makefile \
    life.pro.user \
    client/makefile \
    common/makefile \
    init/makefile \
    server/makefile


FORMS += \
    init/init_ui.ui \
    client/client_ui.ui \


QMAKE_CXXFLAGS += -std=c++11

LIBS += -lboost_system -lboost_thread -lboost_serialization -lm
