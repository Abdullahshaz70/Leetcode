#include<iostream>

using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};

ListNode *detectCycle(ListNode *head) {

    if(!head) return nullptr;
    ListNode* slow = head;
    ListNode* fast = head;
    
    while(fast && fast->next){

        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast) {

            ListNode* entry = head;

            while(entry!=slow){
                slow = slow->next;
                entry = entry->next;
            }

            return entry;

        }

    }
    
    return nullptr;
}

int main(){

    ListNode* node = new ListNode(1);
    node->next = new ListNode(2);
    node->next->next = new ListNode(0);
    node->next->next->next = new ListNode(-4);
    node->next->next = node->next;

    // ListNode* node = new ListNode(1);
    // node->next = new ListNode(2);
    // node->next->next = node;

    // ListNode* node = new ListNode(1);
 

    ListNode* rec = detectCycle(node);

    int n = 0;
    while(node && rec){

        if(node == rec)
        break;

        n++;

        node = node->next;
    }

    if (!rec) n = -1;
    

    cout<<n;
   


    return 0;
}