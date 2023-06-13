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
	void travel(TreeNode* root,vector<int> &v1){
		if(!root)return;
		travel(root->left,v1);
		v1.push_back(root->val);
		travel(root->right,v1);
		return;
	}
	
    int getMinimumDifference(TreeNode* root) {
        vector<int> v1;
        int min=INT_MAX;
		travel(root,v1);
		for(int i=1;i<v1.size();i++){
			if(abs(v1[i]-v1[i-1]) < min){
				min=abs(v1[i]-v1[i-1]);
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
