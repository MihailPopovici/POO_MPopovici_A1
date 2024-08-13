#include "Student.h"
#include <cstring>
#include <iostream>

void Student::SetName(char* name) {
	for (int i = 0; i < strlen(name); i++)
		this->name[i] = name[i];
	this->name[strlen(name)] = '\0';
}

const char* Student::GetName() {
	return this->name;
}

bool Student::SetEnglishGrade(float grade) {
	if (grade < 1 || grade>10) {
		std::cout << "English grade must be between 1 and 10" << std::endl;
		return false;
	}
	this->englishGrade = grade;
	return true;
}

float Student::GetEnglishGrade() const {
	return this->englishGrade;
}

bool Student::SetMathGrade(float grade) {
	if (grade < 1 || grade>10) {
		std::cout << "Math grade must be between 1 and 10" << std::endl;
		return false;
	}
	this->mathGrade = grade;
	return true;
}

float Student::GetMathGrade() const{
	return this->mathGrade;
}

bool Student::SetHistoryGrade(float grade) {
	if (grade < 1 || grade>10) {
		std::cout << "History grade must be between 1 and 10" << std::endl;
		return false;
	}
	this->historyGrade = grade;
	return true;
}

float Student::GetHistoryGrade() const {
	return this->historyGrade;
}

float Student::GetAverageGrade() const {
	return (this->englishGrade + this->historyGrade + this->mathGrade) / 3;
}
