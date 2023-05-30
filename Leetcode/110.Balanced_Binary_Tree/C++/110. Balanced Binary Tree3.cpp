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
	int sol(TreeNode *node){
	    if (node == NULL) {
	        return 0;
	    }		
		int leftHeight = sol(node->left); // ��
		if (leftHeight == -1) return -1;
		int rightHeight = sol(node->right); // �k
		if (rightHeight == -1) return -1;
		cout << "leftHeight: " << leftHeight << endl;
		cout << "rightHeight: " << rightHeight << endl;
		int result;
		if (abs(leftHeight - rightHeight) > 1) {  // ��
		    result = -1;
		} else {
		    result = 1 + max(leftHeight, rightHeight); // �H?�e???��??��?���̤j����
		}
		return result;					
	}
    bool isBalanced(TreeNode* root) {
		bool result=true;
		int ans;
		ans=sol(root);
		if(result!=-1){
			cout << "true";
		}
		else{
			cout << "false";
		}
		return result;
    }
};

int main(){
	Solution sol;
	TreeNode *root,*ptr;
	root=new TreeNode(1);
	ptr=root;
	
	ptr->left=new TreeNode(9);
	ptr->right=new TreeNode(20);
	ptr=ptr->right;
	ptr->left=new TreeNode(15);
	ptr->right=new TreeNode(7);		
	
	
/*	ptr->left=new TreeNode(2);
	ptr->right=new TreeNode(2);
	ptr=ptr->left;
	ptr->left=new TreeNode(3);
	ptr->right=new TreeNode(3);
	ptr=ptr->left;
	ptr->left=new TreeNode(4);		
	ptr->right=new TreeNode(4);*/
	
/*	ptr->right=new TreeNode(2);
	ptr=ptr->right;
	ptr->right=new TreeNode(3);*/
	
/*	ptr->left=new TreeNode(2);
	ptr->right=new TreeNode(2);
	ptr=ptr->left;
	ptr->left=new TreeNode(3);
	ptr=ptr->left;
	ptr->left=new TreeNode(4);
	ptr=root;
	ptr=ptr->right;
	ptr->right=new TreeNode(3);
	ptr=ptr->right;
	ptr->right=new TreeNode(4);*/
	
	
	
	sol.isBalanced(root);

	
	return 0;
}
