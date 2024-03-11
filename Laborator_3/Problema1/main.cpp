#include <iostream>
#include "Math.h"

using namespace std;

int main() {

	cout << Math::Add(4, 5) << endl;
	cout << Math::Add(3, 4, 5) << endl;
	cout << Math::Add(2.5, 2.3) << endl;
	cout << Math::Add(2.1, 2.2, 2.3) << endl;
	cout << Math::Mul(4, 5) << endl;
	cout << Math::Mul(3, 4, 5) << endl;
	cout << Math::Mul(2.5, 2.3) << endl;
	cout << Math::Mul(2.1, 2.2, 2.3) << endl;

	cout << Math::Add("12", "4") << endl;
	return 0;
}