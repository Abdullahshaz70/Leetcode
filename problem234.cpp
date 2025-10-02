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

bool isPalindrome(ListNode* head) {
    
    if(!head) return false;

    ListNode* slow = head;
    ListNode* fast = head;

    while(fast && fast->next){

        slow = slow->next;
        fast = fast->next->next;

    }

    slow = reverseList(slow);

    while(head && slow){

        if(slow->val != head->val) return false;

        slow = slow->next;
        head = head->next;
    }

    return true;

    
}

int main(){

    ListNode* node = new ListNode(1);
    node->next = new ListNode(2);
    node->next->next = new ListNode(2);
    node->next->next->next = new ListNode(3);

    if(isPalindrome(node)) cout<<"True"<<endl;
    else cout<<"False"<<endl;


    return 0;
}