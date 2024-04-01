#pragma once
#include "Car.h"
class Circuit
{
private:
	Car** cars;
	int length;
	Weather weather;
	int nrOfCars;
public:
	Circuit();
	~Circuit();
	void SetLength(int len);
	void SetWeather(Weather weather);
	void AddCar(Car* car);
	void Race();
	void ShowFinalRanks() const;
	void ShowWhoDidNotFinish() const;
};

