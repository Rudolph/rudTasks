#include "rudTasks.h"

#define ledOne 13
#define ledTwo 12

// create task scheduler running every 10 millis
rudTasks tasks(10);

void setup(){
	pinMode(ledOne, OUTPUT);
	pinMode(ledTwo, OUTPUT);
	digitalWrite(ledOne, LOW);
	digitalWrite(ledTwo, LOW);
	
	tasks.add(blinkOne, 50); // every 50 ticks, 500 millis, 2 times per second
	tasks.add(blinkTwo, 20); // every 20 ticks, 200 millis, 5 times per second
}

void loop(){
	tasks.run();
}

void blinkOne(){
	static byte myblink = 0;
	myblink ^= 1;
	digitalWrite(ledOne, myblink);
}

void blinkTwo(){
	static byte myblink = 0;
	myblink ^= 1;
	digitalWrite(ledTwo, myblink);
}
