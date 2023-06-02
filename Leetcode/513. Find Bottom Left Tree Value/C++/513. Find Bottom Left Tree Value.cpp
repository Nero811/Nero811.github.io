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
	void sol(TreeNode *ptr,int &result,int level,int &depth){
		if(ptr==NULL){
			return;
		}
		level++;
		sol(ptr->left,result,level,depth);
		sol(ptr->right,result,level,depth);
		if(depth<level){
			depth=level;
			result=ptr->val;
		}
	}
    int findBottomLeftValue(TreeNode* root) {
        int result=0;
        int level=0;
        int depth=0;
        sol(root,result,level,depth);
    //    cout << "result: " << result << endl; 
        return result;
    }
};

int main(){
	Solution sol;
	TreeNode *root,*ptr;
	root=new TreeNode(1);
	ptr=root;
	ptr->left=new TreeNode(2);
	ptr->right=new TreeNode(3);
	ptr=ptr->left;
	ptr->left=new TreeNode(4);
	ptr=root;
	ptr=ptr->right;
	ptr->left=new TreeNode(5);
	ptr->right=new TreeNode(6);
	ptr=ptr->left;
	ptr->left=new TreeNode(7);

	sol.findBottomLeftValue(root);

	return 0;
}
