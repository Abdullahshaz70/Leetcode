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
    ListNode* deleteDuplicates(ListNode* head) {

	ListNode* prev = nullptr;
	ListNode* curr = head;

	while (curr) {

		if (prev and prev->val == curr->val) {
			curr = curr->next;
			prev->next = curr;
			continue;
		}

		ListNode* next = curr->next;
		prev = curr;
		curr = next;
	}

	return head;
}

};