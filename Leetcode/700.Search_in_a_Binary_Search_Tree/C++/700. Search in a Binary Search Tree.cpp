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
	TreeNode *sol(TreeNode* ptr, int val){
		TreeNode *result;
		if(ptr==NULL){
			return NULL;
		}
		if(ptr->val==val){
			result=ptr;
	//		cout << "result: " << result->val << endl;
			return result;
		}
		else{
			result=NULL;
		}
		TreeNode *left=sol(ptr->left,val);
		if(left)return left;
		TreeNode *right=sol(ptr->right,val);
		if(right)return right;
		return result;
	}
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode *result;
        result=sol(root,val);
        return result;
    }
};

int main(){
	Solution sol;
	TreeNode *root,*ptr;

	root=new TreeNode(4);
	ptr=root;
	ptr->left=new TreeNode(2);
	ptr->right=new TreeNode(7);
	ptr=ptr->left;
	ptr->left=new TreeNode(1);
	ptr->right=new TreeNode(3);	
	
	int val;
	cin >> val;
	
	TreeNode * result;
	queue<TreeNode *>que;
	result=sol.searchBST(root,val);
	if(!result)cout<<"empty"<<endl;
	que.push(result);
	while(!que.empty()){
		int size=que.size();
		for(int i=0;i<size;i++){
			TreeNode *node=que.front();
			cout << "node: " << node->val << " ";
			que.pop();
			if(node->left)que.push(node->left);
			if(node->right)que.push(node->right);
		}
		cout << endl;
	}
	
	return 0;
}
