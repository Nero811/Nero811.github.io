#include<bits/stdc++.h>
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
	TreeNode * sol(TreeNode *root1, TreeNode *root2){
		TreeNode * ptr;
		if(!root1&&!root2){
			return NULL;
		}
		else if(root1&&!root2){
			return root1;
		}
		else if(!root1&&root2){
			return root2;
		}
		
		if(root1&&root2){
			ptr=new TreeNode(root1->val+root2->val);
		}
	//	if(root1)cout << "root1: " << root1->val << endl;
	//	if(root2)cout << "root2: " << root2->val << endl;
	//	if(ptr)cout << "ptr: " << ptr->val << endl;


		if(!root1&&!root2||!root1&&!root2->left||!root1->left&&!root2){
	//		cout << "1" << endl;
			ptr->left=sol(NULL,NULL);
		}		
		else if(root1->left&&!root2->left||root1->left&&!root2){
	//		cout << "2"<< endl;
			ptr->left=sol(root1->left,NULL);
		}
		else if(!root1->left&&root2->left||!root1&&root2->left){
	//		cout << "3"<< endl;
			ptr->left=sol(NULL,root2->left);
		}
		else if(root1->left&&root2->left){
	//		cout << "4"<< endl;
			ptr->left=sol(root1->left,root2->left);
		}		

		if(!root1&&!root2||!root1->right&&!root2||!root1&&!root2->right){
	//		cout << "5"<< endl;
			ptr->right=sol(NULL,NULL);
		}			
		else if(root1->right&&!root2->right||root1->right&&!root2){
	//		cout << "6"<< endl;
			ptr->right=sol(root1->right,NULL);
		}
		else if(!root1->right&&root2->right||!root1&&root2->right){
	//		cout << "7"<< endl;
			ptr->right=sol(NULL,root2->right);
		}
		if(root1->right&&root2->right){
	//		cout << "8"<< endl;
			ptr->right=sol(root1->right,root2->right);	
		}
					
		return ptr;
	}
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        TreeNode *result;
        result=sol(root1,root2);
        return result;
    }
};
int main(){
	Solution sol;
	TreeNode *root1,*root2,*ptr;

	root1=new TreeNode(1);
	ptr=root1;
	ptr->left=new TreeNode(3);
	ptr->right=new TreeNode(2);
	ptr=ptr->left;
	ptr->left=new TreeNode(5);
	
	root2=new TreeNode(2);
	ptr=root2;
	ptr->left=new TreeNode(1);
	ptr->right=new TreeNode(3);	
	ptr=ptr->left;
	ptr->right=new TreeNode(4);
	ptr=root2;
	ptr=ptr->right;
	ptr->right=new TreeNode(7);
	
	TreeNode * result;
	queue<TreeNode *>que;
	result=sol.mergeTrees(root1,root2);
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
