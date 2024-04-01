#pragma once
#include "Car.h"
class Seat : public Car
{
public:
	Seat();
	void print() override;
	void SetTime(Weather weather, int length) override;
	double GetTime() override;
	bool CanFinish(int len) override;
};

