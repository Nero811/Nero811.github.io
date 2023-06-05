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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        TreeNode *root=new TreeNode(postorder.back());
        TreeNode *ptr=root;
        vector<int>v1,v2;
        v2.push_back(root->val);
        postorder.pop_back();
        int i=0;
        while(!postorder.empty()){
        	cout << "ptr " << ptr->val << endl;
        	while(find(v2.begin(),v2.end(),inorder[i])!=v2.end()){
        		i++;
			}
			
			if(i<=inorder.size()-1){
	    		cout << "inorder[i] " << inorder[i] << endl;
	    		ptr->left=new TreeNode(inorder[i]);
	    		v1.push_back(inorder[i]);		
				i++;	
			}
			
			if(find(v1.begin(),v1.end(),postorder.back())==v1.end()){
				ptr->right=new TreeNode(postorder.back());
				v2.push_back(postorder.back());
			}
			postorder.pop_back();
			if(ptr->right){
				ptr=ptr->right;
			}
		}
		return root;
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
			que.pop();
			cout << "node: " << node->val << " ";
			if(node->left)que.push(node->left);
			if(node->right)que.push(node->right);
		}
		cout << endl;
	}
	return 0;
}
