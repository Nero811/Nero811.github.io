#include <bits/stdc++.h>
#include <list>
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
 
 
#include <bits/stdc++.h>
#include <list>
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    	ListNode * ptr;
        list<int> LA,LB;
        list<int>::iterator itA,itB;
        int pos=0,skipA=0,skipB=0;
        
        
        ptr=headA;
        while(ptr!=NULL){
        	LA.push_back(ptr->val);
        	ptr=ptr->next;
		}
		
		ptr=headB;
        while(ptr!=NULL){
        	LB.push_back(ptr->val);
        	ptr=ptr->next;
		}
		
		LA.reverse();
		LB.reverse();
		itB=LB.begin();
		for(itA=LA.begin();itA!=LA.end();itA++){
			if(*itA==*itB){
				pos++;
			}
			itB++;
		}
		cout << "pos: " << pos << endl;
		if(pos==0){
			return 0;
		}
		else{
			skipA=LA.size()-pos;
            cout << "skipA : " << skipA << endl;
			skipB=LB.size()-pos;
            cout << "skipB : " << skipB << endl;
			ptr=headA;
            ListNode * ptrB=headB;
            int start_val;
            for(int i=0;i<skipA;i++){
                ptr=ptr->next;
            }
            for(int i=0;i<skipB;i++){
                ptrB=ptrB->next;
            }          
            while(ptr!=ptrB){
                if(skipA==LA.size()-1||skipB==LB.size()-1){
                    return 0;
                }
                if(ptr->next!=NULL){
                    ptr=ptr->next;
                    skipA++;
                    cout << "skipA : " << skipA << endl;
                }
                if(ptrB->next!=NULL){
                    ptrB=ptrB->next;
                    skipB++;
                    cout << "skipB : " << skipB << endl;
                }               
            }
		}
		return ptr;
    }
};

int main(){
	ListNode * headA,* headB, *ptr;
	Solution sol;
	
	
	
	return 0;
}
