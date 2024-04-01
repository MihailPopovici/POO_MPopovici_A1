#include "Seat.h"

Seat::Seat() {
	capacity = 75;
	consumption = 7;
	rainSpeed = 95;
	sunnySpeed = 105;
	snowSpeed = 85;
	finished = false;
	time = 0;
};
void Seat::print() {
	std::cout << "Seat";
};
void Seat::SetTime(Weather weather, int length) {
	if (weather == Weather::Rain)
		time = length / rainSpeed;
	else if (weather == Weather::Sunny)
		time = length / sunnySpeed;
	else if (weather == Weather::Snow)
		time = length / snowSpeed;
};
double Seat::GetTime() {
	return time;
}
bool Seat::CanFinish(int len) {
	if (capacity > ((consumption / 100) * len))
		finished = true;
	return finished;
};