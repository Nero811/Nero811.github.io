/* ************************************************************************
> File Name:     104.c
> Author:        Jack Yang
> Created Time:  2023年05月05日 (週五) 21時38分36秒
> Description:   Maximum Depth of Binary Tree 
 ************************************************************************/
#include<stdio.h>
#include<stdlib.h>
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
typedef struct TreeNode TreeNode;

void sol(TreeNode *ptr,int level,int *result){
    if(ptr==NULL){
        if(level>*result){
            *result=level;
        }
        return;
    }
    sol(ptr->left,level+1,result);
    sol(ptr->right,level+1,result);
    return;
}

int maxDepth(struct TreeNode* root){
    if(root==NULL)return 0;
    int level=0;
    int result=0;
    sol(root,level,&result);
    return result;
}

TreeNode *NewNode(int x){
    TreeNode *node=(TreeNode *)malloc(sizeof(TreeNode));
    node->val=x;
    node->left=NULL;
    node->right=NULL;
}
int main(int argc,char *argv[]){
    TreeNode *root=NewNode(3); 
    TreeNode *ptr=root;
    ptr->left=NewNode(9);
    ptr->right=NewNode(20);
    ptr=ptr->right;
    ptr->left=NewNode(15);
    ptr->right=NewNode(7);
    int result=maxDepth(root);
    printf("%d",result);
    return 0;
}
