#include <bits/stdc++.h> 

using namespace std;

struct _ListNode{
	int data;
	struct _ListNode *next;
};
typedef _ListNode ListNode;

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
    	ListNode *tmp;
        ptr=head;
	        if(ptr->next != NULL){
	        	head=ptr->next;
	        	if(head->next != NULL){
	        	//	tmp=getnode();
	        	//	tmp=(ListNode*)malloc(sizeof(ListNode));
	        	//	tmp->next=head->next;
	        		tmp=head->next;
	        		head->next=ptr;	        		
				//	tmp=tmp->next;
					ptr->next=swapPairs(tmp);
				}
				else{										
					ptr->next=head->next;
					head->next=ptr;
				}
			}   
		return head;	
    }
    
/*    ListNode *getnode(){
    	ListNode *p;
    	p=(ListNode*)malloc(sizeof(ListNode));
    	if (p == NULL){
    		cout << "Out of memory!";
    		exit (1);
		}
		return p;
	}*/
	
	ListNode* list_link_form_head(ListNode* head,int num){
		if(head==NULL){
		//	head=getnode();
			head=(ListNode*)malloc(sizeof(ListNode));
			head->data=num;
			head->next=NULL;
			ptr=head;
		}
		else{
		//	ptr->next=getnode();
			ptr->next=(ListNode*)malloc(sizeof(ListNode));
			ptr=ptr->next;
			ptr->data=num;
			ptr->next=NULL;
		}	
		return head;	
	}

		
	void print_node(ListNode* head){
		ptr=head;
		while(ptr != NULL){
			cout << ptr->data << " ";
			ptr=ptr->next; 
		}	
		cout << endl;	
	}
private:
	ListNode *ptr;
};

int main(){
	Solution sol;
	ListNode *head=NULL;
	int num;
	while (1){
		cin >> num;
		if (num == -1){
			break;
		}
		head=sol.list_link_form_head(head,num);
	}
	sol.print_node(head);
	head=sol.swapPairs(head);
	sol.print_node(head);
	
	return 0;
}
