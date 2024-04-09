#include <iostream>

using namespace std;

float operator""_Kelvin(unsigned long long number) {
	return number - 273.15;
}
float operator""_Fahrenheit(unsigned long long number) {
	return (number - 32) / 1.8;
}

int main() {

	float a = 300_Kelvin;    
	float b = 120_Fahrenheit;

	cout << a << endl;
	cout << b << endl;
	return 0;
}