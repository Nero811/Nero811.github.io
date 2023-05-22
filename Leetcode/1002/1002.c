/* ************************************************************************
> File Name:     1002.c
> Author:        程序员Carl
> 微信公众号:    代码随想录
> Created Time:  2023年04月23日 (週日) 23時54分55秒
> Description:   
 ************************************************************************/
#include<stdio.h>

#include<stdlib.h>

#include<string.h>



void compare(int *hash,int *cur){

    int i;

    for(i=0;i<26;i++){

            if(hash[i]>cur[i]){

                hash[i]=cur[i];

            }

    }

}



char ** commonChars(char ** words, int wordsSize, int* returnSize){

    if(words[0]==NULL)return NULL;

	char **Result;
	
	Result=(char**)malloc(sizeof(char *)*100);

    int hash[27]={0};

    int cur[27]={0};

    int i;

    int j;

    for(i=0;i<strlen(words[0]);i++){
        hash[words[0][i]-'a']++;

    }

    for(i=1;i<wordsSize;i++){

        for(j=0;j<strlen(words[i]);j++){

            cur[words[i][j]-'a']++;

        }

        compare(hash,cur);

        memset(cur,0,sizeof(cur));

    }


    *returnSize=0;

    for(i=0;i<26;i++){

        while(hash[i]>0){
			char *result=(char*)malloc(sizeof(char)*2);			
			result[0]=i+97;
			result[1]='\0';
            Result[*returnSize]=result;

            hash[i]--;

            (*returnSize)++;

        }

    }

    return Result;

}



int main(int argc,char* argv[]){


    char word1[6]={'b','e','l','l','a','\0'};

    char word2[6]={'l','a','b','e','l','\0'};

    char word3[7]={'r','o','l','l','e','r','\0'};

    char **words;


    words=(char**)malloc(sizeof(char*)*3);

    words[0]=word1;

    words[1]=word2;

    words[2]=word3;

    int wordsSize=3;

    int returnSize=0;

    char **result;


    result=commonChars(words,wordsSize,&returnSize);

    int i;

    int j;

    for(i=0;i<returnSize;i++){

            printf("%s ",result[i]);

    }

    free(words);

    free(result);

    return 0;

}
