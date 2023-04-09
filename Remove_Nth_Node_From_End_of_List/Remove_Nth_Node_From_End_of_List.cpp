#include <bits/stdc++.h> 
#include <cmath>
using namespace std;

struct _ListNode{
	int data;
	struct _ListNode *next;
};
typedef _ListNode ListNode;

class Solution {
public:
    ListNode* swapPairs(ListNode* head,int n) {
		ListNode *tmp;
        tmp=ptr=head;
		int i=1;

        if(count==1){
        	return 0;
		}
		if(count-n==0){
			head=head->next;
			return head;
		}
		while(1){
			if(ptr->next != NULL){
				if(i==(count-n)){
					ptr->next=ptr->next->next;
					return head; 
				}
				ptr=ptr->next;
				i++;
			}
		}
		return head;	
    }
    
	ListNode *getnode(){
    	ListNode *p;
    	p=(ListNode*)malloc(sizeof(ListNode));
    	if (p == NULL){
    		cout << "Out of memory!";
    		exit (1);
		}
		return p;
	}
	
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

	int count_node(ListNode* head){
		ptr=head;
		while(ptr != NULL){
		//	cout << ptr->data << " ";
			ptr=ptr->next; 
			count++;
		}	
		return count;		
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
	int count=0;
};

int main(){
	Solution sol;
	ListNode *head=NULL;
	int num;
	int k;
	double count=0;
	while (1){
		cin >> num;
		if (num == -1){
			break;
		}
		head=sol.list_link_form_head(head,num);
	}
	sol.print_node(head);
	sol.count_node(head);
//	cout << "Total count/2: "<<round(count)<< endl;
	cin >> k;
	head=sol.swapPairs(head,k);
	sol.print_node(head);
	
	return 0;
}
