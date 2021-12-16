#include <stdio.h>
#include <conio.h>
#include <string.h>
#define TXT 1024
#define WORD 30

//////Part 1 - Gematric////////
int CharToNum(char c){//change char to number
    int num;
    int cn = (int)c;
    if(cn>64&&cn<91){num=cn-64;}
    if(cn>96&&cn<123){num=cn-96;}
    if((cn<64||cn>123)||(cn>90&&cn<97)){num=0;}
    return num;
}

int WordCalc(char *c){//change word to number by summing
    int ans=0;
    int s = 0;
    for (int i = 0; i < strlen(c); i++) {
        s = CharToNum(c[i]);
        ans = ans+s;
    }
    return ans;

}
//////Part 2 - Atbash////////
char AtbChar(char c){//change char to opposite
    char atb;
    int cn = (int)c;
    int num=0;
    if(cn>64&&cn<91){num=cn+26-CharToNum(c)-(1*(CharToNum(c)-1));}
    if(cn>96&&cn<123){num=cn+26-CharToNum(c)-(1*(CharToNum(c)-1));}
    if((cn<64||cn>123)||(cn>90&&cn<97)){num=NULL;}
    atb=(char)num;
    return atb;
}

char AtbWord(char *c){//change word to opposite
    int len = strlen(c);
    char ans[len];//string
    char s;//char

    for (int i = 0; i < len; i++) {//runs over the word
        s = AtbChar(c[i]);
        strncat(ans, &s, 1);
    }
    return ans;
}










void main()
{
    char str[WORD];
    char txt[TXT];
    gets(str);
    gets(txt);
    //////Part 1 - Gematric////////
    int wordGem = WordCalc(str);
    while(txt!='~'){
        int i = 0;
        int count = 0;
        if(CharToNum(txt[0])!=0){
            while(count < wordGem) {
                count += txt[i];
                i++;
            }
        }
        else {i++;}



        }

    }






    printf("Gematria Sequences: %s\n",gematry());
    printf("Atbash Sequences: %s\n",gematry());
    printf("Anagram Sequences: %s\n",gematry());


}