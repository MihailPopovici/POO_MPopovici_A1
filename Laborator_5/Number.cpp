#include "Number.h"
#include <iostream>

Number::Number(const char* value, int base) {
	this->base = base;
	int length = 0;
	while (value[length] != '\0') length++;
	this->value = new char[length + 1];
	memcpy(this->value, value, length + 1);
}

Number::Number(int nr) {
	this->base = 10;
	int aux = nr, cnt = 0;
	while (aux) cnt++, aux /= 10;
	this->value = new char[cnt+1];
	this->value[cnt] = '\0';
	for (int i = cnt - 1; i >= 0; i--) {
		this->value[i] = (nr % 10) + '0';
		nr /= 10;
	}
}

Number::Number(const Number& other) {
	this->base = other.base;
	int length = 0;
	while (other.value[length] != '\0') length++;
	this->value = new char[length + 1];
	memcpy(this->value, other.value, length+1);
}

Number::Number(Number&& other) {
	this->base = other.base;
	this->value = other.value;
	other.base = 0;
	other.value = nullptr;
}

Number::~Number() {
	delete[] this->value;
}

Number& Number::operator=(const Number& other) {
	if (this != &other) {
		delete[] this->value;
		this->base = other.base;
		int length = 0;
		while (other.value[length] != '\0') length++;
		this->value = new char[length + 1];
		memcpy(this->value, other.value, length + 1);
	}
	return *this;
}

Number& Number::operator=(Number&& other) {
	if (this != &other) {
		delete[] this->value;

		this->base = other.base;
		this->value = other.value;

		other.base = 0;
		other.value = nullptr;
	}
	return *this;
}
Number& Number::operator=(const char* value) {
	char* result = Number::ConvertBase(value, 10, this->base);
	int length = 0;
	while (result[length] != '\0') length++;
	delete[] this->value;
	this->value = new char[length+1];
	memcpy(this->value, result, length + 1);
	return *this;
}
Number& Number::operator+=(const Number& other) {
	*this = *this + other;
	return *this;
}

void Number::Print() {
	std::cout << "Value is: " << this->value << " and Base is: " << this->base << std::endl;
}

int Number::GetDigitsCount() {
	int length = 0;
	while (this->value[length] != '\0') length++;
	return length;
}

int Number::GetBase() {
	return this->base;
}

Number operator+(const Number& n1, const Number& n2) {
	int base = n1.base;
	if (n2.base > n1.base) base = n2.base;

	char* nr1 = Number::ConvertBase(n1.value, n1.base, 10);
	char* nr2 = Number::ConvertBase(n2.value, n2.base, 10);

	int inr1 = Number::CharToInt(nr1);
	int inr2 = Number::CharToInt(nr2);

	int sum = inr1 + inr2;
	int aux = sum, cnt = 0;
	while (aux) {
		cnt++;
		aux /= 10;
	}

	char* result = Number::IntToChar(sum);
	result = Number::ConvertBase(result, 10, base);

	Number n(result, base);

	delete[] nr1;
	delete[] nr2;
	delete[] result;

	return n;
}
Number operator-(const Number& n1, const Number& n2) {
	int base = n1.base;
	if (n2.base > n1.base) base = n2.base;

	char* nr1 = Number::ConvertBase(n1.value, n1.base, 10);
	char* nr2 = Number::ConvertBase(n2.value, n2.base, 10);

	int inr1 = Number::CharToInt(nr1);
	int inr2 = Number::CharToInt(nr2);

	int diff = inr1 - inr2;
	int aux = diff, cnt = 0;
	while (aux) {
		cnt++;
		aux /= 10;
	}

	char* result = Number::IntToChar(diff);

	result = Number::ConvertBase(result, 10, base);

	Number n(result, base);

	delete[] nr1;
	delete[] nr2;
	delete[] result;

	return n;
}

char& Number::operator[](int index) {
	return this->value[index];
}

bool Number::operator>(const Number& other) {
	char* nr1 = Number::ConvertBase(this->value, this->base, 10);
	char* nr2 = Number::ConvertBase(other.value, other.base, 10);
	int inr1 = Number::CharToInt(nr1);
	int inr2 = Number::CharToInt(nr2);
	delete[] nr1;
	delete[] nr2;
	return inr1 > inr2;
}

bool Number::operator<(const Number& other) {
	char* nr1 = Number::ConvertBase(this->value, this->base, 10);
	char* nr2 = Number::ConvertBase(other.value, other.base, 10);
	int inr1 = Number::CharToInt(nr1);
	int inr2 = Number::CharToInt(nr2);
	delete[] nr1;
	delete[] nr2;
	return inr1 < inr2;
}

