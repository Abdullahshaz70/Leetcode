#include<iostream>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head) {
    
    if(!head) return false;

    ListNode* slow = head;
    ListNode* fast = head;

    

    while(fast && fast->next ){

        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast) return true;

    }

    return false;


}

int main(){

    ListNode* node = new ListNode(3);
    // node->next = new ListNode(2);
    // node->next->next = new ListNode(0);
    // node->next->next->next = new ListNode(-4);
    // node->next->next->next->next = node->next;
   
    if(hasCycle(node)) cout<<"Has cycle"<<endl;
    else cout<<"not cycle"<<endl;

    return 0;
}