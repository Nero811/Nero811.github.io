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
    int findBottomLeftValue(TreeNode* root) {
		queue<TreeNode *>que;
		if (!root)return 0;
		else if(!root->left&&!root->right)return root->val;
		
		que.push(root);
		int result;
		int level=0;
		int depth=0;
		while(!que.empty()){
			int size=que.size();
			level++;
			for(int i=0;i<size;i++){
				TreeNode *node=que.front();
				que.pop();
				if(depth<level){
					depth=level;
					result=node->val;
				}
				if(node->left)que.push(node->left);
				if(node->right)que.push(node->right);
			}
		}
		cout << "result: " << result << endl; 
        return result;
    }
};

int main(){
	Solution sol;
	TreeNode *root,*ptr;
	root=new TreeNode(3);
	ptr=root;
	ptr->left=new TreeNode(1);
	ptr->right=new TreeNode(5);
	ptr=ptr->left;
	ptr->left=new TreeNode(0);
	ptr->right=new TreeNode(2);
	ptr=root;
	ptr=ptr->right;
	ptr->left=new TreeNode(4);
	ptr->right=new TreeNode(6);
	
	
/*	ptr=root;
	ptr->left=new TreeNode(2);
	ptr->right=new TreeNode(3);
	ptr=ptr->left;
	ptr->left=new TreeNode(4);
	ptr=root;
	ptr=ptr->right;
	ptr->left=new TreeNode(5);
	ptr->right=new TreeNode(6);
	ptr=ptr->left;
	ptr->left=new TreeNode(7);*/
	
	
	sol.findBottomLeftValue(root);

	return 0;
}
