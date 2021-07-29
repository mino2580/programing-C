TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CFLAGS += -Wall -Werror -std=c99

SOURCES += \
        $$PWD/*.c

HEADERS += \
        $$PWD/*.h

DESTDIR = bin
