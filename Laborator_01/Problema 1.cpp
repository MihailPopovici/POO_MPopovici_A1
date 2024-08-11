#include <iostream>
#include <cstring>

using namespace std;

int StrToInt(char str[]) {
	int rez = 0;
	for (int i = 0; i < strlen(str); i++) {
		rez = rez * 10 + (str[i] - '0');
	}
	return rez;
}

int main()
{
	FILE* fp;
	char str[100];
	if (fopen_s(&fp, "in.txt", "r") != 0) {
		perror("Eroare la deschiderea fisierului");
		return -1;
	}
	
	int sum = 0;
	while (fgets(str, 100, fp) != 0) {
		if (str[strlen(str) - 1] == '\n')
			str[strlen(str) - 1] = '\0';
		sum += StrToInt(str);
	}
	printf("\n\n%d\n\n", sum);
	fclose(fp);
}


