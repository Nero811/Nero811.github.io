/* ************************************************************************
> File Name:     429.cpp
> Author:        Jack Yang
> Created Time:  2023年05月12日 (週五) 20時50分34秒
> Description:   N-ary Tree Level Order Traversal 
 ************************************************************************/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> result;
        if(!root)return result;
        queue<Node *>que;
        que.push(root);
        result.push_back({root->val});
        while(!que.empty()){
            int size=que.size();
            vector<int>vec;
            for(int i=0;i<size;i++){
                Node *node=que.front();
                que.pop();
                for(int j=0;j<(node->children).size();j++){
                    vec.push_back(node->children[j]->val);
                    que.push(node->children[j]);
                }
            }
            if(!vec.empty()){
                result.push_back(vec);
            }
        }
        return result;
    }
};

int main(){
    Node *root=new Node(1);
    Node *ptr=new Node(3);
    root->children.push_back(ptr);
    ptr=new Node(2);
    root->children.push_back(ptr);
    ptr=new Node(4);
    root->children.push_back(ptr);
    ptr=root->children[0];
    Node *ptr2=new Node(5);
    ptr->children.push_back(ptr2);
    ptr2=new Node(6);
    ptr->children.push_back(ptr2);
    vector<vector<int>>result;
    Solution sol;
    result=sol.levelOrder(root);
    for(vector<int>vec:result){
        for(int &j:vec){
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}
