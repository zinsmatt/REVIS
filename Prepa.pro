TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp StudentManager.cpp \
    human.cpp \
    student.cpp \
    arraylist.cpp
HEADERS += StudentManager.h \
    human.h \
    student.h \
    arraylist.h

include(deployment.pri)
qtcAddDeployment()

