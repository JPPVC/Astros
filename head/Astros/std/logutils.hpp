#ifndef __ASTROS_JPPVC_LOGUTILS__
#define __ASTROS_JPPVC_LOGUTILS__

/*
*	ASTROS PROJECT
*	This file contains user modifiable logging assets which are
*	the standard for logging error and scripts in the Astros logging ecosystem
*
*
*/


#include <Astros/log.hpp>


class LogRegistryScriptNull : public LogRegistryScript{

        public:
        void run () {}
};


class LogRegistryScriptNullVerbose : public LogRegistryScript {
	
	public:
	void run() {std::cout << errFormatVerbose("Null Logging object called", 0) << std::endl();}
};


#endif
