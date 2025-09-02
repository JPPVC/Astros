#ifndef __ASTROS_JPPVC_RESULT__
#define __ASTROS_JPPVC_RESULT__

//this is supposed to be returned by the function to test if the procedure
//was successful note this doesnt require the constant needing of testing
//like the try and catch of the exceptions

#include <Astros/log.hpp>

namespace Astros {
class Result {
	
	public:
	Result();
	~Result();
	
	//custom function to be ran
	virtual void script() = 0;

};
}
#endif
