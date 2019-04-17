#-------------------------------------------------
#
# Project created by QtCreator 2019-03-08T15:22:09
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Visual
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

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    BooleanBitmap.cpp \
    CheckerBoard.cpp \
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD \
    BooleanBitmap.cpp \
    BrokenSqr.cpp \
    CheckerBoard.cpp \
    EllipseBoard.cpp \
    main.cpp \
    mainwindow.cpp
    BrokenSqr.cpp
=======
    EllipseBoard.cpp
>>>>>>> 15ea5826cb6f0e7f521ea5ffbd1edcc87cd7afc1
=======
    EllipseBoard.cpp
>>>>>>> 15ea5826cb6f0e7f521ea5ffbd1edcc87cd7afc1
=======
    EllipseBoard.cpp \
<<<<<<< HEAD
    SquareWithHole.cpp
>>>>>>> 381f5292e6b0102287dd7a6433a3e12bf4c16303
=======
    SquareWithHole.cpp \
    Quadrilateral.cpp
>>>>>>> e4016cd81acd014ff804ea846f4d5ecdbe0d5f61

HEADERS += \
        mainwindow.h \
    BooleanBitmap.h \
    CheckerBoard.h \
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD \
    BooleanBitmap.h \
    BrokenSqr.h \
    CheckerBoard.h \
    EllipseBoard.h \
    mainwindow.h
    BrokenSqr.h
=======
    EllipseBoard.h
>>>>>>> 15ea5826cb6f0e7f521ea5ffbd1edcc87cd7afc1
=======
    EllipseBoard.h
>>>>>>> 15ea5826cb6f0e7f521ea5ffbd1edcc87cd7afc1
=======
    EllipseBoard.h \
<<<<<<< HEAD
    SquareWithHole.h
>>>>>>> 381f5292e6b0102287dd7a6433a3e12bf4c16303
=======
    SquareWithHole.h \
    Quadrilateral.h
>>>>>>> e4016cd81acd014ff804ea846f4d5ecdbe0d5f61

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
