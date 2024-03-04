#include "Student.h"
#include <string.h>

void Student::SetName(char* name) {
	int length = strlen(name);
	for (int i = 0; i < length; i++)
		this->name[i] = name[i];
	for (int i = length; i < 25; i++)
		this->name[i] = '\0';
}

char* Student::GetName() {
	return this->name;
}

bool Student::SetMathGrade(float value) {
	if (value < 1 || value>10)
		return false;
	this->mathGrade = value;
	return true;
}

float Student::GetMathGrade() {
	return this->mathGrade;
}

bool Student::SetEnglishGrade(float value) {
	if (value < 1 || value>10)
		return false;
	this->englishGrade = value;
	return true;
}

float Student::GetEnglishGrade() {
	return this->englishGrade;
}

bool Student::SetHistoryGrade(float value) {
	if (value < 1 || value>10)
		return false;
	this->historyGrade = value;
	return true;
}

float Student::GetHistoryGrade() {
	return this->historyGrade;
}

float Student::GetAverageGrade() {
	float sum = 0;
	sum = this->mathGrade + this->englishGrade + this->historyGrade;
	return sum / 3;
}

