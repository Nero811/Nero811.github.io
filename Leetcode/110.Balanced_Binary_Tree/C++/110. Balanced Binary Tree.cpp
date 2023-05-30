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
    bool isBalanced(TreeNode* root) {
    	if (!root)return true;
    	int lt_left_level=0,lt_right_level=0;
    	int rt_left_level=0,rt_right_level=0;
    	int left_level=0,right_level=0;
    	queue<TreeNode*>que_left,que_right;
		if(root->left)que_left.push(root->left);
		if(root->right)que_right.push(root->right);
		while(!que_left.empty()){
			int size=que_left.size();
			bool left=false,right=false;
			for(int i=0;i<size;i++){
				TreeNode *left_node=que_left.front();
				que_left.pop();
				if(left_node->left){
					que_left.push(left_node->left);
					if(left==false){
						lt_left_level++;
						left=true;
					}					
					if(abs(lt_left_level-lt_right_level) > 0 && !left_node->right){
						if(left_node->left->left||left_node->left->right){
							cout << "false";
							return false;							
						}
					}						
				}								
				if(left_node->right){
					que_left.push(left_node->right);
					if(right==false){
						lt_right_level++;
						right=true;
					}					
					if(abs(lt_left_level-lt_right_level) > 0 && !left_node->left){
						if(left_node->right->right||left_node->right->left){
							cout << "false";
							return false;							
						}
					}						
				}							
			}
			if(abs(lt_left_level-lt_right_level) > 1){
				cout << "false";
				return false;
			}			
			cout << "lt_left_level: " << lt_left_level << endl;
			cout << "lt_right_level: " << lt_right_level << endl;
			left_level++;
		}		
		while(!que_right.empty()){
			int size=que_right.size();
			bool left=false,right=false;
			for(int i=0;i<size;i++){
				TreeNode *right_node=que_right.front();
				que_right.pop();
				if(right_node->left){
					que_right.push(right_node->left);
					if(left==false){
						rt_left_level++;
						left=true;
					}						
					if(abs(rt_left_level-rt_right_level) > 0 && !right_node->right){
						if(right_node->left->left||right_node->left->right){
							cout << "false";
							return false;							
						}
					}				
				}										
				if(right_node->right){
					que_right.push(right_node->right);	
					if(right==false){
						rt_right_level++;
						right=true;
					}						
					if(abs(rt_left_level-rt_right_level) > 0 && !right_node->left){
						if(right_node->right->right||right_node->right->left){
							cout << "false";
							return false;							
						}
					}									
				}									
			}
			if(abs(rt_left_level-rt_right_level) > 1){
				cout << "false";
				return false;
			}					
			cout << "rt_left_level: " << rt_left_level << endl;
			cout << "rt_right_level: " << rt_right_level << endl;						
			right_level++;
		}	
		
//		cout << "left_level: " << left_level;
//		cout << "right_level: " << right_level;
		if(abs(left_level-right_level) > 1 ){
			cout << "false";
			return false;
		}
		cout << "true";
		return true;
    }
};

int main(){
	Solution sol;
	TreeNode *root,*ptr;
	root=new TreeNode(1);
	ptr=root;
	
	ptr->left=new TreeNode(9);
	ptr->right=new TreeNode(20);
	ptr=ptr->right;
	ptr->left=new TreeNode(15);
	ptr->right=new TreeNode(7);		
	
	
/*	ptr->left=new TreeNode(2);
	ptr->right=new TreeNode(2);
	ptr=ptr->left;
	ptr->left=new TreeNode(3);
	ptr->right=new TreeNode(3);
	ptr=ptr->left;
	ptr->left=new TreeNode(4);		
	ptr->right=new TreeNode(4);*/
	
/*	ptr->right=new TreeNode(2);
	ptr=ptr->right;
	ptr->right=new TreeNode(3);*/
	
/*	ptr->left=new TreeNode(2);
	ptr->right=new TreeNode(2);
	ptr=ptr->left;
	ptr->left=new TreeNode(3);
	ptr=ptr->left;
	ptr->left=new TreeNode(4);
	ptr=root;
	ptr=ptr->right;
	ptr->right=new TreeNode(3);
	ptr=ptr->right;
	ptr->right=new TreeNode(4);*/
	
	
	
	sol.isBalanced(root);

	
	return 0;
}
