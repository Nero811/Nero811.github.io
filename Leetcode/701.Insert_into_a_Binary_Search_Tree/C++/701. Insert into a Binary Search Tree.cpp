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
private:
	TreeNode *left=NULL,*right=NULL;
	bool insert=false;	
public:
	TreeNode *sol(TreeNode *ptr, int val){
		if(ptr==NULL){
	//		cout << "ptr==NULL" << endl;
			return NULL;
		}
		TreeNode *pre;
		if(ptr->val>val){
	//		cout << "111" << endl;
			pre=ptr;
			left=sol(ptr->left,val);
		}
		if(ptr->val<val){
	//		cout << "222" << endl;
			pre=ptr;
			right=sol(ptr->right,val);
		}
		cout << ptr->val << endl;
		if(insert==true){
			return ptr;
		}
		if(left==NULL&&ptr->val>val){
	//		cout << "333" << endl;
			ptr->left=new TreeNode(val);
			insert=true;
			return ptr;
		}
		else if(right==NULL&&ptr->val<val){
	//		cout << "444" << endl;
			ptr->right=new TreeNode(val);
			insert=true;
			return ptr;
		}

		return ptr;
	}
    TreeNode* insertIntoBST(TreeNode* root, int val) {   
		if(!root)root=new TreeNode(val);	
		sol(root,val);
		return root;
    }
};

int main(){
	Solution sol;
	TreeNode *root,*ptr,*p,*q;

	root=new TreeNode(10);
	ptr=root;
	ptr->left=new TreeNode(5);
	ptr->right=new TreeNode(14);
	ptr=ptr->left;	
	ptr->left=new TreeNode(3);
	ptr->right=new TreeNode(8);
	

	TreeNode *result;
	int val;
	cin >> val;
	result=sol.insertIntoBST(root,val);
	queue<TreeNode *>que;
	que.push(result);
	while(!que.empty()){
		int size=que.size();
		for(int i=0;i<size;i++){
			TreeNode *node=que.front();
			cout << node->val << " ";
			que.pop();
			if(node->left)que.push(node->left);
			if(node->right)que.push(node->right);
		} 
		cout << endl;
	}
	return 0;
}
