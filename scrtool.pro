TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += qt
QT += widgets

SOURCES += \
        main.cpp

TOPSRCDIR   = $$PWD
TOPBUILDDIR = $$shadowed($$PWD)
DESTDIR = $$TOPBUILDDIR/output

LIBDIR = $$DESTDIR
LIBS += -L$$LIBDIR -lPrScrn -lgdiplus

HEADERS += \
    main.h
