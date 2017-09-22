/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
	struct ListNode* head = (struct ListNode*) malloc(sizeof(struct ListNode));
	struct ListNode* p = head;
	while (l1 && l2) {
		if (l1 -> val < l2 -> val) {
			p -> next = l1;
			l1 = l1 -> next;
		} else {
			p -> next = l2;
			l2 = l2 -> next;
		}
		p = p -> next;
		p -> next = NULL;
	}
	if (l1) p -> next = l1;
	if (l2) p -> next = l2;
	p = head;
	head = head -> next;
	free(p);
	return head;
}

/* Recursion */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
	if (l1 == NULL) return l2;
	if (l2 == NULL) return l1;
	struct ListNode* p;
	if (l1 -> val < l2 -> val) {
		p = l1;
		p -> next = mergeTwoLists(p -> next, l2);
	} else {
		p = l2;
		p -> next = mergeTwoLists(l1, p -> next);
	}
	return p;
}
