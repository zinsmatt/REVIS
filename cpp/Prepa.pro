TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp StudentManager.cpp \
    human.cpp \
    student.cpp \
    arraylist.cpp \
    stringcontainer.cpp \
    mystring.cpp \
    stringarray.cpp \
    word.cpp \
    arrays.cpp
HEADERS += StudentManager.h \
    human.h \
    student.h \
    arraylist.h \
    stringcontainer.h \
    mystring.h \
    stringarray.h \
    word.h \
    arrays.h

include(deployment.pri)
qtcAddDeployment()

