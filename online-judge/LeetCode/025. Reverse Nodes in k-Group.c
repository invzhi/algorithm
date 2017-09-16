/**
 * Definition for singly-linked list.
 * struct ListNode {
 *	 int val;
 *	 struct ListNode *next;
 * };
 */
struct ListNode* reverseKGroup(struct ListNode* head, int k) {
	if (head == NULL || k < 2) return head;
	struct ListNode *preHead = (struct ListNode*) malloc(sizeof(struct ListNode));
	struct ListNode *pre, *cur, *tail;
	int count, index = 0;
	preHead -> next = head;
	for (count = 0, pre = preHead; pre->next; count++) pre = pre -> next;
	count /= k;
	pre = preHead;
	tail = preHead -> next;
	while (index < count) {
		int i = k - 1;
		while (i--) {
			cur = tail -> next;
			tail -> next = cur -> next;
			cur  -> next = pre -> next;
			pre  -> next = cur;
		}
		pre  = tail;
		tail = tail -> next;
		index++;
	}
	return preHead -> next;
}