TEMPLATE = app

QT += widgets

DEFINES += VERSION=\\\"$$system(git describe --tags --always --abbrev=7 --dirty)\\\"

CONFIG += c++11
SOURCES += src/wayclip.cpp

target.path = /usr/local/bin/
INSTALLS += target
QMAKE_CLEAN += ${TARGET}

mac {
	CONFIG -= app_bundle
	OBJECTIVE_SOURCES += src/wayclip_mac.mm
	LIBS += -framework Cocoa
}
