#include<iostream>
using namespace std;


struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseList(ListNode* head) {
    
    ListNode* prev = nullptr;
    ListNode* curr = head;

    while(curr){

        ListNode* next = curr->next;
        curr->next = prev;

        prev = curr;

        curr = next;

    }
  

    return prev;


}



ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

    l1 = reverseList(l1);
    l2 = reverseList(l2);

    ListNode dummy(-1);
    ListNode* curr = &dummy;
    int carry = 0;

    while (l1 || l2 || carry) {
        int sum = carry;
        if (l1) { sum += l1->val; l1 = l1->next; }
        if (l2) { sum += l2->val; l2 = l2->next; }

        carry = sum / 10;
        curr->next = new ListNode(sum % 10);
        curr = curr->next;
    }

    l1 = dummy.next;

    l1 = reverseList(l1);

    return l1;
}

int main(){

    ListNode* l1 = new ListNode(7);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(4);
    l1->next->next->next = new ListNode(3);
    // l1->next->next->next->next = new ListNode(9);
    // l1->next->next->next->next->next = new ListNode(9);
    // l1->next->next->next->next->next->next = new ListNode(9);

  

    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);
    // l2->next->next->next = new ListNode(9);

    l1 = addTwoNumbers(l1,l2);

    while(l1){
        cout<<l1->val<<" ";
        l1= l1->next;
    }

    return 0;
}
