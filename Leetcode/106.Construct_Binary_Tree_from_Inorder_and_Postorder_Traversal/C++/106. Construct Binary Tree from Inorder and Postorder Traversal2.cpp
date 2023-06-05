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
	TreeNode * sol(TreeNode *ptr,vector<int>& inorder, vector<int>& postorder){
		if(postorder.empty()){
			return NULL;	
		}
//		cout << "ptr: " << postorder.back();
		ptr=new TreeNode(postorder.back());
		if(postorder.size()==1)return ptr;
		
		int pos;
		for(int i=0;i<inorder.size();i++){
			if(inorder[i]==ptr->val){
				pos=i;
				break;
			}
		}
		
		vector<int>leftinorder(inorder.begin(),inorder.begin()+pos);
		vector<int>rightinorder(inorder.begin()+pos+1,inorder.end());
		postorder.pop_back();
		vector<int>leftpostorder(postorder.begin(),postorder.begin()+leftinorder.size());
		vector<int>rightpostorder(postorder.begin()+leftinorder.size(),postorder.end());
		
		ptr->left=sol(ptr,leftinorder,leftpostorder);
		ptr->right=sol(ptr,rightinorder,rightpostorder);
		return ptr;
	}
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        TreeNode *root=NULL;
        TreeNode *result;
        result=sol(root,inorder,postorder);
		return result;
    }
};
int main(){
	Solution sol;
	TreeNode *root,*ptr;
	vector<int> inorder;
	vector<int> postorder;
	queue<TreeNode *>que;
	int in,in2;
	while(in != -2){
		cin >> in;
		if(in != -2){
			inorder.push_back(in);
		}
	}
	
	while(in2 != -2){
		cin >> in2;
		if(in2 != -2){
			postorder.push_back(in2);
		}
	}	
		
	root=sol.buildTree(inorder,postorder);
	que.push(root);
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
