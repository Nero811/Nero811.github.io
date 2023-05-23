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
    int maxDepth(TreeNode* root) {
		queue<TreeNode*>que;
		int level=0;
		if(root!=NULL){
			que.push(root);
		}
		while(!que.empty()){
			int size=que.size();
			for(int i=0;i<size;i++){
				TreeNode*node=que.front();
				que.pop();
				if(node->left)que.push(node->left);
				if(node->right)que.push(node->right);
			}
			level++;
		}
		return level;
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
	ptr->right=new TreeNode(5);
	int result=sol.maxDepth(root);
	cout << "result: " << result << endl; 
	return 0;
}
