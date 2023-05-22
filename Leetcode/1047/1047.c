/* ************************************************************************
> File Name:     1047.c
> Author:        Jack Yang
> Created Time:  2023年05月01日 (週一) 17時58分44秒
> Description:   Remove All Adjacent Duplicates In String 
 ************************************************************************/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char * removeDuplicates(char * s){
    int strSize=strlen(s);
    if(strSize==1)return s;
    char *stack=(char *)malloc(sizeof(char)*(strSize+1));
    int i;
    stack[0]=s[0];
    int stackTop=1;
    for(i=1;i<strSize;i++){
        if(stackTop==0 && !stack[0]){
           stack[stackTop++]=s[i];
        }
        else if(stack[stackTop-1]!=s[i]){
           stack[stackTop++]=s[i];
        }
        else if(stackTop>0 && stack[stackTop-1]==s[i]){
            stackTop--;
        }
    }
    stack[stackTop] = '\0';
    return stack;
}
int main(int argc,char *argv[]){
//    char s[]={'a','b','b','a','c','a','\0'};
    char s[]={'a','a','a','a','a','a','a','a','\0'};
    char *result;
    result=removeDuplicates(s);
    int len=strlen(result);
    int i;
    for(i=0;i<len;i++){
        printf("%c ",result[i]);
    }
    return 0;
}
