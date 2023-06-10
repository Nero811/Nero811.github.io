#include<bits/stdc++.h>
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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        TreeNode *result;
        queue<TreeNode *>que;
        if(!root1&&root2){
        	return root2;
		}
		else if(root1&&!root2){
			return root1;
		}
		else if(!root1&&!root2){
			return NULL;
		}
        que.push(root1);
        que.push(root2);
        while(!que.empty()){
        	TreeNode *node1=que.front();
        	que.pop();
        	TreeNode *node2=que.front();
			que.pop();   
			 
			node1->val+=node2->val;

			if(node1->left&&node2->left){
				que.push(node1->left);
				que.push(node2->left);
			}
			if(node1->right&&node2->right){
				que.push(node1->right);
				que.push(node2->right);				
			} 
			
			if(!node1->left&&node2->left){
				node1->left=node2->left;
			}
			if(!node1->right&&node2->right){
				node1->right=node2->right;
			}
		}
        return root1;
    }
};
int main(){
	Solution sol;
	TreeNode *root1,*root2,*ptr;

	root1=new TreeNode(1);
/*	ptr=root1;
	ptr->left=new TreeNode(3);
	ptr->right=new TreeNode(2);
	ptr=ptr->left;
	ptr->left=new TreeNode(5);*/
	
	root2=new TreeNode(2);
	ptr=root2;
	ptr->left=new TreeNode(1);
	ptr->right=new TreeNode(3);	
	ptr=ptr->left;
	ptr->right=new TreeNode(4);
	ptr=root2;
	ptr=ptr->right;
	ptr->right=new TreeNode(7);
	
	TreeNode * result;
	queue<TreeNode *>que;
	result=sol.mergeTrees(root1,root2);
	que.push(result);
	while(!que.empty()){
		int size=que.size();
		for(int i=0;i<size;i++){
			TreeNode *node=que.front();
			cout << "node: " << node->val << " ";
			que.pop();
			if(node->left)que.push(node->left);
			if(node->right)que.push(node->right);
		}
		cout << endl;
	}
	
	return 0;
}
