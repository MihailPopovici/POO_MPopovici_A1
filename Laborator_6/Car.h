#pragma once
#include "Weather.h"
#include <iostream>
class Car
{
protected:

	double capacity;
	double consumption;
	double rainSpeed;
	double sunnySpeed;
	double snowSpeed;
	bool finished;//can/can not finish
	double time;//timeToFinishTheCircuit
public:
	virtual void SetTime(Weather weather, int length) = 0;
	virtual double GetTime() = 0;
	virtual bool CanFinish(int l) = 0;
	virtual void print() =0;
};