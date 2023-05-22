/* ************************************************************************
> File Name:     20.c
> Author:        Jack Yang
> Created Time:  2023年05月01日 (週一) 09時58分45秒
> Description:   Valid Parentheses 
 ************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
struct _list{
    char ch;
    struct _list *next;
};
typedef struct _list list;

list *MakeList(char x){
    list *node=(list *)malloc(sizeof(list));
    node->ch=x;
    node->next=NULL;
    return node;
}
list *StackPush(list *head,char x){
    if(head==NULL){
        head=MakeList(x);
        return head;
    }
    list *ptr=head;
    while (ptr->next!=NULL){
        ptr=ptr->next;
    }
    ptr->next=MakeList(x);
    return head;
}
list *StackPOp(list *head){
    if(head->next==NULL)return NULL;
    list *ptr=head;
    list *tmp;
    while(ptr->next!=NULL){
        tmp=ptr;
        ptr=ptr->next;
    }
    tmp->next=NULL;
    return head;
}
char Top(list *head){
    if(head==NULL)return 'a';
    list *ptr=head;
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    return ptr->ch;
}
bool isValid(char * s){
    int len=strlen(s);
    int i;
    char ch;
    char top;
    if(len<2)return false;
    list *head=NULL;
    for(i=0;i<len;i++){
        ch=s[i];
        if(ch=='(' || ch=='[' || ch=='{'){
            head=StackPush(head,ch);
        }
        else if((ch==')' && Top(head)=='(') || (ch==']' && Top(head)=='[') || (ch=='}' && Top(head)=='{')){
            head=StackPOp(head);
        }
        else if((ch==')' && Top(head)!='(') || (ch==']' && Top(head)!='[') || (ch=='}' && Top(head)!='{')){
            return false;
        }
    }
    if(head!=NULL)return false;
    return true;
}

int main(int argc,char *argv[]){
    // char s[]={'(',')','[',']','{','}','\0'};
     char s[]={'s',']','\0'};
     if(isValid(s))printf("true");
     else printf("false");
     return 0;
}
