#pragma once
#include "Car.h"

class RangeRover : public Car
{
public:
	RangeRover();
	void print() override;
	void SetTime(Weather weather, int length) override;
	double GetTime() override;
	bool CanFinish(int len) override;
};

