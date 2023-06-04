#include<bits/stdc++.h>
#include <stack>
using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):val(x),left(NULL),right(NULL){};
};

class Solution {
public:
    bool hasPathSum(TreeNode *root, int targetSum) {
    	stack<pair<TreeNode *,int>>st;
    	if(!root)return false;
  		st.push(pair<TreeNode *,int>(root,root->val));
  		while(!st.empty()){
			pair<TreeNode *,int>node=st.top();
			st.pop();
			if(!node.first->right&&!node.first->left){
				cout << "node.second: " << node.second << endl;
				if(node.second==targetSum){
					return true;
				}
			}
			if(node.first->right){
				st.push(pair<TreeNode *,int>(node.first->right,node.second+node.first->right->val));
			}
			if(node.first->left){
				st.push(pair<TreeNode *,int>(node.first->left,node.second+node.first->left->val));
			}
		}
		return false;
    }
};

int main(){
	Solution sol;
	TreeNode *root,*ptr;
	bool result;
	int targetSum;
	
	cin >> targetSum;
	
	root=new TreeNode(5);
	ptr=root;
	
	
/*	ptr->left=new TreeNode(2);
	ptr->right=new TreeNode(3);	*/
	
	
	ptr->left=new TreeNode(4);
	ptr->right=new TreeNode(8);
	ptr=ptr->left;
	ptr->left=new TreeNode(11);
	ptr=ptr->left;
	ptr->left=new TreeNode(7);
	ptr->right=new TreeNode(2);
	ptr=root;
	ptr=ptr->right;
	ptr->left=new TreeNode(13);
	ptr->right=new TreeNode(4);
	ptr=ptr->right;
	ptr->right=new TreeNode(1);
	
	
	
	result=sol.hasPathSum(root,targetSum);
	if(result){
		cout << "true";
	}
	else{
		cout << "false";
	}
	return 0;
}
