#pragma once
class Student
{
private:
	char name[256];
	float mathGrade;
	float englishGrade;
	float historyGrade;
public:
	void SetName(char* name);
	const char* GetName();

	bool SetMathGrade(float grade);
	float GetMathGrade() const;

	bool SetEnglishGrade(float grade);
	float GetEnglishGrade() const;

	bool SetHistoryGrade(float grade);
	float GetHistoryGrade() const;

	float GetAverageGrade() const;
};

