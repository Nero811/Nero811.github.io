/* ************************************************************************
> File Name:     136.c
> Author:        Jack Yang
> Created Time:  2023年05月04日 (週四) 21時27分02秒
> Description:   Single Number
 ************************************************************************/
#include<stdio.h>
int singleNumber(int* nums, int numsSize){
    if(numsSize==1)return nums[0];
    int i;
    for(i=1;i<numsSize;i++){
        nums[i]^=nums[i-1];
    }
    return nums[numsSize-1];
}
int main(int argc,char *argv[]){
    //int nums[5]={4,1,2,1,2};
    //int val=4;
    int nums[3]={2,2,1}; 
    int val=3;
    int result;
    result=singleNumber(nums,val);
    printf("%d",result);
    return 0;
}
