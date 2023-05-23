#include <bits/stdc++.h> 
#include <vector>
#include <queue>
using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):val(x),left(NULL),right(NULL){};
}; 

class Solution {
public:
	void sol(TreeNode* ptr,int level,int &result){
		bool ptr_left,ptr_right;
		if(ptr==NULL){
			return;
		}
		if(ptr->left==NULL){
			ptr_left=true;
		}
		else{
			ptr_left=false;
		}
		if(ptr->right==NULL){
			ptr_right=true;
		}
		else{
			ptr_right=false;
		}
		if(ptr_left&&ptr_right){
			if(level<result){
				result=level;
			}
		}	
		sol(ptr->left,level+1,result);
		sol(ptr->right,level+1,result);
	}
	
    int minDepth(TreeNode* root) {
        int level=1;
        int result=INT_MAX;
        if(root==NULL){
        	return 0;	
		}
		else{
			sol(root,level,result);
		}
        return result;
    }
};

int main(){
	TreeNode *root,*ptr;
	Solution sol;
	root=new TreeNode(1);
	ptr=root;
	ptr->left=new TreeNode(2);
	ptr->right=new TreeNode(3);
	ptr=ptr->left;
	ptr->left=new TreeNode(4);
	ptr=root->right;
	ptr->right=new TreeNode(7);


	int result=sol.minDepth(root);
	cout << "result: " << result << endl; 
	return 0;
}
