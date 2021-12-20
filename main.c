#include <stdio.h>
#include <conio.h>
#include <string.h>
#define TXT 1024
#define WORD 30

int main()
{
    char str[WORD]={};
    char txt[TXT]={};
    getWord(str);
    getText(txt);
    int sum=WordCalc(str);
     printf("Gematria Sequences: ");
    Gematry(sum, txt);
    printf("\nAtbash Sequences: ");
    Atbash_Sequences(str, txt);
    printf("\nAnagram Sequences: ");
    Anagram(str, txt);
    return 0;
}
