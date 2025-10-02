#include<iostream>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// ListNode* reverseList(ListNode* head) {
//     if (!head) return nullptr;


//     ListNode dummy(-1);

//     ListNode* result = &dummy;


    

//     int length = 0;
//     ListNode* h = head;
//     while (h) {
//         length++;
//         h = h->next;
//     }


//    for(int k = 0 ; k < length ; k++){
//         h = head;

//         for(int j = 0 ; j < length -k -1 ; j++)
//             h = h->next;

//         result->next= h;
//         result = result->next;
//         result->next = nullptr;



//    }


// return dummy.next;

// }
// // 

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


int main(){

    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(2);
    list2->next->next = new ListNode(3);



    list2 = reverseList(list2);

    while(list2){

    cout<<list2->val<<" ";
    list2 = list2->next;
    }


    return 0;
}