TEMPLATE = app

QT += widgets

CONFIG += c++11
SOURCES += wayclip.cpp

target.path = /usr/local/bin/
INSTALLS += target

mac {
	CONFIG -= app_bundle
	OBJECTIVE_SOURCES += wayclip_mac.mm
	LIBS += -framework Cocoa
}
