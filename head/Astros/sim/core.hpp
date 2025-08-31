/*
	ASTROS PROJECT
	2025
	
	The purpose of this file is to define macros and classes 
	to make sure physics rules can be defined at compile time
	or runtime in the simulation
	
	For this when creating compile time physics objects 
	or physics rules you inherit de Object class or Rules class
	
	if you wish to add objects and rules at runtime there is the Astros Script
	which is a modified JSON syntax to add objects and rules at runtime
	
	The API can run multiples simulations through multithreading note 
	that as of version 0.0.1 indev each simulation will have access to only
	one thread but this can in the future be changed
*/

#ifndef __ASTROS_JPPVC_SIM_CORE__
#define __ASTROS_JPPVC_SIM_CORE__

#include <Astros/sim/script.hpp>
#include <time>
#include <vector>

namespace Astros {

//define at compile an object for the simulation
class Object {
};


//physics Rules
//priority determines the order in which the rule script will be ran
//rules will modify the behavior of objects in stages
//the tick function is a function called on the thread sim loop
//to update the simulation according to the rules
class Rule {
 
	private:
        int priority;
        unsigned long step;
	
	public:
	Rule(int priority) : priority(priority), step(0) {}
	virtual void tick(std::vector<Object> &objs) = 0;
	
};


//Class that creates runtime rules, in other words the rules
//created by the Astros script .as files
class RuntimeRule {


};

//this is what spit out by the clock after it does its calculations 
typedef struct ClockTickResultStruct {
	unsigned int iter_count;
	long long wait_time_ns;
	
	ClockTickResultStruct(unsigned int iter_count, long long wait_time_ns) : iter_count(iter_count), wait_time_ns(wait_time_ns) {}
	
}ClockTickResult;



//registerSpeed -> will register at which speed the Clock shall make the simulation run
//getIterInfo -> get info on how the simulation loop shall run
class Clock {

	private:
	
	public:
	Clock(int speed);
	
	void registerSpeed(int speed);
	ClockTickResult getIterInfo(std::time_t curr_time);
	
};

//RUNNING -> run at the normal universal seconds
//HALT -> pause the simulation
//DOUBLE_SPEED -> double of the current speed
//HALF_SPEED -> half of the current speed
//CUSTOM_SPEED -> custom speed, note that this is a scalar of universes speed (normal_speed * custom_speed)
//KILL -> kill the simulation
typedef enum SimStateEnum {
	RUNNING,
	HALT,
	HALF_SPEED,
	DOUBLE_SPEED,
	CUSTOM_SPEED,
	KILL
}SimState;

//class which holds the rules to be applied to objects
//this architecture makes it possible for at runtime to the objects and 
//rules of a simulation object to be changed.
class ObjectHolder {
	
	private:
	std::vector<Rule> rules;
	std::vector<Object> objects;
	Clock clock;
	
	public:
	
	ObjectHolder(Rule rule, Object object);
	
	~ObjectHolder();

	void tick();
};



//main simulation object which will have the simulation loop
//since in the API how the Sim loop works should not change it will be hard coded into the 
//API's binary
class Sim {
	
	private:
	int context_id;
	std::vector<ObjectHolder> objects;
	
	public:
	Sim(ObjectHolder init) : context_id(0) {objects.push_back(init)}
	void simLoopTick();
	void registerSpeed(unsigned long speed);
	void registerContext(ObjectHolder add);
};

}

#endif
