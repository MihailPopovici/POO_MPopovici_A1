#include "Volvo.h"

Volvo::Volvo() {
	capacity = 75;
	consumption = 15;
	rainSpeed = 110;
	sunnySpeed = 130;
	snowSpeed = 100;
	finished = false;
	time = 0;
};
void Volvo::print() {
	std::cout << "Volvo";
};
void Volvo::SetTime(Weather weather, int length) {
	if (weather == Weather::Rain)
		time = length / rainSpeed;
	else if (weather == Weather::Sunny)
		time = length / sunnySpeed;
	else if (weather == Weather::Snow)
		time = length / snowSpeed;
};
double Volvo::GetTime() {
	return time;
}
bool Volvo::CanFinish(int len) {
	if (capacity > ((consumption / 100) * len))
		finished = true;
	return finished;
};