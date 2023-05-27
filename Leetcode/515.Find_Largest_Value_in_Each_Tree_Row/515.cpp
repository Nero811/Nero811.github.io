/* ************************************************************************
> File Name:     515.cpp
> Author:        Jack Yang
> Created Time:  2023年05月13日 (週六) 16時06分35秒
> Description:   Find Largest Value in Each Tree Row 
 ************************************************************************/
#include<iostream>
#include<vector>
#include<queue>
#include <climits>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int>result;
        if(!root)return result;
        queue<TreeNode *>que;
        que.push(root);
        while(!que.empty()){
           int size=que.size();
           int Max=INT_MIN;
           for(int i=0;i<size;i++){
                TreeNode *node=que.front();
                que.pop();
                Max=max(Max,node->val);
                if(node->left)que.push(node->left);
                if(node->right)que.push(node->right);
           }
           result.push_back(Max);
        }
        return result;
    }
};

int main(){
    TreeNode *root=new TreeNode(1);
    root->left=new TreeNode(3);
    root->right=new TreeNode(2);
    TreeNode *ptr;
    ptr=root->left;
    ptr->left=new TreeNode(5);
    ptr->right=new TreeNode(3);
    ptr=root->right;
    ptr->right=new TreeNode(9);
    vector<int>result;
    Solution sol;
    result=sol.largestValues(root);
    for(int &i:result){
        cout << i << " ";
    }
    return 0;
}
