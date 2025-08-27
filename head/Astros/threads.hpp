#ifndef __ASTROS_JPPVC_THREADS__
#define __ASTROS_JPPVC_THREADS__

#include <string>
#include <functionals>
#include <Astros/log.hpp>

using namespace Astros;

#define __ASTROS_DEEP_LOGGIN__

//if null wants to be passed to thr ThreadTask constructor set null to true
//
typedef class ThreadTask ThreadTask;
typedef struct ThreadTaskArgStruct ThreadTaskArg;

class ThreadLog {
	
	
	public:
	void trackNewThread(ThreadTask add, ThreadTaskArg root) {
		if (root.null) {

		}
	}

	void print(std::string msg) {

	}
	
};


//Essa classe existe principalmente para padronizar as operacoes de 
//thread feita pela API
class ThreadTask {
	std::function<void()> run;
	ThreadLog &log;

	public:
	ThreadTask(std::function<void()> run, ThreadLog &log, ThreadTaskArg rootThread) {
		this->run = run;
		this->log = log;

		this->log.trackNewThread(this, rootThread);
	}
//Essa funcao torna Thread Task em um objeto callable
	void operator()() {
		run();
		#ifdef __ASTROS_DEEP_LOGGIN__
		log.print("New Thread");
		#endif
	}

};

struct ThreadTaskArgStruct {
	bool null;
	ThreadTask &task;
};

class Thread {
	
	public:
	Thread(class ThreadTask &task);
	~Thread(std::function<void()> func);

};

#endif
