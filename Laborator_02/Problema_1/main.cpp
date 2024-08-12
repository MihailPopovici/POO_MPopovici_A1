#include <iostream>
#include "NumberList.h"

using namespace std;

int main() {

	NumberList ourNumbers;

	ourNumbers.Init();
	
	ourNumbers.Add(12);
	ourNumbers.Add(23);
	ourNumbers.Add(11);
	ourNumbers.Add(40);

	ourNumbers.Print();//12 23 11 40

	ourNumbers.Sort();

	ourNumbers.Print();//11 12 23 40
	return 0;
}