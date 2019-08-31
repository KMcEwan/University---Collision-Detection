#pragma once

#include <ctime> //LowResTimer good for test not appropriate in games

class Timer
{
public:
	virtual ~Timer() {};
	virtual void startTimer() = 0;
	virtual double getTime() = 0;
	virtual void resetTimer() = 0;
};

class LowResTimer : public Timer
{
public:
	virtual ~LowResTimer() {}
	LowResTimer();
	void startTimer();
	double getTime();
	void resetTimer();

private:
	clock_t timer;
};