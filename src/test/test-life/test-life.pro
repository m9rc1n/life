#-------------------------------------------------
#
# Project created by QtCreator 2013-06-02T17:23:10
#
#-------------------------------------------------

QT       += testlib
QT       += core
QT       += widgets
QT       += gui

TARGET = tst_lifetest

TEMPLATE = app


SOURCES += tst_lifetest.cpp \
    ../../server/AwarenessDetector.cpp \
    ../../server/genetics/Genotype.cpp \
    ../AllocationCounter.cpp \
    ../../common/Waterhole.cpp \
    ../../common/Visitor.cpp \
    ../../common/Tree.cpp \
    ../../common/Predator.cpp \
    ../../common/MaslovPyramid.cpp \
    ../../common/MapObject.cpp \
    ../../common/Map.cpp \
    ../../common/Lair.cpp \
    ../../common/Herbivore.cpp \
    ../../common/GeneticEquation.cpp \
    ../../common/Creature.cpp \
    ../../server/genetics/Genetics.cpp \
    ../../server/actions/SleepingAction.cpp \
    ../../server/actions/RunningAction.cpp \
    ../../server/actions/ProcreatingAction.cpp \
    ../../server/actions/HuntingAction.cpp \
    ../../server/actions/EatingAction.cpp \
    ../../server/actions/DrinkingAction.cpp \
    ../../server/actions/Action.cpp \
    ../../server/SimulationVisitor.cpp \
    ../../server/MapGenerator.cpp \
    ../../server/InternalSimulationVisitor.cpp \
    ../../server/ActionPerformVisitor.cpp \
    ../../server/server.cpp \
    ../../client/StatisticsSumVisitor.cpp \
    ../../client/StatisticsAverageVisitor.cpp \
    ../../client/Statistics.cpp \
    ../../client/PaintingVisitor.cpp \
    ../../client/client.cpp \
    ../../client/client_ui.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

QMAKE_CXXFLAGS += -std=c++11

HEADERS += \
    ../AllocationCounter.hpp \
    ../../common/Waterhole.hpp \
    ../../common/Visitor.hpp \
    ../../common/Tree.hpp \
    ../../common/Predator.hpp \
    ../../common/MaslovPyramid.hpp \
    ../../common/MapObject.hpp \
    ../../common/Map.hpp \
    ../../common/Lair.hpp \
    ../../common/Herbivore.hpp \
    ../../common/GeneticEquation.hpp \
    ../../common/Creature.hpp \
    ../../common/Config.hpp \
    ../../server/genetics/Genotype.hpp \
    ../../server/genetics/Genetics.hpp \
    ../../server/actions/SleepingAction.hpp \
    ../../server/actions/RunningAction.hpp \
    ../../server/actions/ProcreatingAction.hpp \
    ../../server/actions/HuntingAction.hpp \
    ../../server/actions/EatingAction.hpp \
    ../../server/actions/DrinkingAction.hpp \
    ../../server/actions/Action.hpp \
    ../../server/server.hpp \
    ../../server/SimulationVisitor.hpp \
    ../../server/MapGenerator.hpp \
    ../../server/InternalSimulationVisitor.hpp \
    ../../server/AwarenessDetector.hpp \
    ../../server/ActionPerformVisitor.hpp \
    ../../client/StatisticsSumVisitor.hpp \
    ../../client/StatisticsAverageVisitor.hpp \
    ../../client/Statistics.hpp \
    ../../client/PaintingVisitor.hpp \
    ../../client/PaintingVisitor.cpp.orig \
    ../../client/Map.hpp~ \
    ../../client/client.hpp \
    ../../client/client_ui.hpp

OTHER_FILES += \
    ../../common/makefile \
    ../../server/Map.hpp~ \
    ../../server/makefile \
    ../../client/Map.cpp~ \
    ../../client/makefile

FORMS += \
    ../../client/client_ui.ui
