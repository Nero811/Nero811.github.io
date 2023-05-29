#include<bits/stdc++.h>
#include<queue>
#include<vector>
using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):val(x),left(NULL),right(NULL){};
};


class Solution {
public:
    int countNodes(TreeNode* root) {
    	int result=0;
        queue<TreeNode*>que;
        if(!root)return result;
        que.push(root);
        result++;
        while(!que.empty()){
        	int size=que.size();
        	for(int i=0;i<size;i++){
        		TreeNode *node=que.front();
				que.pop();
				if(node->left){
					que.push(node->left);
					result++;
				}
				if(node->right){
					que.push(node->right);
					result++;
				}
			}
		}
		return result;
    }
};

int main(){
	Solution sol;
	TreeNode *root,*ptr;
	root=new TreeNode(1);
	ptr=root;
	
	ptr->left=new TreeNode(2);
	ptr->right=new TreeNode(3);
	ptr=ptr->left;
	ptr->left=new TreeNode(4);
	ptr->right=new TreeNode(5);	
	ptr=root;
	ptr=ptr->right;
	ptr->left=new TreeNode(6);	
	
	
/*	ptr->left=new TreeNode(2);
	ptr->right=new TreeNode(2);
	ptr=ptr->left;
	ptr->right=new TreeNode(3);
	ptr=root;
	ptr=ptr->right;	
	ptr->right=new TreeNode(3);*/
	
	int result;
	result=sol.countNodes(root);
	cout << "result: " << result << endl;
	
	return 0;
}
