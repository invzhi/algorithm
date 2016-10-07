/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
	struct ListNode *first, *second, *last;
	if (head && head -> next) {
		last = first = head;
		head = head -> next;
	} else return head;
	while (first && (second = first -> next)) {
		last -> next = second;
		first -> next = second -> next;
		second -> next = first;
		last = first;
		first = first -> next;
	}
	return head;
}