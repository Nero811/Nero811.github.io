/* ************************************************************************
> File Name:     344.c
> Author:        Jack Yang
> Created Time:  2023年04月29日 (週六) 10時17分15秒
> Description:   Reverse String 
 ************************************************************************/
#include<stdio.h>
#include<string.h>
void reverseString(char* s, int sSize){
    int i=0;
    int j=sSize-1;
    char temp;
    while(i<=j){
       temp=s[i];
       s[i]=s[j];
       s[j]=temp;
       i++;
       j--;
    }
}
int main(int argc,char *argv[]){
    char s[]={'h','e','l','l','o','\0'};
    reverseString(s,strlen(s));
    int i;
    for(i=0;i<strlen(s);i++){
        printf("%c ",s[i]);
    }
    return 0;
}

