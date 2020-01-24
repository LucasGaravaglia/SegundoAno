TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    contador.cpp \
    pessoa.cpp \
    ponto.cpp \
    reta.cpp

SUBDIRS += \
    Exercicios.pro

HEADERS += \
    contador.h \
    pessoa.h \
    ponto.h \
    reta.h
