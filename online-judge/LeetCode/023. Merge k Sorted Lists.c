/**
 * Definition for singly-linked list.
 * struct ListNode {
 *	 int val;
 *	 struct ListNode *next;
 * };
 */
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

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
	if (listsSize == 0) return NULL;
	if (listsSize == 1) return lists[0];
	int i, j;
	for (i = 2; i / 2 < listsSize; i *= 2) {
		for (j = 0; j < listsSize; j += i) {
			if (j + i / 2 < listsSize) {
				lists[j] = mergeTwoLists(lists[j], lists[j + i / 2]);
			}
		}
	}
	return lists[0];
}
