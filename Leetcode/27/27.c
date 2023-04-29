/* ************************************************************************
> File Name:     27.c
> Author:        Jack Yang
> Created Time:  2023年04月28日 (週五) 21時08分10秒
> Description:   
 ************************************************************************/
#include<stdio.h>
#include<stdlib.h>

int removeElement(int* nums, int numsSize, int val){
        if(numsSize==0)return 0;
        int i;   
        int remain[100];
        int cnt=0;
        for(i=0;i<numsSize;i++){
            if(nums[i]!=val){
                remain[cnt++]=nums[i];
            }
        }
        for(i=0;i<cnt;i++){
            nums[i]=remain[i];
        }
        return cnt;
}

int main(int argc,char *argv[]){
        int nums[8]={0,1,2,2,3,0,4,2};
        int val=2;
        int result=removeElement(nums,8,val);
        int i;
        printf("%d\n",result);
        for(i=0;i<result;i++){
            printf("%d ",nums[i]);
        }
        return 0;
}
