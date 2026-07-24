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
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
    if (!head) return nullptr;


    ListNode dummy(-1);

    ListNode* result = &dummy;


    

    int length = 0;
    ListNode* h = head;
    while (h) {
        length++;
        h = h->next;
    }


   for(int k = 0 ; k < length ; k++){
        h = head;

        for(int j = 0 ; j < length -k -1 ; j++)
            h = h->next;

        result->next= h;
        result = result->next;
        result->next = nullptr;



   }


return dummy.next;

}

};