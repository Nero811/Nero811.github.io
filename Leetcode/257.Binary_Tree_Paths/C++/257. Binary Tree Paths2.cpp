#include<bits/stdc++.h>
#include<stack>
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
    vector<string> binaryTreePaths(TreeNode *root) {
        stack<TreeNode*> st;
        stack<string> pst;
        vector<string> result;
        if (root != NULL) st.push(root);
        pst.push(to_string(root->val));
        while (!st.empty()) {
            TreeNode *node = st.top();
            st.pop();
            string str=pst.top();
            cout << "str: " << str << endl;
            pst.pop();
            if(!node->left&&!node->right){
            	result.push_back(str);
			}
            if (node->right){
            	st.push(node->right);  
            	pst.push(str + "->" + to_string(node->right->val));
			}
            if (node->left){
            	st.push(node->left);
            	pst.push(str + "->" + to_string(node->left->val));
			}
        }
        return result;
    }
};

int main(){
	Solution sol;
	TreeNode *root,*ptr;
	vector<string> ans;
	root=new TreeNode(1);
	ptr=root;
	ptr->left=new TreeNode(2);
	ptr->right=new TreeNode(3);
	ptr=ptr->left;
	ptr->right=new TreeNode(5);
	

	ans=sol.binaryTreePaths(root);
	for(auto a:ans){
		cout << a << " ";
	}

	return 0;
}
