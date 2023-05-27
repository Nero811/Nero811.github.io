/* ************************************************************************
> File Name:     232.c
> Author:        Jack Yang
> Created Time:  2023年04月24日 (週一) 20時45分00秒
> Description:   
 ************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct {
    int stackInTop,stackOutTop;
    int stackIn[100],stackOut[100];
} MyQueue;


MyQueue* myQueueCreate() {
    MyQueue* queue=(MyQueue*)malloc(sizeof(MyQueue));
    queue->stackInTop=0;
    queue->stackOutTop=0;
    return queue;
}

void myQueuePush(MyQueue* obj, int x) {
    obj->stackIn[(obj->stackInTop)++]=x;
}

int myQueuePop(MyQueue* obj) {
    int stackinTop=obj->stackInTop;
    int stackoutTop=obj->stackOutTop;
    if(stackoutTop==0){
         while(stackinTop>0){
                obj->stackOut[stackoutTop++]=obj->stackIn[--stackinTop];
         }
    }
    int top=obj->stackOut[--stackoutTop];
    while(stackoutTop>0){
        obj->stackIn[stackinTop++]=obj->stackOut[stackoutTop--];
    }
    obj->stackInTop=stackinTop;
    obj->stackOutTop=stackoutTop;
    return top;
}

int myQueuePeek(MyQueue* obj) {
    return obj->stackIn[0];
}

bool myQueueEmpty(MyQueue* obj) {
   if(obj->stackInTop==0&&obj->stackOutTop==0)return true;
   else return false;
}

void myQueueFree(MyQueue* obj) {
    free(obj);    
}

int main(int argc,char * argv[]){
    MyQueue* obj = myQueueCreate();
    myQueuePush(obj,1);
    myQueuePush(obj,2);
    printf("%d\n",myQueuePeek(obj));
    printf("%d\n",myQueuePop(obj));
    if(myQueueEmpty(obj)){
        printf("true");
    }
    else{
        printf("false");
    }
    return 0;
}
