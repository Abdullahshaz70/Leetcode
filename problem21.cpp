#include<iostream>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    
    ListNode dummy(-1);
    

    ListNode* result = &dummy;


    while(list1 && list2){

        
        if(list1->val < list2->val){
            result->next = list1;
            list1 = list1->next;
        }
        else{
            result->next = list2;
            list2 = list2->next;
        }
        result=result->next;
        
    } 
    result->next = list1 ? list1 : list2;

    return dummy.next;
}

int main(){

ListNode* list1 = new ListNode(1);
list1->next = new ListNode(2);
list1->next->next = new ListNode(4);

ListNode* list2 = new ListNode(1);
list2->next = new ListNode(2);
list2->next->next = new ListNode(3);

list1 = mergeTwoLists(list1 , list2);

while(list1){

    cout<<list1->val<<" ";
    list1 = list1->next;
}


    return 0;
}

