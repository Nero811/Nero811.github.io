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
	void sol(TreeNode *ptr,int &result){
		if(ptr==NULL){
			return;
		}
	//	cout << "ptr->val: " << ptr->val << endl;
		if(ptr->left!=NULL&&ptr->left->left==NULL&&ptr->left->right==NULL){
			//	cout << ptr->left->val;
				result+=ptr->left->val;
		}		
		sol(ptr->left,result);
		sol(ptr->right,result);
	}
    int sumOfLeftLeaves(TreeNode *root) {
    	int result=0;
    	sol(root,result);
    	cout << "result: " << result << endl; 
        return result;
    }
};

int main(){
	Solution sol;
	TreeNode *root,*ptr;
	root=new TreeNode(3);
	ptr=root;
	ptr->left=new TreeNode(9);
	ptr->right=new TreeNode(20);
	ptr=ptr->right;
	ptr->left=new TreeNode(15);
	ptr->right=new TreeNode(7);

	sol.sumOfLeftLeaves(root);

	return 0;
}
