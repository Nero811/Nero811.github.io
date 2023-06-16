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
        vector<int> v1,result;
        travel(root,v1);
    //    if(v1.size()<=2)return v1;
        int count=0;
        int feq=0;
        result.push_back(v1[0]);
        for(int slowidx=0,i=1;i<v1.size();i++){
        	cout << "feq: " << feq << endl;
        	if(v1[i]!=v1[slowidx]){
        		slowidx=i;
        		count=0;  
				if(count==feq){
					cout << v1[slowidx] << endl;
					result.push_back(v1[slowidx]);
				}	
			//	slowidx=i;			
			//	count=0;  
			}
        	else if(v1[i]==v1[slowidx]){
        		count++;  		
				if(count>feq){
					feq=count;
					result.clear();
					result.push_back(v1[slowidx]);
				}
				else if(count==feq){
					result.push_back(v1[slowidx]);
				}
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
