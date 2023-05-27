/* ************************************************************************
> File Name:     bin.cpp
> Author:        Jack Yang
> Created Time:  2023年05月10日 (週三) 20時20分05秒
> Description:   Binary Tree Right Side View 
 ************************************************************************/
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode():val(0),left(nullptr),right(nullptr){};
    TreeNode(int x):val(x),left(nullptr),right(nullptr){};
};
typedef struct TreeNode TreeNode;
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
            vector<int>result;
            if(!root)return result;
            queue<TreeNode *>que;
            que.push(root);
            while(!que.empty()){
                int size=que.size();
                for(int i=0;i<size;i++){
                        TreeNode *node=que.front();
                        que.pop();
                        if(node->left)que.push(node->left);
                        if(node->right)que.push(node->right);
                        if(i==size-1 && node!=nullptr){
                            result.push_back(node->val);
                        }
                }
            }
            return result;
    }
};

int main(){
    Solution sol;
    TreeNode *root=new TreeNode(1);
    TreeNode *ptr=root;
    ptr->left=new TreeNode(2);
    ptr->right=new TreeNode(3);
    ptr=ptr->left;
    ptr->right=new TreeNode(5);
    ptr=root;
    ptr=ptr->right;
    ptr->right=new TreeNode(4);
    vector<int>result;
    result=sol.rightSideView(root);
    for(int &i:result){
        cout << i << " ";
    }
    return 0;
}
