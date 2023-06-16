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
		
    vector<int> findMode(TreeNode* root) {
 		stack<TreeNode*> st;
 		vector<int> result;
 		TreeNode *cur=root;
 		TreeNode *pre=NULL;
 		int count=0;
 		int feq=0;
 		while(cur!=NULL||!st.empty()){
 			if(cur!=NULL){
 				st.push(cur);
 				cur=cur->left;
			}
			else{
				cur=st.top();
				st.pop();
				cout << "cur: " << cur->val << endl;
				if(result.empty()) result.push_back(cur->val);
				if(pre!=NULL&&cur->val!=pre->val){
					count=0;
					if(count==feq){
						result.push_back(cur->val);
					}
				}
				else if(pre!=NULL&&cur->val==pre->val){
					count++;
					if(count > feq){
						feq=count;
						result.clear();
						result.push_back(cur->val);
					}
					else if(count==feq){
						result.push_back(cur->val);
					}					
				}				
				pre=cur;
				cur=cur->right;
			}
		}
    	return result;
    }
};

int main(){
	Solution sol;
	TreeNode *root,*ptr;

	root=new TreeNode(1);
	ptr=root;
	ptr->right=new TreeNode(2);
	ptr=ptr->right;
	ptr->left=new TreeNode(2);	

/*	root=new TreeNode(4);
	ptr=root;
	ptr->left=new TreeNode(2);
	ptr->right=new TreeNode(6);
	ptr=ptr->left;
	ptr->left=new TreeNode(1);
	ptr->right=new TreeNode(3);	*/
	
	vector<int> result;
	result=sol.findMode(root);
	for(auto a:result){
		cout << a << " " ;
	}
	return 0;
}
