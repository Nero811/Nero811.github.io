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
	TreeNode * sol(TreeNode* root, TreeNode* p, TreeNode* q){
		if(root==p||root==q||root==NULL){
			return root;
		}				
	//	cout << "root: " << root->val << endl;
		TreeNode *left=sol(root->left,p,q);	
		TreeNode *right=sol(root->right,p,q);
		if(left!=NULL&&right!=NULL)return root;
		if(left!=NULL&&right==NULL){
	//		cout << "left: " << left->val << endl; 
			return left;
		}
		else if(left==NULL&&right!=NULL){
			return right;
		}							
		else if(left==NULL&&right==NULL){
			return NULL;
		}	
		return NULL;
	}
    TreeNode * lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode *result;
        result=sol(root,p,q);
        return result;
    }
};

int main(){
	Solution sol;
	TreeNode *root,*ptr,*p,*q;

	root=new TreeNode(3);
	ptr=root;
	ptr->left=new TreeNode(5);
	p=ptr->left;
	ptr->right=new TreeNode(1);
	q=ptr->right;
	ptr=ptr->left;	
	ptr->left=new TreeNode(6);
	ptr->right=new TreeNode(2);
	ptr=ptr->right;
	ptr->left=new TreeNode(7);
	ptr->right=new TreeNode(4);	
//	q=ptr->right;
	ptr=root;
	ptr=ptr->right;
	ptr->left=new TreeNode(0);
//	p=ptr->left;
	ptr->right=new TreeNode(8);		
//	q=ptr->right;
	
/*	root=new TreeNode(4);
	ptr=root;
	ptr->left=new TreeNode(2);
	ptr->right=new TreeNode(6);
	ptr=ptr->left;
	ptr->left=new TreeNode(1);
	ptr->right=new TreeNode(3);	*/
	TreeNode *result;
	result=sol.lowestCommonAncestor(root,p,q);
	cout << "result: " << result->val;
	return 0;
}
