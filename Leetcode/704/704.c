/* ************************************************************************
> File Name:     704.c
> Author:        Jack Yang
> Created Time:  2023年04月26日 (週三) 22時30分47秒
> Description:   
 ************************************************************************/
#include<stdio.h>
#include<stdlib.h>
int search(int* nums, int numsSize, int target){
        int i,j;
        if(numsSize==1 && nums[0]==target)return 0;
        else if(numsSize==1 && nums[0]!=target)return -1;
        i=0;
        j=numsSize-1;
        int mid=(i+j)/2;
        while(i<j){
            if(nums[mid]>target){
                j=mid-1;
            }
            else if(nums[mid]<target){
                i=mid+1;
            }
            mid=(i+j)/2;
            if(nums[mid]==target){
                return mid;
            }
        }
        return -1;
}

int main(int argc,char *argv[]){
    int nums[6]={-1,0,3,5,9,12};
    int target=9;
    printf("result: %d",search(nums,6,9));
    return 0;
}
