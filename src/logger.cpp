#include <qt4/QtCore/QFile>
#include "logger.h"

using namespace Log;

Logger::Logger( QString log_filename ) {
  logger_filename = log_filename;
}

void
Logger::log( QString message ) {
  QFile logger_file( logger_filename );
  logger_file.open( QIODevice::Text | QIODevice::Append | QIODevice::WriteOnly );
  QTextStream logger(&logger_file); // logger
  logger.setCodec("UTF-8");
  logger << message << "\n";
}

