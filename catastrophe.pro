#-------------------------------------------------
#
# Project created by QtCreator 2023-12-15T15:24:16
#
#-------------------------------------------------

QT       += core gui
QT += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = catastrophe
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
    game_window.cpp \
    help_browser.cpp \
    load_game_window.cpp \
    new_game_window.cpp \
    settings_window.cpp \
    about_window.cpp \
    file_processor.cpp \
    save_current_game_window.cpp

HEADERS += \
        mainwindow.h \
    game_window.h \
    help_browser.h \
    load_game_window.h \
    new_game_window.h \
    settings_window.h \
    about_window.h \
    file_processor.h \
    save_current_game_window.h

FORMS += \
        mainwindow.ui \
    game_window.ui \
    help_browser.ui \
    load_game_window.ui \
    new_game_window.ui \
    settings_window.ui \
    about_window.ui \
    save_current_game_window.ui

DISTFILES += \
    ../build-catastrophe-Desktop_Qt_5_10_0_MinGW_32bit-Debug/debug/styles.css
