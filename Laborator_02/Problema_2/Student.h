#pragma once
class Student
{
private:
	char name[25];
	float mathGrade;
	float englishGrade;
	float historyGrade;
public:
	void SetName(char* name);
	char* GetName();

	bool SetMathGrade(float value);
	float GetMathGrade();

	bool SetEnglishGrade(float value);
	float GetEnglishGrade();

	bool SetHistoryGrade(float value);
	float GetHistoryGrade();

	float GetAverageGrade();
};

