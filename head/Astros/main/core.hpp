#ifndef __ASTROS_JPPVC_CORE__
#define __ASTROS_JPPVC_CORE__
namespace Astros {

typedef struct TimeStruct {
	unsigned long ns;
	unsigned long ms;
} Time;

}

#ifdef _WIN64

#include<Astros/main/winclock.hpp>

#elif linux

#include<Astros/main/linclock.hpp>

#elif __gnu_linux__

#include<Astros/main/linclock.hpp>

#elif __linux__

#include<Astros/main/linclock.hpp>

#endif

#endif
