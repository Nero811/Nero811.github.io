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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
    	int pos;
        TreeNode *root,*ptr;
        if(nums.size()<=2){
        	ptr=new TreeNode(nums[0]);
        	if(nums.size()==1){
        		return ptr;
			}
			root=new TreeNode(nums[1]);
			root->left=ptr;
			return root;
		}
        root=new TreeNode(nums[0]);
        for(int i=1;i<nums.size()/2;i++){
        	if(nums[i-1]<nums[i]){
        		cout << "nums: " << nums[i] << endl;
        		TreeNode *ptr=new TreeNode(nums[i]);
        		ptr->left=root;
        		root=ptr;
			}
		}
		TreeNode *left=root;

		root=new TreeNode(nums[nums.size()/2+1]);
        for(int i=nums.size()/2+1;i<nums.size()-1;i++){
        	if(nums[i]<nums[i+1]){
        		TreeNode *ptr=new TreeNode(nums[i+1]);
        		ptr->left=root;
        		root=ptr;
			}
		}	
		TreeNode *right=root;	
		TreeNode *result=new TreeNode(nums[nums.size()/2]);
		result->left=left;	
		result->right=right;
		return result;
    }
};

int main(){
	Solution sol;
	TreeNode *root,*ptr,*p,*q;
	vector<int> nums;
	int val;
	while(val!=500){
		cin >> val;
		if(val!=500){
			nums.push_back(val);
		}
	}

	
	TreeNode *result;
	result=sol.sortedArrayToBST(nums);
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
