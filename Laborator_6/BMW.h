#pragma once
#include "Car.h"
class BMW : public Car
{
public:
	BMW();
	void print() override;
	void SetTime(Weather weather, int length) override;
	double GetTime() override;
	bool CanFinish(int len) override;
};
