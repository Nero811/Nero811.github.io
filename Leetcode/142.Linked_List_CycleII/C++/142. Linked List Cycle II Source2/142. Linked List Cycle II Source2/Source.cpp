#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

struct _ListNode {
    int val;
    _ListNode* next;
    _ListNode(int x) :val(x),next(nullptr){};
};
typedef struct _ListNode ListNode;

class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        unordered_map<ListNode*,int>hashTable;
        ListNode* dummyhead = new ListNode(-10001);
        dummyhead->next = head;
        ListNode* ptr = dummyhead->next;
        while (ptr !=nullptr) {
        //    cout << ptr->val << endl;
            if (hashTable[ptr]> 0) {
                delete dummyhead;
                return ptr;
            }
            hashTable[ptr]++;
            ptr = ptr->next;
        }
        return nullptr;
    }
};

int main() {
    Solution sol;
    ListNode* head= new ListNode(3);
    head->next= new ListNode(2);
    ListNode* temp = head->next;
    head->next->next= new ListNode(0);
    head->next->next->next= new ListNode(-4);
    head->next->next->next->next = temp;
    ListNode* result = sol.detectCycle(head);
    if (result != nullptr)cout << result->val;
    else cout << "no cycle";
    return 0;
}