#include <qt4/QtCore/QFile>
#include "logger.h"
#include "main.h"

using namespace Log;

Logger::Logger( QString log_filename, QString level) {
  logger_filename = LOGGER_DIR + log_filename;
  logger_level = level;
}

void
Logger::log( QString message ) {
  QFile logger_file( logger_filename );
  logger_file.open( QIODevice::Text | QIODevice::Append | QIODevice::WriteOnly );
  QTextStream logger(&logger_file); // logger
  logger.setCodec("UTF-8");
  logger << logger_level << ": "<< message << "\n";
}

void
Logger::set_level(QString level_name) {
  logger_level = level_name;
}
