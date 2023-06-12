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
	void TravelTree(TreeNode *root,vector<int> &v1){
		if(!root)return;
		TravelTree(root->left,v1);
		v1.push_back(root->val);
		TravelTree(root->right,v1);
	} 
    bool isValidBST(TreeNode* root) {
    	vector<int>v1;
		TravelTree(root,v1);
		for(int i=0;i<v1.size()-1;i++){
			if(v1[i+1]<=v1[i]){
				return false;
			}
		}
		return true;       
    }
};

int main(){
	Solution sol;
	TreeNode *root,*ptr;

/*	root=new TreeNode(2);
	ptr=root;
	ptr->left=new TreeNode(1);
	ptr->right=new TreeNode(3);*/

	root=new TreeNode(5);
	ptr=root;
	ptr->left=new TreeNode(1);
	ptr->right=new TreeNode(4);
	ptr=ptr->right;
	ptr->left=new TreeNode(3);
	ptr->right=new TreeNode(6);	
	
	bool result;
	result=sol.isValidBST(root);
	if(result)cout << "true" << endl;
	else cout << "false" << endl;
	
	return 0;
}
