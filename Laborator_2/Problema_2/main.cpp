#include <iostream>
#include "Student.h"
#include "GlobalFunctions.h"

using namespace std;

int main() {

	Student s1;
	s1.SetName((char*)"Mihail");
	s1.SetMathGrade(8.16);
	s1.SetEnglishGrade(10);
	s1.SetHistoryGrade(7.5);

	Student s2;
	s2.SetName((char*)"Razvan");
	s2.SetMathGrade(8.16);
	s2.SetEnglishGrade(9);
	s2.SetHistoryGrade(8);

	cout << "Nume Student: " << s1.GetName() << '\n';
	cout << "Nota Mate: " << s1.GetMathGrade() << '\n';
	cout << "Nota Engleza: " << s1.GetEnglishGrade() << '\n';
	cout << "Nota Istorie: " << s1.GetHistoryGrade() << '\n';
	cout << "Media Notelor: " << s1.GetAverageGrade() << "\n\n";

	cout << "Nume Student: " << s2.GetName() << '\n';
	cout << "Nota Mate: " << s2.GetMathGrade() << '\n';
	cout << "Nota Engleza: " << s2.GetEnglishGrade() << '\n';
	cout << "Nota Istorie: " << s2.GetHistoryGrade() << '\n';
	cout << "Media Notelor: " << s2.GetAverageGrade() << "\n\n\n";

	cout << "Comparatie in functie de nume: " << CompareByName(&s1, &s2) << '\n';
	cout << "Comparatie in functie de nota la mate: " << CompareByMathGrade(&s1, &s2) << '\n';
	cout << "Comparatie in functie de nota la engleza: " << CompareByEnglishGrade(&s1, &s2) << '\n';
	cout << "Comparatie in functie de nota la istorie: " << CompareByHistoryGrade(&s1, &s2) << '\n';
	cout << "Comparatie in functie de media notelor: " << CompareByAverageGrade(&s1, &s2) << '\n';
	return 0;
}