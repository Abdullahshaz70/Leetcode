#include<iostream>
#include<vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* createList(vector<int> vals) {
    if (vals.empty()) return nullptr;
    ListNode* head = new ListNode(vals[0]);
    ListNode* current = head;
    for (int i = 1; i < vals.size(); i++) {
        current->next = new ListNode(vals[i]);
        current = current->next;
    }
    return head;
}

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


ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* root = nullptr;

        for(int i = 0 ; i < lists.size() ; i++)
        root = mergeTwoLists(root , lists[i]);

        return root;
}

int main(){

    vector<ListNode*> lists;

    lists.push_back(createList({1,4,5}));
    lists.push_back(createList({1,3,4}));
    lists.push_back(createList({2,6}));

    ListNode* root= mergeKLists(lists);

    while(root){

        cout<<root->val<<" ";
        root = root->next;
    }


    return 0;
}

