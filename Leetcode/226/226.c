/* ************************************************************************
> File Name:     226.c
> Author:        Jack Yang
> Created Time:  2023年05月01日 (週一) 23時14分23秒
> Description:   Invert Binary Tree 
 ************************************************************************/
#include<stdio.h>
#include<stdlib.h>
struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
};
struct TreeNode* NewNode(int x){
     typedef struct TreeNode TreeNode;
     TreeNode *node=(TreeNode *)malloc(sizeof(TreeNode));
     node->val=x;
     node->left=NULL;
     node->right=NULL;
     return node;
}
struct TreeNode *solution(struct TreeNode* ptr){
     typedef struct TreeNode TreeNode;
     if(ptr==NULL)return ptr;
 //    printf("%d ",ptr->val);
 /*    if(ptr->left && ptr->right){
         TreeNode *tmp;
         tmp=ptr->left;
         ptr->left=ptr->right;
         ptr->right=tmp;
     }*/
     solution(ptr->left);
     solution(ptr->right);
     if(ptr->left && ptr->right){
         TreeNode *tmp;
         tmp=ptr->left;
         ptr->left=ptr->right;
         ptr->right=tmp;
     }
     return ptr;
}
struct TreeNode* invertTree(struct TreeNode* root){
     typedef struct TreeNode TreeNode;
     TreeNode *result;
     result=solution(root);
     return result;
}
void TravelTree(struct TreeNode* ptr){
     typedef struct TreeNode TreeNode;
     if(ptr==NULL)return;
     printf("%d ",ptr->val);
     TravelTree(ptr->left);
     TravelTree(ptr->right);
}
int main(int argc,char *argv[]){
     typedef struct TreeNode TreeNode;
     TreeNode *root=NewNode(4);
     TreeNode *ptr=root;
     ptr->left=NewNode(2);
     ptr->right=NewNode(7);
     ptr=ptr->left;
     ptr->left=NewNode(1);
     ptr->right=NewNode(3);
     ptr=root;
     ptr=ptr->right;
     ptr->left=NewNode(6);
     ptr->right=NewNode(9);
     root=invertTree(root);
     TravelTree(root);
     return 0;
}
