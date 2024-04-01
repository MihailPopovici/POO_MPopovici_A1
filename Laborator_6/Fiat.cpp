#include "Fiat.h"
Fiat::Fiat() {
	capacity = 60;
	consumption = 10;
	rainSpeed = 90;
	sunnySpeed = 100;
	snowSpeed = 80;
	finished = false;
	time = 0;
};
void Fiat::print() {
	std::cout << "Fiat";
};
void Fiat::SetTime(Weather weather, int length) {
	if (weather == Weather::Rain)
		time = length / rainSpeed;
	else if (weather == Weather::Sunny)
		time = length / sunnySpeed;
	else if (weather == Weather::Snow)
		time = length / snowSpeed;
};
double Fiat::GetTime() {
	return time;
}
bool Fiat::CanFinish(int len) {
	if (capacity > ((consumption / 100) * len))
		finished = true;
	return finished;
};