/* ************************************************************************
> File Name:     459.c
> Author:        Jack Yang
> Created Time:  2023年04月30日 (週日) 22時58分08秒
> Description:   Repeated Substring Pattern 
 ************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
void next(char *s,int *nextTable){
    int len=strlen(s);
    int i;
    int j=0;
    nextTable[0]=j;
    for(i=1;i<len;i++){
        while(j>0 && s[i]!=s[j]){
            j=nextTable[j-1];
        }
        if(s[i]==s[j]){
            j++;
        }
        nextTable[i]=j;
    }
}
bool repeatedSubstringPattern(char * s){
    int len=strlen(s);
    int *nextTable=(int*)calloc(len,sizeof(int));
    int i;
    int j=0;
    next(s,nextTable);
    return nextTable[len-1]>0 && nextTable[len-1]%(len-nextTable[len-1])==0 ? true : false;
}

int main(int argc,char *argv[]){
    char s[]={'a','b','c','a','b','c','a','b','c','a','b','c','\0'};
    if (repeatedSubstringPattern(s))printf("true");
    else printf("false");
    return 0;
}
