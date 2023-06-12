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
    bool isValidBST(TreeNode* root) {
		if(root->right&&root->right->val<=root->val){
			return false;
		}
		else if(root->left&&root->left->val>=root->val){
			return false;
		}	
		else{
			return true;
		}
		bool result=false;	
			
		result=isValidBST(root->left);
		if(!result)return false;
		result=isValidBST(root->right);
		if(!result)return false;
		return result;       
    }
};

int main(){
	Solution sol;
	TreeNode *root,*ptr;

	root=new TreeNode(2);
	ptr=root;
	ptr->left=new TreeNode(1);
	ptr->right=new TreeNode(3);

/*	root=new TreeNode(5);
	ptr=root;
	ptr->left=new TreeNode(1);
	ptr->right=new TreeNode(4);
	ptr=ptr->right;
	ptr->left=new TreeNode(3);
	ptr->right=new TreeNode(6);	*/
	
	bool result;
	result=sol.isValidBST(root);
	if(result)cout << "true" << endl;
	else cout << "false" << endl;
	
	return 0;
}
