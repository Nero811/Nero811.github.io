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
	TreeNode * sol(vector<int>& preorder, vector<int>& inorder){
		TreeNode *ptr;
		if(preorder.empty()){
			return NULL;	
		}
		ptr=new TreeNode(preorder.front());
		if(preorder.size()==1)return ptr;
		
		int pos;
		for(int i=0;i<inorder.size();i++){
			if(inorder[i]==ptr->val){
				pos=i;
				break;
			}
		}
		
		vector<int>leftinorder(inorder.begin(),inorder.begin()+pos);
		vector<int>rightinorder(inorder.begin()+pos+1,inorder.end());
		preorder.erase(preorder.begin());
//		cout << "preorder.front: " << preorder.front() << endl;
		vector<int>leftpreorder(preorder.begin(),preorder.begin()+leftinorder.size());
		vector<int>rightpreorder(preorder.begin()+leftinorder.size(),preorder.end());
		
//		cout << "ptr: " << ptr->val << endl;
		ptr->left=sol(leftpreorder,leftinorder);
//		cout << "ptr->left: " << ptr->left->val << endl;
		ptr->right=sol(rightpreorder,rightinorder);
//		cout << "ptr->right: " << ptr->right->val << endl;
		return ptr;
	}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode *result;
        result=sol(preorder,inorder);
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
