#include <iostream>
#include "Sort.h"

using namespace std;

int main(){
	
	Sort s1(5,1,10);
	s1.BubbleSort();
	s1.Print();

	Sort s2({12,14,144,23});
	s2.InsertSort(true);
	s2.Print();

	vector<int> vec = { 14,15,10,7,23 };
	Sort s3(vec, 5);
	s3.QuickSort();
	s3.Print();

	Sort s4(5, 2, 5, 6, 1, 4);
	s4.QuickSort(true);
	s4.Print();

	Sort s5("10,23,9,17");
	s5.InsertSort();
	s5.Print();
	cout << s5.GetElementsCount() << ' ' << s5.GetElementFromIndex(2);
	return 0;
}