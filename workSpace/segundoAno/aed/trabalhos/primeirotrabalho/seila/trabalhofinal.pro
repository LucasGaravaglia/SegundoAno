TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    controle.c \
    controleaeronave.c \
    controlecliente.c \
    controlevoo.c \
    gerastruct.c \
    grafico.c \
    interacaocliente.c \
    interacoesaeronave.c \
    interacoesvoo.c \
    lista_aeronave.c \
    lista_cliente.c \
    lista_voo.c \
    menus.c \
    relatoriotesteaeronave.c \
    relatoriotesteclietes.c \
    relatoriotestes.c \
    relatoriotestevoo.c \
    testeaeronave.c \
    testecliente.c \
    testevoo.c \
    validacao.c

SUBDIRS += \
    trabalhofinal.pro

DISTFILES += \
    trabalhofinal.pro.user

HEADERS += \
    controle.h \
    controleaeronave.h \
    controlecliente.h \
    controlevoo.h \
    estruturas.h \
    gerastruct.h \
    grafico.h \
    interacaocliente.h \
    interacoesaeronave.h \
    interacoesvoo.h \
    lista_aeronave.h \
    lista_cliente.h \
    lista_voo.h \
    menus.h \
    relatoriotesteaeronave.h \
    relatoriotesteclietes.h \
    relatoriotestes.h \
    relatoriotestevoo.h \
    testeaeronave.h \
    testecliente.h \
    testevoo.h \
    validacao.h
