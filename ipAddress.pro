QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ipAddress

TEMPLATE = app

SOURCES += src/main.cpp src/MainWindow.cpp

HEADERS += src/MainWindow.hpp

FORMS += src/MainWindow.ui
