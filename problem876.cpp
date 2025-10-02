#include<iostream>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};

ListNode* middleNode(ListNode* head) {
    
    if(!head) return nullptr;

    ListNode* slow = head;
    ListNode* fast = head;

    while(fast && fast->next){

        slow = slow->next;
        fast = fast->next->next;

    }

    return slow ;

}

int main(){

    
    ListNode* node = new ListNode(1);
    node->next = new ListNode(2);
    node->next->next = new ListNode(3);
    node->next->next->next = new ListNode(4);
    node->next->next->next->next = new ListNode(5);
    node->next->next->next->next->next = new ListNode(6);

    node = middleNode(node);

    cout<<node->val<<endl;

    return 0;
}