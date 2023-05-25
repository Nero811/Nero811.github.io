#include <bits/stdc++.h>
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
	ListNode* next;
	ListNode(int x) : val(x), next(nullptr) {}
};
typedef struct ListNode ListNode;
class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		if (head == NULL) {
			return NULL;
		}
		ListNode* ptr = head;
		if (ptr->next == NULL) return ptr;
		ListNode* temp = ptr->next;
		ListNode* pre = NULL;
		while (temp !=NULL) {
			ptr->next = pre;
			pre = ptr;
			ptr = temp;
			temp = temp->next;
			if (temp ==NULL) {
				ptr->next = pre;
				pre = ptr;
				return pre;
			}
		}
		return NULL;
	}
};

int main() {
	ListNode* head=new ListNode(1);
	ListNode* ptr = head;
	ptr->next= new ListNode(2);
	ptr = ptr->next;
	ptr->next = new ListNode(3);
	ptr = ptr->next;
	ptr->next = new ListNode(4);
	ptr = ptr->next;
	ptr->next = new ListNode(5);
	Solution sol;
	ListNode* result = sol.reverseList(head);
	while (result != NULL) {
		cout << result->val << " " << endl;
		result = result->next;
	}
	return 0;
}

