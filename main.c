
#include <stdio.h>
#include <string.h>
#define TXT 1024
#define WORD 30


int CharToNum(char c){//change char to number
    if('A' <= c && c<='Z'){//checkin where is the latter,uppercase?
       int temp=(c-'A'+1);
    return temp;}
    if('a' <= c && c<='z'){//or is the latter,lowercase
        int temp = (c-'a'+1);
    return temp;
    }
    
        return 0;
    
}

int WordCalc(char ch[]){//change word to number by summing charToNum
    int ans=0;
    int i=0;
    while(ch[i]) {//running over all the words
        ans += CharToNum(ch[i]);//summing it
        i++;
    }
    return ans;

}
void reset_print(char t[], int i, int k, char string[]){//reset values to print 
    int index = 0;
    for (; i <= k; i++) {
        string[index] = t[i];
        index++;
    }
    string[index] = 0;
}

char AtbChar(char c){//change char to opposite
    char atb;
    int cn = (int)c;
    int num=0;//looking for the place that we got
    if(cn>64&&cn<91){num=cn+26-CharToNum(c)-(1*(CharToNum(c)-1));}
    if(cn>96&&cn<123){num=cn+26-CharToNum(c)-(1*(CharToNum(c)-1));}
    if((cn<64||cn>123)||(cn>90&&cn<97)){num =  0;}
    atb=(char)num;
    return atb;
}
    void getText(char txt[TXT]){//function to get the text by the rools
    int count = 0;
    char ch = getchar();
    while(ch!='~'){
        txt[count] = ch;
        ch = getchar();
        count++;
    }
}
void getWord(char word[WORD]){//function to get the text by the rools
    int count = 0;
    char ch = getchar();
    while(ch!=' ' && ch!='\t' && ch!='\n'){
        word[count] = ch;
        ch = getchar();
        count++;
    }
}
int check1(char ch[], int i, int k, char words[]){//check one way in word for Atbash
    
    int counter = 0;
    for(;i <= k; i++){//looking forward
        
        if(ch[i] != ' '){
            if(ch[i] != words[counter]){//chek if contain
                return 0;
            }
            counter++;
        }
    }
    return 1;
}


int check2(char ch[], int i, int k, char words[]){//check from the other way
    int counter = 0;
    for(;k >= i; k--){//looking backward 

        if(ch[k] != ' '){
            if(ch[k] != words[counter]){//check if contain
                return 0;
            }
            counter++;
        }
    }
    return 1;
}
void Gematry(int val,char t[]){//Gematry function
    int t_len = strlen(t);
    char string[TXT] = {};
    for(int i=0;i<t_len;i++){
        while(CharToNum(t[i])==0){i++;}//when it is not a letter
       int cal = 0; int k=i;
        while(cal<val && k<t_len){
            cal += CharToNum(t[k]);//summing the Gematry
            if(cal==val){
                if(strlen(string)>0){
                printf("%s~",string);}
            reset_print(t,i,k,string);
            }
            k++;
        }
    }
    if(strlen(string)>0){
    printf("%s",string);
    }
}
char AtbWord(char *c){//change word to opposite
    int len = strlen(c);
    char ans[len];//string
    char s;//char

    for (int i = 0; i < len; i++) {//runs over the word
        s = AtbChar(c[i]);
        strncat(ans, &s, 1);
    }
    return *(ans);
}
void Atbash_se(char ch[]){////change word to opposite
     for (int i = 0; i < strlen(ch); i++) {
        if('a'<=ch[i] && ch[i]<='z'){//checking if it lowercase
            ch[i] = ('z'- ch[i] + 'a');//convert
        }
    if('A'<=ch[i] && ch[i]<='Z'){//checking if it uppercase
            ch[i] = ('Z'- ch[i] + 'A');//convert
        }
}
}

void Atbash_Sequences(char ch[],char words[]){//Atbash function
    char val[TXT]={}; 
    int t_len=strlen(words);
    char Atbash[strlen(ch)];
    strcpy(Atbash,ch);
    Atbash_se(Atbash);
    int sum = WordCalc(Atbash);
    
    for(int i=0;i<t_len;i++){
        while(words[i] == ' '){i++;}//when its empty
        int k=i;int temp=0;
        while(temp<sum && k<t_len){
            temp+=CharToNum(words[k]);//summing to Gematry
            if(sum==temp){
                 if(check1(words, i, k, Atbash) || check2(words, i, k, Atbash)){
//checking with the helper function if it contain
                if(strlen(val)>0){
                    printf("%s~",val);
                    printf("a");
                }
              reset_print(words,i,k,val);
        }
    }
    k++;
}
}
if(strlen(val)>0){
printf("%s",val);
printf("b");
}
}

void Anagram(char str[],char txt[]){//Anagram function
int flag=0;
for(int i=0;i<strlen(txt);i++){
    char new_word[strlen(txt)+1];
    strcpy(new_word,str);
    char temp_word[strlen(txt)-i+1];
    for(int j=0;j<strlen(txt)-i+1;j++){
        temp_word[j]='\0';}
        for(int j=i;j<strlen(txt);j++){
            if(CharToNum(txt[i]) !=0){
                char *pointer=strchr(new_word,txt[j]);
                if((txt[j]== ' ' || pointer!=NULL ) && strlen(new_word) != 0){
                    temp_word[j-i]=txt[j];}
                    else{break;}
                    if(pointer!=NULL){
                        int new_p=pointer- new_word;
                        for(int k=new_p+1;k<(strlen(new_word)+1);k++){
                            new_word[k-1]=new_word[k];
                        }
                    }
                    if(strlen(new_word)==0){
                        if(flag==0){
                            printf("%s",temp_word);
                        }
                        else{
                            printf("~%s",temp_word);
                        }
                        flag++;
                }
            }
        }
    }
}



int main()
{
    char str[WORD]={};//define
    char txt[TXT]={};
    
    getWord(str);//function to get by the rool of the assighment
    getText(txt);//function to get by the rool of the assighment
    
    int sum=WordCalc(str);//get the value number of the text
    
     printf("Gematria Sequences: ");
    Gematry(sum, txt);
    
    printf("\nAtbash Sequences: ");
    Atbash_Sequences(str, txt);
    
    printf("\nAnagram Sequences: ");
    Anagram(str, txt);
    
    return 0;
}
