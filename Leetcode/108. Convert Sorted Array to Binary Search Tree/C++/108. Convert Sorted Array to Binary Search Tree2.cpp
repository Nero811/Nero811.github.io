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
	TreeNode *travel(vector<int>& nums,int left,int right){
		if(left>right){
			return NULL;
		}
		int mid=left+((right-left)/2);
	//	cout << "mid: " << mid << endl;
	//	cout << "nums: " << nums[mid-1] << endl;
		TreeNode *root=new TreeNode(nums[mid-1]);
		root->left=travel(nums,left,mid-1);
		root->right=travel(nums,mid+1,right);
		return root;
	}
    TreeNode* sortedArrayToBST(vector<int>& nums) {
		int size=nums.size();
		int left=1,right=size;
		int mid=left+((right-left)/2);
	//	cout << "mid: " << mid << endl;
		TreeNode *root=new TreeNode(nums[mid-1]);
		root->left=travel(nums,left,mid-1);
		root->right=travel(nums,mid+1,right);
		return root;
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
