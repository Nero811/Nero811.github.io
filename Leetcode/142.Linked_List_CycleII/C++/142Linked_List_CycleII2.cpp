#include <bits/stdc++.h> 
#include <map>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {                           
    int val;                                
    ListNode *next;                         
    ListNode(int x) : val(x), next(NULL) {}
};
  
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {  	
    	bool cycle=false;
    	int idx=0;
    
    	ListNode* ptr;
    	map<ListNode *,int> mp;           
   		map<ListNode *,int>::iterator it2;    
   		
        if(head==NULL){
            return NULL;
        }	
		else if(head->next==NULL){
			return NULL;
		}	
        if(head!=NULL){
        	ptr=head;
        	mp[ptr]=idx;
        	it2=mp.begin();
		}

        while(ptr->next!=NULL){
        	ptr=ptr->next;
        	cout << "ptr->val: " << ptr->val << endl;
        	idx++;
			it2=mp.find(ptr);
			if(it2!=mp.end()){
				cout << "cycle" << endl;
				cycle=true;
				break;
			}
        	mp[ptr]=idx;
		}	

		if(cycle){
			ptr=head;
			for(int i=0;i<(*it2).second;i++){
				ptr=ptr->next;
			}		
			cout << "ans: " <<"pos " << (*it2).second << " , "<<"val " << ptr->val << endl;
			return ptr;			
		}
		else{
			return NULL;
		}
    }
};

int main(){
	ListNode * headA,* headB, *ptr;
	Solution sol;
	headA=new ListNode(1);
	ptr=new ListNode(2);
	
	headA->next=ptr;
	ptr->next=headA;
//	headA=NULL;
	headB=sol.detectCycle(headA);
	if(headB==NULL){
		cout << "no cycle" << endl;
	}
	return 0;
}
