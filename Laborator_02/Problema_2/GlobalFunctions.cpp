#include "GlobalFunctions.h"
#include <cstring>

int CompareByEnglishGrade(Student* s1, Student* s2) {
	if (s1->GetEnglishGrade() > s2->GetEnglishGrade()) 
		return 1;
	if (s1->GetEnglishGrade() < s2->GetEnglishGrade()) 
		return -1;
	return 0;
}

int CompareByMathGrade(Student* s1, Student* s2) {
	if (s1->GetMathGrade() > s2->GetMathGrade())
		return 1;
	if (s1->GetMathGrade() < s2->GetMathGrade())
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
	int length1 = strlen(s1->GetName());
	int length2 = strlen(s2->GetName());
	for (int i = 0; i < length1 && i < length2; i++) {
		const char* name_s1 = s1->GetName();
		const char* name_s2 = s2->GetName();
		if (name_s1[i] > name_s2[i]) return 1;
		if (name_s1[i] < name_s2[i]) return -1;
	}
	if (length1 > length2) return 1;
	if (length1 < length2) return -1;
	return 0;
}