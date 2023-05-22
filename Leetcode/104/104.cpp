/* ************************************************************************
> File Name:     104.cpp
> Author:        Jack Yang
> Created Time:  2023年05月05日 (週五) 20時48分03秒
> Description:   Maximum Depth of Binary Tree  
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
    int maxDepth(TreeNode* root) {
        if(!root)return 0;
        queue<TreeNode *>que;
        que.push(root);
        int level=0;
        while(!que.empty()){
            int size=que.size();
            level++;
            for(int i=0;i<size;i++){
                TreeNode *node=que.front();
                que.pop();
                if(node->left)que.push(node->left);
                if(node->right)que.push(node->right);
            }
        }
        return level;
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
    int result=sol.maxDepth(root);
    cout << result << endl;
    return 0;
}
