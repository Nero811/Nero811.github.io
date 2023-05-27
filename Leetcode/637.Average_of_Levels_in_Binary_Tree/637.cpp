/* ************************************************************************
> File Name:     637.cpp
> Author:        Jack Yang
> Created Time:  2023年05月11日 (週四) 21時23分22秒
> Description:   Average of Levels in Binary Tree 
 ************************************************************************/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode():val(0),left(nullptr),right(nullptr){};
    TreeNode(int x):val(x),left(nullptr),right(nullptr){};
};

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root){
            vector<double>result;
            if(!root)return result;
            queue<TreeNode *>que;
            que.push(root);
            while(!que.empty()){
                int size=que.size();
                double sum=0;
                for(int i=0;i<size;i++){
                    TreeNode *node=que.front();
                    que.pop();
                    sum+=node->val;
                    if(node->left)que.push(node->left);
                    if(node->right)que.push(node->right);
                }
                result.push_back(sum/size);
            }
            return result;
    }
};

int main(){
    Solution sol;
    TreeNode *root=new TreeNode(3);
    TreeNode *ptr=root;
    ptr->left=new TreeNode(9);
    ptr->right=new TreeNode(20);
    ptr=ptr->right;
    ptr->left=new TreeNode(15);
    ptr->right=new TreeNode(7);
    vector<double>result;
    result=sol.averageOfLevels(root);
    for(double d:result){
        cout << d << " ";
    }
    return 0;
}
