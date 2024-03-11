#include "Math.h"
#include <cstdarg>
#include <cstdlib>

int Math::Add(int a, int b) {
	return a + b;
}
int Math::Add(int a, int b, int c) {
	return a + b + c;
}
int Math::Add(double a, double b) {
	return (int)(a + b);
}
int Math::Add(double a, double b, double c) {
	return (int)(a + b + c);
}

int Math::Mul(int a, int b) {
	return a * b;
}
int Math::Mul(int a, int b, int c) {
	return a * b * c;
}
int Math::Mul(double a, double b) {
	return (int)(a + b);
}
int Math::Mul(double a, double b, double c) {
	return (int)(a * b * c);
}

int Math::Add(int count, ...) {
	va_list args;
	va_start(args, count);

	int sum = 0;
	for (int i = 0; i < count; i++)
		sum += va_arg(args, int);

	va_end(args);
	return sum;
}

char* Math::Add(const char* s1, const char* s2) {
	if (s1 == nullptr || s2 == nullptr)
		return nullptr;

	int x1 = atoi(s1);
	int x2 = atoi(s2);

	x1 += x2;
	int aux = x1, cnt=0;
	while (aux) {
		cnt++;
		aux /= 10;
	}
	char* rez = new char[cnt + 1];
	_itoa_s(x1, rez, cnt+1, 10);

	return rez;

}