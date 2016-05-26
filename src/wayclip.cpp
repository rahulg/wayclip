#include <QApplication>
#include <QClipboard>
#include <QCommandLineParser>
#include <QTextStream>

#ifdef Q_OS_MAC
#include "wayclip_mac.h"
#endif

void blackHole(QtMsgType type, const QMessageLogContext& ctx,
               const QString& msg) {
	(void)type;
	(void)ctx;
	(void)msg;
}

void pasteText() {
	QClipboard* clipboard = QApplication::clipboard();
	QTextStream(stdout) << clipboard->text(QClipboard::Clipboard);
}

void copyText(bool filter) {
	QClipboard* clipboard = QApplication::clipboard();
	QString input = QTextStream(stdin).readAll();
	clipboard->setText(input, QClipboard::Clipboard);
	if (filter) {
		QTextStream(stdout) << input;
	}
}

int main(int argc, char** argv) {

#ifdef Q_OS_MAC
	returnFocus();
#endif

	qInstallMessageHandler(blackHole);

	QApplication app(argc, argv);
	QApplication::setApplicationName("wayclip");
	QApplication::setApplicationVersion(VERSION);

	QCommandLineParser parser;
	parser.setApplicationDescription("Copy or paste text from the clipboard");
	parser.addHelpOption();
	parser.addVersionOption();

	QCommandLineOption debugOption("debug", "Print messages from Qt");
#if QT_VERSION >= 0x050600
	debugOption.setHidden(true);
#endif
	parser.addOption(debugOption);

	parser.addOptions({
	  {{"i", "in"}, "Read text into the clipboard"},
	  {{"o", "out"}, "Print text from the clipboard"},
	  {{"f", "filter"},
	   "In input mode, pass text through from stdin to stdout"},
	});
	parser.process(app.arguments());

	if (parser.isSet("debug")) {
		qInstallMessageHandler(0);
	}

	const bool inputOption = parser.isSet("in");
	const bool outputOption = parser.isSet("out");
	const bool filterOption = parser.isSet("filter");

	if (inputOption && outputOption) {
		parser.showHelp(1);
		return 1;
	}

	if (inputOption) {
		copyText(filterOption);
	} else if (outputOption) {
		pasteText();
	} else {
		copyText(filterOption);
	}

	return 0;
}
