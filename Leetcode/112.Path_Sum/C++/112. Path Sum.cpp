#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):val(x),left(NULL),right(NULL){};
};

class Solution {
public:
	int sol(TreeNode *ptr,int targetSum,int sum,int &result){
		if(ptr==NULL){
			return 0;
		}
		sum+=ptr->val;
		if(!ptr->left&&!ptr->right){
			cout << "sum: " << sum << endl;
			if(sum==targetSum){
				cout << "true";
				result=2;
			}
			else{
				result=0;
			}
			return result;
		}		
		int left=sol(ptr->left,targetSum,sum,result);
		if(left==2){
			cout << "true";
			return 2;
		}
		int right=sol(ptr->right,targetSum,sum,result);
		if(right==2){
			cout << "true";
			return 2;
		}
		return result;
	}
    bool hasPathSum(TreeNode *root, int targetSum) {
    	if(!root)return false;
        int result=0;
        bool Result;
        int sum=0;
        sol(root,targetSum,sum,result);
    //    cout << "result: " << result << endl;
		if(result==2)Result=true;
		else Result=false;
        return Result;
    }
};

int main(){
	Solution sol;
	TreeNode *root,*ptr;
	bool result;
	int targetSum;
	
	cin >> targetSum;
	
	root=new TreeNode(1);
	ptr=root;
	
	
	ptr->left=new TreeNode(2);
	ptr->right=new TreeNode(3);	
	
	
/*	ptr->left=new TreeNode(4);
	ptr->right=new TreeNode(8);
	ptr=ptr->left;
	ptr->left=new TreeNode(11);
	ptr=ptr->left;
	ptr->left=new TreeNode(7);
	ptr->right=new TreeNode(2);
	ptr=root;
	ptr=ptr->right;
	ptr->left=new TreeNode(13);
	ptr->right=new TreeNode(4);
	ptr=ptr->right;
	ptr->right=new TreeNode(1);*/
	
	
	
	result=sol.hasPathSum(root,targetSum);
	if(result){
		cout << "true";
	}
	else{
		cout << "false";
	}
	return 0;
}
