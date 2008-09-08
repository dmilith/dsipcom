/*
 * author: Daniel (dmilith) Dettlaff
 * email: dmilith at drakor.eu
 * released under GPL2 & LGPL license
 * © 2oo8
 */
     
#include <qt4/QtCore/QFile>
#include "logger.h"
#include "main.h"

using namespace Log;

Logger::Logger( const QString& log_filename, const QString& level ) {
  logger_filename = log_filename;
  logger_level = level;
}

void
Logger::log( const QString& message ) {
  QFile logger_file( logger_filename );
  logger_file.open( QIODevice::Text | QIODevice::Append | QIODevice::WriteOnly );
  QTextStream logger( &logger_file ); // logger
  logger.setCodec( "UTF-8" );
  logger << logger_level << ": "<< message << "\n";
}

void
Logger::set_level( const QString& level_name ) {
  logger_level = level_name;
}

