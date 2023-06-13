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
public:
    int getMinimumDifference(TreeNode* root) {
 		stack<TreeNode*> st;
 		int min=INT_MAX;
 		TreeNode *cur=root;
 		TreeNode *pre=NULL;
 		while(cur!=NULL||!st.empty()){
 			if(cur!=NULL){
 				st.push(cur);
 				cur=cur->left;
			}
			else{
				cur=st.top();
				st.pop();
				if(pre!=NULL&&abs(cur->val-pre->val)<min){
					min=abs(cur->val-pre->val);
				}
				pre=cur;
				cur=cur->right;
			}
		}
    	return min;
    }
};

int main(){
	Solution sol;
	TreeNode *root,*ptr;

	root=new TreeNode(1);
	ptr=root;
	ptr->left=new TreeNode(0);
	ptr->right=new TreeNode(48);
	ptr=ptr->right;
	ptr->left=new TreeNode(12);
	ptr->right=new TreeNode(49);	

/*	root=new TreeNode(4);
	ptr=root;
	ptr->left=new TreeNode(2);
	ptr->right=new TreeNode(6);
	ptr=ptr->left;
	ptr->left=new TreeNode(1);
	ptr->right=new TreeNode(3);	*/
	
	int result;
	result=sol.getMinimumDifference(root);	
	cout << "result: " << result << endl;
	return 0;
}
