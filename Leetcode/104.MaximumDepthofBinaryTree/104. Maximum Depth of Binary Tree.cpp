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
		if(ptr==NULL){
			return;
		}	
		if(level>result){
			result=level;
		}
		sol(ptr->left,level+1,result);
		sol(ptr->right,level+1,result);
	}
	
    int maxDepth(TreeNode* root) {
        int level=0;
        int result=0;
        if(root==NULL){
        	return 0;	
		}
		else{
			sol(root,level,result);
		}
        return result+1;
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
