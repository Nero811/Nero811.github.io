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
	bool LEFT=false,RIGHT=false;	
public:
	TreeNode *find(TreeNode *root, int val){
		if(root==NULL||root->val==val){
			return root;
		}	
		if(root->val>val){
			pre=root;
			left=find(root->left,val);
			if(left!=NULL){
				if(!RIGHT){
					LEFT=true;
				}
				return pre;
			}
		}
		if(root->val<val){
			pre=root;
			right=find(root->right,val);
			if(right!=NULL){
				if(!LEFT){
					RIGHT=true;	
				}
				return pre;
			}			
		}
		return NULL;					
	}
    TreeNode* deleteNode(TreeNode* root, int key) {   
		if(!root)return NULL;	
		TreeNode *target;
		TreeNode *ptr;
		TreeNode *parent;
		TreeNode *pre=find(root,key);
 		if(pre==NULL){
			return root;
		}       
		if(LEFT){
			target=pre->left;
			if(target->left!=NULL&&target->right!=NULL){
				parent=target;
				target=target->left;
				ptr=target;
				while(ptr->right!=NULL){
					ptr=ptr->right;
				}
				ptr->right=parent->right;
				pre->left=target;
				if(root==pre){
					root=pre;
				}
			}
			else if(target->left!=NULL&&target->right==NULL){
				pre->left=target->left;
			}
			else if(target->left==NULL&&target->right!=NULL){
				pre->left=target->right;
			}
			else if(target->left==NULL&&target->right==NULL){
				pre->left=NULL;	
			}						
		}
		else if(RIGHT){
			target=pre->right;
			if(target->left!=NULL&&target->right!=NULL){
				parent=target;
				target=target->left;
				ptr=target;
				while(ptr->right!=NULL){
					ptr=ptr->right;
				}
				ptr->right=parent->right;
				pre->right=target;
				if(root==pre){
					root=pre;
				}
			}
			else if(target->left!=NULL&&target->right==NULL){
				pre->right=target->left;
			}
			else if(target->left==NULL&&target->right!=NULL){
				pre->right=target->right;
			}
			else if(target->left==NULL&&target->right==NULL){
				pre->right=NULL;	
			}				
		}
		else{
			target=pre;
			if(target->left!=NULL&&target->right!=NULL){
				parent=target;
				target=target->left;
				ptr=target;
				pre=ptr;
				while(ptr->right!=NULL){
					ptr=ptr->right;
				}
				ptr->right=parent->right;
				root=pre;
			}
			else if(target->left!=NULL&&target->right==NULL){
				pre=target->left;
			}
			else if(target->left==NULL&&target->right!=NULL){
				pre=target->right;
			}
			else if(target->left==NULL&&target->right==NULL){
				pre=NULL;	
                root=pre;
			}		
            root=pre;	
		}
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
		
/*	root=new TreeNode(1);	
	ptr=root;
	ptr->right=new TreeNode(2);	*/

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
