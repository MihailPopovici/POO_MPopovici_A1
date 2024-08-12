#include "GlobalFunctions.h"
#include "string.h"

int CompareByMathGrade(Student* s1, Student* s2){
	if (s1->GetMathGrade() > s2->GetMathGrade())
		return 1;
	if (s1->GetMathGrade() < s2->GetMathGrade())
		return -1;
	return 0;
}
int CompareByEnglishGrade(Student* s1, Student* s2) {
	if (s1->GetEnglishGrade() > s2->GetEnglishGrade())
		return 1;
	if (s1->GetEnglishGrade() < s2->GetEnglishGrade())
		return -1;
	return 0;
}

int CompareByHistoryGrade(Student* s1, Student* s2) {
	if (s1->GetHistoryGrade() > s2->GetHistoryGrade())
		return 1;
	if (s1->GetHistoryGrade() < s2->GetHistoryGrade())
		return -1;
	return 0;
}

int CompareByAverageGrade(Student* s1, Student* s2) {
	if (s1->GetAverageGrade() > s2->GetAverageGrade())
		return 1;
	if (s1->GetAverageGrade() < s2->GetAverageGrade())
		return -1;
	return 0;
}
int CompareByName(Student* s1, Student* s2) {
	int lengthName1 = strlen(s1->GetName());
	int lengthName2 = strlen(s2->GetName());
	for (int i = 0; i < lengthName1 && i < lengthName2; i++) {
		if (s1->GetName()[i] > s2->GetName()[i]) return 1;
		if (s1->GetName()[i] < s2->GetName()[i]) return -1;
	}
	if (lengthName1 == lengthName2) return 0;
	if (lengthName1 < lengthName2) return -1;
	return 1;
}