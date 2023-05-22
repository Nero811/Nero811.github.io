/* ************************************************************************
> File Name:     190.c
> Author:        Jack Yang
> Created Time:  2023年05月04日 (週四) 22時48分03秒
> Description:   Reverse Bits 
 ************************************************************************/
#include<stdio.h>
#include<stdint.h>
uint32_t reverseBits(uint32_t n) {
        uint32_t result=0;   
        int i=0;
        while(i<32){
           result <<= 1; 
           result |= (n & 1 ? 1 : 0);
          // if((n & 1) == 1) result|=1;
           n >>=1;
           i++;
        }
        return result;
}
int main(int argc,char *argv[]){
        uint32_t n=0xFFFFFFFD;
        uint32_t result=reverseBits(n);
        printf("%u",result);
        return 0;
}
