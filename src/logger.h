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

namespace Log {

  class Logger {
    public:
      QString logger_filename;
      QString logger_level;
      
      Logger( QString log_filename, QString level = "notice" );
      void set_level(QString level_name);
      void log( QString message );
  };

}

#endif	/* _LOGGER_H */

