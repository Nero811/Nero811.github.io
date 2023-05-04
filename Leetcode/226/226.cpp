/* ************************************************************************
> File Name:     226.cpp
> Author:        Jack Yang
> Created Time:  2023年05月04日 (週四) 20時36分25秒
> Description:   Invert Binary Tree C++ iteration 
 ************************************************************************/
#include<iostream>
#include<stack>
#include<queue>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
typedef TreeNode TreeNode;
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        stack<TreeNode *>st;
        if(root)st.push(root);
        else if(!root)return nullptr;
        TreeNode *cur=root;
        while(!st.empty()){
            TreeNode *node=st.top();
            st.pop();
            swap(node->right,node->left);
            if(node->right)st.push(node->right);
            if(node->left)st.push(node->left);
        }
        return root;
    }
};

int main(){
    Solution sol;
    TreeNode *root=new TreeNode(4);
    TreeNode *ptr=root;
    ptr->left=new TreeNode(2);
    ptr->right=new TreeNode(7);
    ptr=ptr->left;
    ptr->left=new TreeNode(1);
    ptr->right=new TreeNode(3);
    ptr=root;
    ptr->right=new TreeNode(7);
    ptr=ptr->right;
    ptr->left=new TreeNode(6);
    ptr->right=new TreeNode(9);
    root=sol.invertTree(root);
    queue<TreeNode *>que;
    que.push(root);
    while(!que.empty()){
        TreeNode *node;
        node=que.front();
        que.pop();
        cout << node->val << endl;
        if(node->left)que.push(node->left);
        if(node->right)que.push(node->right);
    }
    return 0;
}
