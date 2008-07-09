/* 
 * File:   logger.h
 * Author: dmilith
 *
 * Created on 6 kwiecień 2008, 18:03
 */

#ifndef _LOGGER_H
#define	_LOGGER_H

#include <qt4/QtCore/QTextOStream>
#include "main.h"

using namespace std;

namespace Log {

  class Logger {
    public:
      QString logger_filename;
      QString logger_level;
      
      Logger( const QString& log_filename, const QString& level = "notice" );
      void set_level( const QString& level_name );
      void log( const QString& message );
  };

}

#endif	/* _LOGGER_H */

