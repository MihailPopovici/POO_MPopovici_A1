#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int strToInt(char s[]) {
    int rez = 0, p = 1;
    for (int i = strlen(s) - 1; i >= 0; i--) {
        rez = rez + p * (s[i] - '0');
        p *= 10;
    }
    return rez;
}

int main()
{
    FILE* fp;
    char str[100];
    if (fopen_s(&fp, "init.txt", "r")!=0) {
        perror("Eroare la deschiderea fisierului");
        return (-1);
    }
    else {
        int sum = 0;
        while (fgets(str, 100, fp) != NULL) {
            if(str[strlen(str)-1]=='\n')
                str[strlen(str) - 1] = '\0';
            sum += strToInt(str);
        }
        printf("\n\n%d\n\n", sum);
    }
    fclose(fp);
}
