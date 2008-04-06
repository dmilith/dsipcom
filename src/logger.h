/* 
 * File:   logger.h
 * Author: dmilith
 *
 * Created on 6 kwiecień 2008, 18:03
 */

#ifndef _LOGGER_H
#define	_LOGGER_H

#include <qt4/QtCore/QTextOStream>

namespace Log {

  class Logger {
    public:
      QString logger_filename;
      
      Logger( QString log_filename );
      void log( QString message );
  };

}

#endif	/* _LOGGER_H */

