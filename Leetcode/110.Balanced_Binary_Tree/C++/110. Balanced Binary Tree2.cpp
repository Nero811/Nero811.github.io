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
	int sol(TreeNode *ptr,bool &result,int level){
		if(ptr==NULL){
			return 0;
		}								
		int left = sol(ptr->left,result,level);
		if(result==false){
			return 0;
		}		

		int	right = sol(ptr->right,result,level);

		if(result==false){
			return 0;
		}		
		cout << "left_level: " << left << endl;
		cout << "right_level: " << right << endl;			
		if(abs(left-right)>1){
			cout << "abs: " << abs(left-right) << endl;
			result=false;
		}		
		else{
			level=1+max(left,right);
		}		
		return level;			
	}
    bool isBalanced(TreeNode* root) {
		bool result=true;
		int level=0;
		sol(root,result,level);
		if(result){
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
	
/*	ptr->left=new TreeNode(9);
	ptr->right=new TreeNode(20);
	ptr=ptr->right;
	ptr->left=new TreeNode(15);
	ptr->right=new TreeNode(7);		*/
	
	
	ptr->left=new TreeNode(2);
	ptr->right=new TreeNode(2);
	ptr=ptr->left;
	ptr->left=new TreeNode(3);
	ptr->right=new TreeNode(3);
	ptr=ptr->left;
	ptr->left=new TreeNode(4);		
	ptr->right=new TreeNode(4);
	
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
