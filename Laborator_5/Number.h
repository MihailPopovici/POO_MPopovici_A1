#pragma once
class Number
{
private:
	char* value;
	int base;
public:
	Number(const char* value, int base); // where base is between 2 and 16
	Number(int nr);
	Number(const Number& other);//copy constructor
	Number(Number&& other);//move constructor
	~Number();

	Number& operator=(const Number& other); // copy assignment operator
	Number& operator=(Number&& other); // move assignment operator
	Number& operator=(const char* value);
	Number& operator+=(const Number& other);

	//+/- operators using friend functions
	friend Number operator+(const Number& n1, const Number& n2);
	friend Number operator-(const Number& n1, const Number& n2);

	//operators
	char& operator[](int index);
	bool operator>(const Number& other);
	bool operator<(const Number& other);
	bool operator>=(const Number& other);
	bool operator<=(const Number& other);
	bool operator==(const Number& other);
	bool operator!=(const Number& other);

	//decrement operators
	Number& operator--(); // prefixat
	Number& operator--(int); // postfixat

	void SwitchBase(int newBase);
	void Print();
	int  GetDigitsCount(); // returns the number of digits for the current number
	int  GetBase(); // returns the current base

private:
	//helper function
	static char* ConvertBase(const char* value, int oldBase, int newBase);
	static int CharToInt(char* value);
	static char* IntToChar(int nr);
};

