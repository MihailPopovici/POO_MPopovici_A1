#include "RangeRover.h"

RangeRover::RangeRover() {
	capacity = 70;
	consumption = 12;
	rainSpeed = 100;
	sunnySpeed = 140;
	snowSpeed = 90;
	finished = false;
	time = 0;
};
void RangeRover::print() {
	std::cout << "RangeRover";
};
void RangeRover::SetTime(Weather weather, int length) {
	if (weather == Weather::Rain)
		time = length / rainSpeed;
	else if (weather == Weather::Sunny)
		time = length / sunnySpeed;
	else if (weather == Weather::Snow)
		time = length / snowSpeed;
};
double RangeRover::GetTime() {
	return time;
}
bool RangeRover::CanFinish(int len) {
	if (capacity > ((consumption / 100) * len))
		finished = true;
	return finished;
};