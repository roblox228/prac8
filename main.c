#include <stdio.h>
#include <string.h>
#include <Windows.h>

unsigned long long factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    unsigned long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main() {
    SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
    char word[15];
    printf("Введіть слово: ");
    scanf("%s", word);

    int length = strlen(word);


    int count[256] = {0};

    for (int i = 0; i < length; i++) {

        count[(unsigned char)tolower(word[i])]++;
    }


    unsigned long long anagrams = factorial(length);


    for (int i = 0; i < 256; i++) {
        if (count[i] > 1) {
            anagrams /= factorial(count[i]);
        }
    }

    printf("Кількість анаграм: %llu\n", anagrams);

    return 0;
}
