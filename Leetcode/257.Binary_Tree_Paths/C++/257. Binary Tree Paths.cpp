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
	string sol(TreeNode *ptr,vector<string> &result,string str){
		if(ptr==NULL){
			return "0";
		}
		str+=to_string(ptr->val);
		if(ptr->left||ptr->right){
			str+="->";
		}
		cout << "str: " << str << endl;
		string left=sol(ptr->left,result,str);
		string right=sol(ptr->right,result,str);
		if(left=="0"&&right=="0"){
			result.push_back(str);
		}
		return str;
	}
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        string str="";
		sol(root,result,str);
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
