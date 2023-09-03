#include<bits/stdc++.h>
#include<vector>
#include<queue>
using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):val(x),left(NULL),right(NULL){};
};

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {   
    	TreeNode *pre,*result;
    	if(root==NULL){
    		root=new TreeNode(val);
    		return root;
		}
    	result=root;
		while(root!=NULL){
			if(root->val>val){
				pre=root;
				root=root->left;
			}		
			else if(root->val<val){
				pre=root;
				root=root->right;
			}				
		}
		if(pre->val>val){
			pre->left=new TreeNode(val);
		}
		else if(pre->val<val){
			pre->right=new TreeNode(val);
		}				
		return result;
    }
};

int main(){
	Solution sol;
	TreeNode *root,*ptr,*p,*q;

	root=new TreeNode(10);
	ptr=root;
	ptr->left=new TreeNode(5);
	ptr->right=new TreeNode(14);
	ptr=ptr->left;	
	ptr->left=new TreeNode(3);
	ptr->right=new TreeNode(8);
	

	TreeNode *result;
	int val;
	cin >> val;
	result=sol.insertIntoBST(root,val);
	queue<TreeNode *>que;
	que.push(result);
	while(!que.empty()){
		int size=que.size();
		for(int i=0;i<size;i++){
			TreeNode *node=que.front();
			cout << node->val << " ";
			que.pop();
			if(node->left)que.push(node->left);
			if(node->right)que.push(node->right);
		} 
		cout << endl;
	}
	return 0;
}
