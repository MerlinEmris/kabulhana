#-------------------------------------------------
#
# Project created by QtCreator 2016-04-20T20:45:29
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = kabulhana
TEMPLATE = app


SOURCES += main.cpp\
        hassa.cpp

HEADERS  += hassa.h
QMAKE_LFLAGS += -static -static-libgcc
