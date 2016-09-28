/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
	struct ListNode *p, *q;
	p = q = head;
	while (n--) p = p->next;
	if (p == NULL) return head->next;
	while (p->next) {
		p = p->next;
		q = q->next;
	}
	q->next = q->next->next;
	return head;
}