#pragma once
#include "Car.h"

class Fiat : public Car
{
public:
	Fiat();
	void print() override;
	void SetTime(Weather weather, int length) override;
	double GetTime() override;
	bool CanFinish(int len) override;
};

