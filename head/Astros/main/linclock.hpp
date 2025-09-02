#ifndef __ASTROS_JPPVC_LINCLOCK__
#define __ASTROS_JPPVC_LINCLOCK__

//NOTE apparently chrono is portable so no need to make 
//the use of macros
#include<chrono>

class Clock {
	
	unsigned long curr;
	
	public:
	Clock();
};

#endif
