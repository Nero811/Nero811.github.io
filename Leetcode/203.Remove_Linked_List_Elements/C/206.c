/* ************************************************************************
> File Name:     206.c
> Author:        Jack Yang
> Created Time:  2023年04月26日 (週三) 21時01分07秒
> Description:   
 ************************************************************************/
#include<stdio.h>
#include<stdlib.h>

struct ListNode {
        int val;
        struct ListNode *next;
};

struct ListNode* MakeList(int x){
        struct ListNode *node=(struct ListNode *)malloc(sizeof(struct ListNode));
        node->val=x;
        node->next=NULL;
        return node;
}

struct ListNode* reverseList(struct ListNode* head){
        typedef struct ListNode ListNode;
        if(head==NULL)return NULL;
        ListNode *dummyhead=MakeList(0);
        dummyhead->next=head;
        ListNode *cur;
        ListNode *tmp;
        ListNode *ahead;
        cur=dummyhead->next;
        ahead=cur->next;
        tmp=NULL;
        while(cur!=NULL){
            cur->next=tmp;
            tmp=cur;
            cur=ahead;
            if(ahead)ahead=ahead->next;
        }
        head=tmp;
        ahead=tmp=cur=dummyhead;
        free(dummyhead);
        return head;
}

int main(int argc,char *argv[]){
        struct ListNode *head=MakeList(1);
        head->next=MakeList(2);
        head->next->next=MakeList(3);
        head->next->next->next=MakeList(4);
        head->next->next->next->next=MakeList(5);
        struct ListNode *result;
        result=reverseList(head);
        while(result!=NULL){
            printf("%d ",result->val);
            result=result->next;
        }
        return 0;
}