bool Number::operator>=(const Number& other) {
	char* nr1 = Number::ConvertBase(this->value, this->base, 10);
	char* nr2 = Number::ConvertBase(other.value, other.base, 10);
	int inr1 = Number::CharToInt(nr1);
	int inr2 = Number::CharToInt(nr2);
	delete[] nr1;
	delete[] nr2;
	return inr1 >= inr2;
}

bool Number::operator<=(const Number& other) {
	char* nr1 = Number::ConvertBase(this->value, this->base, 10);
	char* nr2 = Number::ConvertBase(other.value, other.base, 10);
	int inr1 = Number::CharToInt(nr1);
	int inr2 = Number::CharToInt(nr2);
	delete[] nr1;
	delete[] nr2;
	return inr1 <= inr2;
}

bool Number::operator==(const Number& other) {
	char* nr1 = Number::ConvertBase(this->value, this->base, 10);
	char* nr2 = Number::ConvertBase(other.value, other.base, 10);
	int inr1 = Number::CharToInt(nr1);
	int inr2 = Number::CharToInt(nr2);
	delete[] nr1;
	delete[] nr2;
	return inr1 == inr2;
}
bool Number::operator!=(const Number& other) {
	char* nr1 = Number::ConvertBase(this->value, this->base, 10);
	char* nr2 = Number::ConvertBase(other.value, other.base, 10);
	int inr1 = Number::CharToInt(nr1);
	int inr2 = Number::CharToInt(nr2);
	delete[] nr1;
	delete[] nr2;
	return inr1 != inr2;
}

void Number::SwitchBase(int newBase) {
	if (this->base == newBase) return;

	char* newValue = Number::ConvertBase(this->value, this->base, newBase);

	this->base = newBase;
	delete[] this->value;
	int length = 0;
	while (newValue[length] != '\0') length++;
	this->value = new char[length + 1];
	memcpy(this->value, newValue, length + 1);

	delete[] newValue;
}


char* Number::ConvertBase(const char* value, int oldBase, int newBase) {
	//convert from current base to base 10;
	int length = 0;
	while (value[length] != '\0') length++;
	int res = 0;
	for (int i = 0; i < length; i++) {
		int currentDigit = 0;
		if (value[i] >= '0' && value[i] <= '9') currentDigit = value[i] - '0';
		if (value[i] >= 'A' && value[i] <= 'F') currentDigit = value[i] - 'A' + 10;
		res = res * oldBase + currentDigit;
	}
	//now, in res we have stored the number in base 10

	//convert from base 10 to newBase
	char* newValue = new char[16];
	int index = 0;
	while (res != 0) {
		int remainder = res % newBase;
		char digit;
		if (remainder < 10) {
			digit = remainder + '0';
		}
		else {
			digit = remainder - 10 + 'A';
		}
		newValue[index++] = digit;
		res /= newBase;
	}
	if (index == 0) {
		newValue[index++] = '0';
	}
	newValue[index] = '\0';
	//reverse 
	for (int i = 0; i < index / 2; ++i) {
		char aux = newValue[i];
		newValue[i] = newValue[index - i - 1];
		newValue[index - i - 1] = aux;
	}

	return newValue;
}

Number& Number::operator--() {
	int length = 0;
	while (this->value[length] != '\0') length++;
	if (length == 0)
		return *this; 

	for (int i = 0; i < length; i++)
		this->value[i] = this->value[i + 1];
	//char* newValue = new char[length];
	//memcpy(newValue, this->value+1, length);
	//delete[] this->value;
	//memcpy(this->value, newValue, length);
	//delete[] newValue;

	return *this;
}

Number& Number::operator--(int) {
	int length = 0;
	while (this->value[length] != '\0') length++;
	this->value[length - 1] = '\0';
	return *this;
}

int Number::CharToInt(char* value) {
	int res = 0;
	int length = 0;
	while (value[length] != '\0') length++;
	for (int i = 0; i < length; i++)
		res = res * 10 + (value[i] - '0');
	return res;
}

char* Number::IntToChar(int nr) {
	int aux = nr, cnt = 0;
	while (aux) cnt++, aux /= 10;
	char* value = new char[cnt + 1];
	value[cnt] = '\0';
	for (int i = cnt - 1; i >= 0; i--) {
		value[i] = (nr % 10) + '0';
		nr /= 10;
	}
	return value;
}