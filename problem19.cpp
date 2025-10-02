#include<iostream>
using namespace std;


struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    
    if (!head) return nullptr;

    ListNode dummy(-1);

    dummy.next = head;

    

    ListNode* slow = &dummy;
    ListNode* fast = &dummy;

    for(int i = 0 ; i <= n ; i++)
        fast = fast->next;

    while(fast){
        slow = slow->next;
        fast=fast->next;
    }

    slow->next = slow->next->next;

    return dummy.next;

}



int main(){

    ListNode* l1 = new ListNode(1);
    // l1->next = new ListNode(2);
    // l1->next->next = new ListNode(3);
    // l1->next->next->next = new ListNode(4);
    // l1->next->next->next->next = new ListNode(5);

    l1 = removeNthFromEnd(l1 , 1);

     while(l1){

    cout<<l1->val<<" ";
    l1 = l1->next;
    }

    return 0;
}