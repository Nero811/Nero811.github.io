#include <bits/stdc++.h>
#include <vector>
#include <map>
using namespace std;
/* Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
struct TreeNode{
	int val;	
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {};
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
};

class Solution {
public:
	TreeNode* new_node(){
		TreeNode* New_Node;
		New_Node=new TreeNode;
		New_Node->left=NULL;
		New_Node->right=NULL;
		return New_Node;
	}
	
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    	TreeNode *root,*ptr,*parent,*parent_right,*tmp;
    	vector<int>::iterator it;
    	root=new_node();
    	parent=ptr=tmp=root;
    	int max,pos;
    	pos=0;
    	max=nums[0];
    	root->val=max;
		for(int i=1;i<nums.size();i++){
		//	cout << "max :" << max << endl;
			if(nums[i-1]>nums[i]){
				if(nums[i-1]<=max){
				//	cout << "step 1:" << endl;
					if(nums[i-1]==max){
						//cout <<"max" << endl; 
						ptr=root;
					}
					ptr->right=new_node();
					ptr=ptr->right;
					ptr->val=nums[i];
				//	cout << "ptr->val: " << ptr->val <<endl; 
				}
				else if(nums[i-1]>max){
				//	cout << "step 2:" << endl;
					parent=root;
					root=new TreeNode;
					root->left=parent;
					root->val=nums[i-1];
				//	cout << "root->val: "<< root->val << endl;
					max=nums[i-1];
					parent=root;
					ptr=root;
				}				
			}
			else if(nums[i-1]<nums[i]){			
				if(nums[i]<max){
				//	cout << "step 3:" << endl;
					ptr=root;
					while(ptr->val>nums[i]){
						tmp=ptr;
						ptr=ptr->right;
					}
					parent=new_node();
					parent->val=nums[i];
				//	cout << "parent->val: " << parent->val <<endl; 
					parent->left=ptr;
					tmp->right=parent;
					ptr=parent;
				}
				else if(nums[i]>max){
				//	cout << "step 4:" << endl;
					parent=root;
					root=new_node();
					root->left=parent;
					root->val=nums[i];
				//	cout << "root->val: "<< root->val << endl;
					max=nums[i];
					ptr=root;
					parent=root;			
				}		
			}
		}
		return root;
    }
	
	TreeNode * construct2(vector<int>& nums, int l, int r) {
		TreeNode *root;
        if (l == r){
            cout << "NULL " ;
            return NULL;        	
		}
        int max_i = max(nums, l, r);
        root = new TreeNode(nums[max_i]);
        cout << root->val << " ";
        root->left = construct2(nums, l, max_i);
//        cout << root->val << " ";
        root->right = construct2(nums, max_i + 1, r);
//        cout << root->val << " ";
        return root;
    }

	int max(vector<int>& nums, int l, int r) {
	        int max_i = l;
	        for (int i = l; i < r; i++) {
	            if (nums[max_i] < nums[i])
	                max_i = i;
	        }
	        return max_i;
	}
    
	
	void print_postorder(TreeNode *ptr)
	{
	    if(ptr != NULL)
	    {
	    	cout <<  ptr->val << " "<< endl;
	        print_postorder(ptr->left);
	     //   cout <<  ptr->val << " "<< endl;
	        print_postorder(ptr->right);
	   //     cout <<  ptr->val << " "<< endl;
	    }
	}		
};


int main(){
	Solution sol;
	vector<int> v1;
	int l=0,r;
	TreeNode * root;
	int n;
	while(n!=-1){
		cin >> n;
		if(n!=-1){
			v1.push_back(n);
		}
	} 
	root=sol.constructMaximumBinaryTree(v1);
	r=v1.size();
//	root=sol.construct2(v1,l,r);
	sol.print_postorder(root);
	return 0;
}
