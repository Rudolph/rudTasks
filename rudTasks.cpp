#include "Arduino.h"
#include "rudTasks.h"

// create the list o' tasks
rudTasks::rTask _tasks[MAXTASKS];

rudTasks::rudTasks(unsigned int inTickTime){
	_lastTime = millis();
	tickTime = inTickTime;
}

// called incessantly from loop() to run things what need running
void rudTasks::run(){
	noInterrupts();

	_theTime = millis();
	if(_theTime - _lastTime >= rudTasks::tickTime){
		_lastTime = _theTime;
		for(byte i=0; i<MAXTASKS; i++){
			if (--_tasks[i].wait == 0){
				_tasks[i].wait = _tasks[i].repeat;
				interrupts();
				_tasks[i].task();
				noInterrupts();
			}
		}
	}

	interrupts();
}

// called in setup(), once for each function to schedule
// returns int just in case I wanna catch errors ever
int rudTasks::add(taskCallback pointer, unsigned int repeat, unsigned int wait){
	static uint32_t _schedCount = 0;
	if(_schedCount < MAXTASKS){
		_tasks[_schedCount].task = pointer;
		_tasks[_schedCount].repeat = repeat;
		_tasks[_schedCount].wait = wait + 1;
		++_schedCount;
		return 0;
	}else{
		return -1;
	}
}
