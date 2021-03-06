#-------------------------------------------------
#
# Project created by QtCreator 2018-06-03T08:59:15
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ms3D
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    gameworld.cpp \
    gameobject.cpp \
    gamesector.cpp \
    gameObjectComponents/mesh.cpp \
    gameObjectComponents/phythicobject.cpp \
    widgets/viewwidget.cpp \
    gameObjectComponents/texture.cpp \
    parsers/material.cpp \
    parsers/parserobj.cpp \
    parsers/sceneobject.cpp \
    parsers/ducParser/configitem.cpp \
    parsers/ducParser/ducparser.cpp \
    gameObjectComponents/gameObjectMaterial.cpp \
    enginecore.cpp \
    editorcore.cpp \
    parsers/baseparser.cpp

HEADERS += \
        mainwindow.h \
    gameworld.h \
    gameobject.h \
    gamesector.h \
    gameObjectComponents/mesh.h \
    gameObjectComponents/phythicobject.h \
    widgets/viewwidget.h \
    gameObjectComponents/texture.h \
    defines.h \
    msArray.h \
    parsers/material.h \
    parsers/parserobj.h \
    parsers/sceneobject.h \
    parsers/ducParser/configitem.h \
    parsers/ducParser/ducparser.h \
    gameObjectComponents/gameObjectMaterial.h \
    enginecore.h \
    editorcore.h \
    parsers/baseparser.h

FORMS += \
        mainwindow.ui
