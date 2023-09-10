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
private:
	TreeNode *left=NULL,*right=NULL,*pre=NULL;
	bool new_root=false;	
public:
	TreeNode *sol(TreeNode *root, int val){
		if(root==NULL||root->val==val){
			return root;
		}
		if(root->val>val){
			pre=root;
			left=sol(root->left,val);
		}
		if(left!=NULL){
			TreeNode *cur;
			TreeNode *parent;
			TreeNode *left_parent;
			if(left->left!=NULL&&left->right!=NULL){
				cur=left;
				left=left->right;
				parent=left;
				while(left->left!=NULL){
					left_parent=left;
					left=left->left;
					new_root=true;
				}
				left->left=cur->left;
				pre->left=left;
				if(new_root){
					TreeNode *ptr=left;
					while(ptr->right!=NULL){
						ptr=ptr->right;
					}	
					ptr->right=parent;
					if(left_parent->left==left){
						left_parent->left=NULL;
					}
				}
			}
			else if(left->left!=NULL&&left->right==NULL){
				pre->left=left->left;
			}
			else if(left->left==NULL&&left->right!=NULL){
				pre->left=left->right;
			}
			else if(left->left==NULL&&left->right==NULL){
				pre->left=NULL;
			}
		}
		if(root->val<val){
			pre=root;
			right=sol(root->right,val);
		}
		if(right!=NULL){
			TreeNode *cur;
			TreeNode *parent;
			TreeNode *right_parent;			
			if(right->left!=NULL&&right->right!=NULL){
				cur=right;
				right=right->right;
				parent=right;
				while(right->left!=NULL){
					right_parent=right;
					right=right->left;
					new_root=true;
				}
				right->left=cur->left;
				pre->right=right;
				if(new_root){
					TreeNode *ptr=right;
					while(ptr->right!=NULL){
						ptr=ptr->right;
					}					
					ptr->right=parent;
					if(right_parent->left==right){
						right_parent->left=NULL;
					}
				}
			}
			else if(right->left!=NULL&&right->right==NULL){
				pre->right=right->left;
			}
			else if(right->left==NULL&&right->right!=NULL){
				pre->right=right->right;
			}
			else if(right->left==NULL&&right->right==NULL){
				pre->right=NULL;
			}
		}		
		return NULL;
	}
    TreeNode* deleteNode(TreeNode* root, int key) {   
		if(!root)return NULL;	
		if(root->val==key){
			TreeNode *cur;
			TreeNode *parent;
			TreeNode *root_parent;		
			if(root->left!=NULL&&root->right!=NULL){
				cur=root;
				root=root->right;
				parent=root;
				while(root->left!=NULL){
					root_parent=root;
					root=root->left;
					new_root=true;
				}
				root->left=cur->left;
				if(new_root){
					TreeNode *ptr=root;
					while(ptr->right!=NULL){
						ptr=ptr->right;
					}					
					ptr->right=parent;
					if(root_parent->left==root){
						root_parent->left=NULL;
					}
				}
			}
			else if(root->left!=NULL&&root->right==NULL){
				root=root->left;
			}
			else if(root->left==NULL&&root->right!=NULL){
				root=root->right;
			}
			else if(root->left==NULL&&root->right==NULL){
				root=NULL;	
			}
		}
		sol(root,key);
		return root;
    }
};

int main(){
	Solution sol;
	TreeNode *root,*ptr,*p,*q;

	root=new TreeNode(5);
	ptr=root;
	ptr->left=new TreeNode(3);
	ptr->right=new TreeNode(6);
	ptr=ptr->left;	
	ptr->left=new TreeNode(2);
	ptr->right=new TreeNode(4);
	ptr=root;
	ptr=ptr->right;
	ptr->right=new TreeNode(7);
	
	
/*	root=new TreeNode(50);
	ptr=root;
	ptr->left=new TreeNode(30);
	ptr->right=new TreeNode(70);
	ptr=ptr->left;	
	ptr->right=new TreeNode(40);
	ptr=root;
	ptr=ptr->right;
	ptr->left=new TreeNode(60);
	ptr->right=new TreeNode(80);*/
		

	TreeNode *result;
	int val;
	cin >> val;
	result=sol.deleteNode(root,val);
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
