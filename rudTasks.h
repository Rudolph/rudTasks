#ifndef RUDTASKS_H
#define RUDTASKS_H

#include "Arduino.h"

#define MAXTASKS 10

typedef void(*taskCallback)(void);

class rudTasks {
	public:
		rudTasks(unsigned int inTickTime = 10);
		unsigned int tickTime;
		int add(taskCallback pointer, unsigned int repeat, unsigned int wait=0);
		void run();
		struct rTask {
			void (*task)();
			uint32_t repeat;
			uint32_t wait;
		};

	private:
		//uint32_t _tickTime;
		uint32_t _theTime;
		uint32_t _lastTime;
		static uint32_t _schedCount;

	
};

#endif

