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
	TreeNode *sol(TreeNode *root,TreeNode *node1,TreeNode *node2){
		if(root==node1||root==node2||root==NULL){
			return root;
		}
		TreeNode *left=sol(root->left,node1,node2);
		if(left!=NULL&&left->val==node1->val&&node2->val>root->val){
			return root;	
		}
		else if(left!=NULL&&left->val==node1->val&&node2->val<root->val){
			return left;
		}
		TreeNode *right=sol(root->right,node1,node2);
		if(left!=NULL&&right!=NULL)return root;
		if(right!=NULL&&right->val==node2->val&&node1->val<root->val){
			return root;	
		}
		else if(right!=NULL&&right->val==node2->val&&node1->val>root->val){
			return right;
		}	
		if(left!=NULL&&right==NULL){
			return left;
		}
		else if(left==NULL&&right!=NULL){
			return right;
		}
		return NULL;	
	}
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		TreeNode *result;
		if(p->val>q->val){
			result=sol(root,q,p);
		}
		else{
			result=sol(root,p,q);
		}
		return result;
    }
};

int main(){
	Solution sol;
	TreeNode *root,*ptr,*p,*q;

	root=new TreeNode(6);
	ptr=root;
	ptr->left=new TreeNode(2);
	
	p=ptr->left;
	
	ptr->right=new TreeNode(8);
	
//	q=ptr->right;
	
	ptr=ptr->left;	
	ptr->left=new TreeNode(0);
	ptr->right=new TreeNode(4);
	
//	q=ptr->right;
	
	ptr=ptr->right;
	
	ptr->left=new TreeNode(3);
	ptr->right=new TreeNode(5);	
	
//	q=ptr->right;

	ptr=root;
	ptr=ptr->right;
	ptr->left=new TreeNode(7);
	
//	p=ptr->left;

	ptr->right=new TreeNode(9);	
		
	q=ptr->right;
	
	
	
	TreeNode *result;
	result=sol.lowestCommonAncestor(root,p,q);
	cout << "result: " << result->val;
	return 0;
}
