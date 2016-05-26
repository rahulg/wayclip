TEMPLATE = app

QT += widgets

CONFIG += c++11
SOURCES += wayclip.cpp

mac {
	CONFIG -= app_bundle
}
