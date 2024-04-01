#include "Circuit.h"
#include <iostream>

Circuit::Circuit() {
	this->cars = new Car * [0];
	this->length = 0;
	this->nrOfCars = 0;
	this->weather = Weather::Rain;
}
Circuit::~Circuit() {
		for (int i = 0; i < nrOfCars; i++)
			delete this->cars[i];
		delete[] this->cars;
}
void Circuit::SetLength(int len) {
	this->length = len;
}
void Circuit::SetWeather(Weather weather) {
	this->weather = weather;
}
void Circuit::AddCar(Car* car) {
	Car** tmp = new Car * [nrOfCars + 1];
	for (int i = 0; i < nrOfCars; i++)
		tmp[i] = this->cars[i];
	tmp[nrOfCars++] = car;
	delete[] cars;
	this->cars = tmp;
}
void swap(Car*& a, Car*& b) {
	Car* aux;
	aux = a;
	a = b;
	b = aux;
}
void Circuit::Race() {
	for (int i = 0; i < nrOfCars; i++)
		if (cars[i]->CanFinish(length))
			cars[i]->SetTime(weather, length);
	for (int i = 0; i < nrOfCars; i++) {
		bool swapped = false;
		for (int j = 0; j < nrOfCars - i - 1; j++) {
			if (cars[j]->GetTime() > cars[j + 1]->GetTime()) {
				swap(cars[j], cars[j + 1]);
				swapped = true;
			}
		}
		if (swapped == false)
			break;
	}

}
void Circuit::ShowFinalRanks() const {
	std::cout << "Clasament: " << std::endl;
	int rank = 1;
	for (int i = 0; i < nrOfCars; i++)
		if (cars[i]->CanFinish(length))
		{
			cars[i]->print();
			std::cout << " a terminat pe locul " << rank << std::endl;
			rank++;
		}
}
void Circuit::ShowWhoDidNotFinish() const {
	std::cout << std::endl << "Masinile care nu au terminat: " << std::endl;
	for (int i = 0; i < nrOfCars; i++)
		if (!cars[i]->CanFinish(length))
		{
			cars[i]->print();
			std::cout << std::endl;
		}
}