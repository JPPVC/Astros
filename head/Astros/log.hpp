#ifndef __ASTROS_JPPVC_LOG__
#define __ASTROS_JPPVC_LOG__

#include <vector>
#include <string>
#include <iostream>

namespace Astros {
	
	class Log {
		
		std::vector<std::string> buff;

		public:
		
//this is for the subclass to inject any custon suffixes or prefixes to the
//payload to be printed to shell
		virtual std::string customFormatMsg(std::string msg) = 0;
		virtual std::string customFormatErr(std::string msg) = 0;
		
		void msg(std::string msg) {
			std::string base =  "Astros [MSG]  " << msg << "\n";
			std::cout << customFormatMsg << std::endl;
		}

		void msg(std::string msg) {
			std::string base = "Astros [ERR]  " << msg << "\n";
			std::cout << customFormatErr(base);
		}
		
	};
}
#endif
