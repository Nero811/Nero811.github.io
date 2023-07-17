#include <bits/stdc++.h> 
#include <list>
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
    	list<int> L1;
    	list<int>::iterator it;
    //    map<int,list<int>::iterator> mp;
    //    map<int,list<int>::iterator>::iterator it2;
    	map<int,int> mp;           
   		map<int,int>::iterator it2;   

        if(head==NULL){
            return NULL;
        }	
		else if(head->next==NULL){
			return NULL;
		}          
        if(head!=NULL){
            ptr=head;
        	L1.push_back(ptr->val);
        	it=L1.begin();
        //	mp[idx]=it;
        	mp[*it]=idx;
        	it2=mp.begin();
		}

        while(ptr->next!=NULL){
        	ptr=ptr->next;
        	L1.push_back(ptr->val);
        	cout << "ptr->val: " << ptr->val << endl;
        	idx++;
        	it++;
        	it2=mp.find(*it);
        	if(it2!=mp.end()){
        		cycle=true;
        		break;
			}       	
        	mp[*it]=idx;
		}	
		ptr=head;
		if(cycle){
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
