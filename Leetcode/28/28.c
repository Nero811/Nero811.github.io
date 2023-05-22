/* ************************************************************************
> File Name:     28.c
> Author:        Jack Yang
> Created Time:  2023年04月30日 (週日) 20時04分01秒
> Description:   Find the Index of the First Occurrence in a String 
 ************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void next(char *str,int *nextTable){
    int i;
    int j=0;
    int len=strlen(str);
    nextTable[0]=0;
    for(i=1;i<len;i++){
        while(j>0 && str[i]!=str[j]){
            j=nextTable[j-1];
        }
        if(str[i]==str[j]){
            j++;
        }
        nextTable[i]=j;
    }
   /* for(i=0;i<len;i++){
        printf("%d ",nextTable[i]);
    }*/
}    

int strStr(char * haystack, char * needle){
    int len=strlen(haystack);
    int len2=strlen(needle);
    if (len<len2)return -1;
    int result=0;
    int *nextTable=(int*)calloc(len2,sizeof(int));
    next(needle,nextTable);
    int i;
    int j=0;
    for(i=0;i<len;i++){
        while(j >0 && haystack[i]!=needle[j]){
            j=nextTable[j-1];
        }
        if(haystack[i]==needle[j]){
            j++;
        }
        if(j==len2){
            free(nextTable);
            return i+1-j;
        }
            
    }
    free(nextTable);
    return -1;
}

int main(int argc,char *argv[]){
    //char haystack[]={'s','a','d','b','u','t','s','a','d','\0'};
    //char needle[]={'s','a','d','\0'};
    char haystack[]={'l','e','e','t','c','o','d','e','\0'};
    char needle[]={'l','e','e','t','o','\0'};
    int result;
    result=strStr(haystack,needle);
    printf("%d ",result);
    return 0;
}
