/* ************************************************************************
> File Name:     102.cpp
> Author:        Jack Yang
> Created Time:  2023年05月06日 (週六) 22時36分44秒
> Description:   Binary Tree Level Order Traversal 
 ************************************************************************/
#include<iostream>
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>result;
        if(!root)return result;
        queue<TreeNode *>que;
        que.push(root);
        while(!que.empty()){
            int size=que.size();
            vector<int>vec;
            for(int i=0;i<size;i++){
                TreeNode *node=que.front();
                que.pop();
                vec.push_back(node->val);
                if(node->left)que.push(node->left);
                if(node->right)que.push(node->right);
            }
            result.push_back(vec);
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
   vector<vector<int>>result;
   result=sol.levelOrder(root);
   for(vector<int> vec:result){
        for(int &i:vec){
            cout << i << " ";
        }
        cout << endl;
   }
   return 0;
}
