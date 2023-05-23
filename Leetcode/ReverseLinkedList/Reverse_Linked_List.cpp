#include <bits/stdc++.h>
#include <list>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
 
struct ListNode {                                          
    int val;                                               
    ListNode *next;                                        
    ListNode() : val(0), next(nullptr) {}                  
    ListNode(int x) : val(x), next(nullptr) {}             
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
    	ListNode* ptr;
        list<int> L1;
        list<int>::iterator it;
        ptr=head;
        while(ptr!=NULL){
        	L1.push_back(ptr->val);
        	ptr=ptr->next;
		}
		L1.reverse();
		ptr=head;
		for(it=L1.begin();it!=L1.end();it++){
			ptr->val=*it;
			ptr=ptr->next;
		}
		return head;
    }
};
