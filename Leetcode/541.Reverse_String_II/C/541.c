/* ************************************************************************
> File Name:     541.c
> Author:        Jack Yang
> Created Time:  2023年04月29日 (週六) 11時18分00秒
> Description:   Reverse String II   
 ************************************************************************/
#include<stdio.h>
#include<string.h>
void reverseString(char* s,int start,int end){
    int i=start;
    int j=end;
    char temp;
    while(i<=j){
       temp=s[i];
       s[i++]=s[j];
       s[j--]=temp;
    }
}

char * reverseStr(char * s, int k){
        int slowidx;
        int i;
        int j;
        int cnt=1;
        if(strlen(s)==1 && k>=1)return s;
        for(i=0,slowidx=0;i<strlen(s);i++){
            if(cnt==2*k){
                reverseString(s,slowidx,slowidx+k-1);
                slowidx=i+1;
                cnt=0;
            }
            else if(strlen(s)-slowidx < 2*k && strlen(s)-slowidx >= k){
                reverseString(s,slowidx,slowidx+k-1);
                break;
            }
            else if(strlen(s)-slowidx<k){
                reverseString(s,slowidx,strlen(s)-1);
                break;
            }
            cnt++;
        }            
        return s;
}

int main(int argc,char *argv[]){
        char s[]={'a','b','c','d','e','f','g','\0'};
        int k=2;
        reverseStr(s,k);
        int i;
        for(i=0;i<strlen(s);i++){
            printf("%c ",s[i]);
        }
        return 0;
}
