/* ************************************************************************
> File Name:     977.c
> Author:        Jack Yang
> Created Time:  2023年04月28日 (週五) 22時58分04秒
> Description:   
 ************************************************************************/
#include<stdio.h>
#include<stdlib.h>
int* sortedSquares(int* nums, int numsSize, int* returnSize){
        int i=0;
        int j=numsSize-1;
        int k=j;
        *returnSize=numsSize;
        int *result=(int *)malloc(sizeof(int)*numsSize);
        while(i<=j){
            if((nums[i]*nums[i])>(nums[j]*nums[j])){
                    result[k--]=(nums[i]*nums[i]);
                    i++;
            }
            else{
                result[k--]=(nums[j]*nums[j]);
                j--;
            }
        }
        return result;
}

int main(int argc,char *argv[]){
        int nums[5]={-4,-1,0,3,10};
        int *result=(int *)malloc(sizeof(int)*5);
        int returnSize=0;
        result=sortedSquares(nums,5,&returnSize);
        int i;
        for(i=0;i<returnSize;i++){
                printf("%d ",result[i]);
        }
        return 0;
}
