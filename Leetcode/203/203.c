/* ************************************************************************
> File Name:     203.c
> Author:        Jack Yang
> Created Time:  2023年04月25日 (週二) 21時28分49秒
> Description:   
 ************************************************************************/
#include<stdio.h>
#include<stdlib.h>

struct ListNode {
     int val;
     struct ListNode *next;
};

struct ListNode *myListNode(int x){
     struct ListNode *listnode=(struct ListNode*)malloc(sizeof(struct ListNode)); 
     listnode->val=x;
     listnode->next=NULL;
     return listnode;
}
struct ListNode* removeElements(struct ListNode* head, int val){
     if(head==NULL)return NULL;
     struct ListNode *dummyhead=myListNode(0);
     while(head!=NULL && head->val==val){
         head=head->next;
     }
     dummyhead->next=head;
     struct ListNode *ptr=NULL;
     ptr=dummyhead->next;
     struct ListNode *temp;
     temp=ptr;
     while(ptr!=NULL){
        while(ptr!=NULL && ptr->val==val){
            ptr=ptr->next;
            temp->next=ptr;
        }
        if(ptr!=NULL){
            temp=ptr;
            ptr=ptr->next;    
        }
     }
     temp=ptr=dummyhead;
     free(dummyhead);
     return head;
}

int main(int argc,char *argv[]){
     struct ListNode *head=myListNode(1);
     struct ListNode *ptr;
     ptr=head;
     ptr->next=myListNode(2);
     ptr=ptr->next;
     ptr->next=myListNode(6);
     ptr=ptr->next;
     ptr->next=myListNode(3);
     ptr=ptr->next;
     ptr->next=myListNode(4);
     ptr=ptr->next;
     ptr->next=myListNode(5);
     ptr=ptr->next;
     ptr->next=myListNode(6);
     struct ListNode *result;
     result=removeElements(head,6);
     while(result!=NULL){
            printf("%d ",result->val);
            result=result->next;
     }
     return 0;
}
