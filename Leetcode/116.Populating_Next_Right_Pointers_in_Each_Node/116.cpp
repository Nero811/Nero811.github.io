/* ************************************************************************
> File Name:     116.cpp
> Author:        Jack Yang
> Created Time:  2023年05月14日 (週日) 18時46分27秒
> Description:   Populating Next Right Pointers in Each Node 
 ************************************************************************/
#include<iostream>
#include<queue>
using namespace std;
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
class Solution {
public:
    Node* connect(Node* root) {
        if(!root)return nullptr;
        queue<Node *>que;
        que.push(root);
        while(!que.empty()){
            int size=que.size();
            Node *pre=que.front();
            for(int i=0;i<size;i++){
                Node *node=que.front();
                que.pop();
                if(i>0){
                    pre->next=node;
                    pre=pre->next;
                }
                else if(i == (size-1)){
                    pre->next=nullptr;
                }
                if(node->left)que.push(node->left);
                if(node->right)que.push(node->right);
            }
        }
        return root;
    }
};

int main(){
    Solution sol;
    Node *root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    Node *ptr=root->left;
    ptr->left=new Node(4);
    ptr->right=new Node(5);
    ptr=root->right;
    ptr->left=new Node(6);
    ptr->right=new Node(7);
    root=sol.connect(root);
    queue<Node *>que;
    que.push(root);
    while(!que.empty()){
        int size=que.size();
        for(int i=0;i<size;i++){
            Node *node=que.front();
            que.pop();
            if(node->next)cout << node->next->val << " ";
            if(node->left)que.push(node->left);
            if(node->right)que.push(node->right);
        }
        cout << endl;
    }
    return 0;
}
