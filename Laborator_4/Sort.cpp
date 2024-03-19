#include "Sort.h"
#include <iostream>
#include <cstdlib>
#include <time.h>

Sort::Sort(int numOfElements, int min, int max) {
	this->list = new int[numOfElements];
	this->count = numOfElements;
	srand(time(0));
	for (int i = 0; i < this->count; i++)
		this->list[i] = (rand() % (max - min + 1)) + min;
}

Sort::Sort(const std::initializer_list<int> il) {
	this->count = il.size();
	this->list = new int[il.size()];
	int i = 0;
	for (auto value : il) {
		this->list[i] = value;
		i++;
	}
}
Sort::Sort(std::vector<int> vec, int numOfElements) {
	this->count = numOfElements;
	this->list = new int[numOfElements];
	for (int i = 0; i < numOfElements; i++)
		this->list[i] = vec[i];
}

Sort::Sort(int numOfElements, ...){
	this->count = numOfElements;
	this->list = new int[numOfElements];
	va_list args;
	va_start(args, numOfElements);
	for (int i = 0; i < numOfElements; i++) {
		int num = va_arg(args, int);
		this->list[i] = num;
	}
	va_end(args);
}

Sort::Sort(const char* str) {
	int length = 0;
	while (str[length] != '\0') length++;
	int nrOfElements = 0, currentNum=0;
	for (int i = 0; i < length; i++) {
		if (str[i] == ',')
			nrOfElements++;
	}
	nrOfElements++;
	this->count = nrOfElements;
	this->list = new int[nrOfElements];
	int index = 0;
	for (int i = 0; i < length; i++) {
		if (str[i] == ',') this->list[index] = currentNum, index++, currentNum = 0;
		else currentNum = currentNum * 10 + (str[i] - '0');
	}
	this->list[index] = currentNum;
}

void Sort::InsertSort(bool ascendent) {
	int aux, j;
	for (int i = 1; i < this->count; i++) {
		aux = this->list[i];
		j = i - 1;
		if (ascendent) {
			while (j >= 0 && this->list[j] > aux) {
				this->list[j + 1] = this->list[j];
				j--;
			}
		}
		else {
			while (j >= 0 && this->list[j] < aux) {
				this->list[j + 1] = this->list[j];
				j--;
			}
		}
		if (this->list[j + 1] != aux) this->list[j + 1] = aux;
	}
}

void Sort::QuickSort(bool ascendent) {
	this->quickSort(this->list, 0, this->count-1, ascendent);
}
void Sort::quickSort(int* arr, int left, int right, bool ascendent) {
	if (left < right) {
		int pivot = this->partition(arr, left, right, ascendent);
		this->quickSort(arr, left, pivot - 1, ascendent);
		this->quickSort(arr, pivot + 1, right, ascendent);
	}
}
int Sort::partition(int* arr, int left, int right, bool ascendent) {
	int x = arr[left];
	int i = left + 1, j = right;
	if (ascendent) {
		while (i <= j) {
			if (arr[i] <= x) i++;
			if (arr[j] >= x) j--;
			if (i<j && arr[i]>x && arr[j] < x) {
				std::swap(arr[i], arr[j]);
				i++;
				j--;
			}
		}
	}
	else {
		while (i <= j) {
			if (arr[i] >= x) i++;
			if (arr[j] <= x) j--;
			if (i<j && arr[i]<x && arr[j] > x) {
				std::swap(arr[i], arr[j]);
				i++;
				j--;
			}
		}
	}
	int k = i - 1;
	arr[left] = arr[k];
	arr[k] = x;
	return k;
}

void Sort::BubbleSort(bool ascendent) {
	bool sorted = true;
	int n = this->count, aux=0;
	do {
		sorted = true;
		for (int i = 0; i < n - 1; i++) {
			if (ascendent) {
				if (this->list[i] > this->list[i + 1]) {
					aux = this->list[i];
					this->list[i] = this->list[i + 1];
					this->list[i + 1] = aux;
					sorted = false;
				}
			}
			else {
				if (this->list[i] < this->list[i + 1]) {
					aux = this->list[i];
					this->list[i] = this->list[i + 1];
					this->list[i + 1] = aux;
					sorted = false;
				}
			}
		}
		n--;
	} while (!sorted);
}

void Sort::Print() {
	for (int i = 0; i < this->count; i++)
		std::cout << this->list[i] << ' ';
	std::cout << std::endl;
}

int Sort::GetElementsCount() {
	return this->count;
}
int Sort::GetElementFromIndex(int index) {
	if (index < 0 || index >= this->count)
		return -1;
	return this->list[index];
}



Sort::~Sort() {
	delete[] this->list;
}