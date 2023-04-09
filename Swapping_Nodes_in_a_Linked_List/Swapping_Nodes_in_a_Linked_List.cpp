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
    ListNode* swapPairs(ListNode* head,int k) {
    	ListNode *tmp,*tmp2;
        ptr=head;
        tmp=head;
        bool Cardinality=false;
        if(count==1){
        	return head;
		}
		else if(count==2){
			head=ptr->next;
			head->next=ptr;
			ptr->next=NULL;
			return head;
		}
		double mid=count/2;
		int div=int(count)%2;

		if (div != 0){
			Cardinality=true;
		}
		
		for(int i=1;i<count;i++){
		 	if(i<k-1){
		 		ptr=ptr->next;	
			}
			if(i<count-k){
				tmp=tmp->next;
			}						      	
		}
			
		if(k==1){
			tmp2=ptr->next;
			head=tmp->next;
			head->next=tmp2;
			tmp->next=ptr;
			ptr->next=NULL;
		}
		else if(k==count){
			tmp2=tmp->next;
			head=ptr->next;
			head->next=tmp2;
			ptr->next=tmp;
			tmp->next=NULL;
		}
		else if(k<round(mid)&&Cardinality==true){
			tmp2=ptr->next;
			ptr->next=tmp->next;
			tmp->next=tmp2;
			tmp=tmp2->next;
			ptr=ptr->next;
			tmp2->next=ptr->next;
			ptr->next=tmp;								
		}
		else if(k<round(mid)&&Cardinality==false){
			tmp2=ptr->next;
			ptr->next=tmp->next;
			ptr=ptr->next;
			tmp->next=tmp2;
			tmp=tmp2->next;
			tmp2->next=ptr->next;
			ptr->next=tmp;							
		}		
		else if(k==round(mid) && Cardinality==true){
			return head;							
		}
		else if(k==round(mid) && Cardinality==false){
			ptr->next=tmp->next;
			ptr=ptr->next;
			tmp2=ptr->next;
			tmp->next=tmp2;
			ptr->next=tmp;									
		}				
		else if(k>round(mid)&&Cardinality==true){
			tmp2=tmp->next;			
			tmp->next=ptr->next;
			ptr->next=tmp2;
			tmp=tmp->next;
			ptr=tmp->next;
			tmp->next=tmp2->next;
			tmp2->next=ptr;
		}
		else if(k>round(mid)&&Cardinality==false){
			tmp2=tmp->next;
			tmp->next=ptr->next;
			tmp=tmp->next;
			ptr->next=tmp2;
			ptr=tmp2->next;
			tmp2->next=tmp->next;
			tmp->next=ptr;			
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

	double count_node(ListNode* head){
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
	double count=0;
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
	count=sol.count_node(head)/2;
	cout << "Total count/2: "<<round(count)<< endl;
	cin >> k;
	head=sol.swapPairs(head,k);
	sol.print_node(head);
	
	return 0;
}
