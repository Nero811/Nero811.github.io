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
	void sol(TreeNode *ptr,vector<int> &result){
		if(ptr==NULL){
			return;
		}
		result.push_back(ptr->val);
		if(ptr->left)sol(ptr->left,result);
		if(ptr->right)sol(ptr->right,result);
	}
    int countNodes(TreeNode* root) {
    	int level=0;
    	vector<int>result;
    	sol(root,result);
 
		return result.size();
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
