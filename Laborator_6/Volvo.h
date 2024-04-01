#pragma once
#include "Car.h"
class Volvo : public Car
{
public:
	Volvo();
	void print() override;
	void SetTime(Weather weather, int length) override;
	double GetTime() override;
	bool CanFinish(int len) override;
};

