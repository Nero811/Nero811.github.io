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
    int minDepth(TreeNode* root) {
		queue<TreeNode*>que;
		int level=0;
		int min=INT_MAX;
		if(root==NULL){
			return 0;
		}
		else if(root->left==NULL&&root->right==NULL){
			return 1;
		}
		que.push(root);
		while(!que.empty()){
			int size=que.size();
			level++;			
			for(int i=0;i<size;i++){
				bool node_left,node_right;
				TreeNode*node=que.front();
				que.pop();
				if(node->left){
					que.push(node->left);
					node_left=false;
				}
				else{
					node_left=true;
				}				
				if(node->right){
					que.push(node->right);
					node_right=false;
				}
				else{
					node_right=true;
				}
				if(node_left&&node_right){
					int val=level-0;
					if(val<min&&level!=1){
						min=val;
					}	
				}
			}
		}
		return min;
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
