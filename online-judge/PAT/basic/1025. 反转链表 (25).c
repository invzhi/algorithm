#include <stdio.h>
#include <stdlib.h>

#define N 100000

typedef struct {
	int addr;
	int data;
	int next;
} node;

void swap(node* a[], int i, int j) {
	node* tmp = a[i];
	a[i] = a[j];
	a[j] = tmp;
}

void reverse(node* a[], int begin, int end) {
	for (int i = begin, j = end - 1; i < j; i++, j--) {
		swap(a, i, j);
	}
}

int main(int argc, char const *argv[])
{
	int first, n, k; // 0 < n <= 10^5, 0 < k <= n
	scanf("%d %d %d", &first, &n, &k);

	node* nodes[N];
	for (int i = 0; i < n; i++) {
		node* newnode = (node*)malloc(sizeof(node));
		scanf("%d %d %d", &newnode->addr, &newnode->data, &newnode->next);
		nodes[newnode->addr] = newnode;
	}

	node* list[n];
	int cnt = 0; // some node is not on list
	for (int p = first; p != -1; p = nodes[p]->next) {
		list[cnt++] = nodes[p];
	}

	// Plan A
	for (int i = k; i <= cnt; i += k) {
		reverse(list, i-k, i);
	}

	for (int i = 0; i < cnt - 1; i++) {
		printf("%05d %d %05d\n", list[i]->addr, list[i]->data, list[i+1]->addr);
	}
	printf("%05d %d -1\n", list[cnt-1]->addr, list[cnt-1]->data);

	// Plan B
	// for (int i = k - 1; i < cnt; i += k) {
	// 	for (int j = 0; j < k - 1; j++) {
	// 		printf("%05d %d %05d\n", list[i-j]->addr, list[i-j]->data, list[i-j-1]->addr);
	// 	}
	// 	if (i + 1 == cnt) { // list[i] is last node
	// 		printf("%05d %d -1\n", list[i+1-k]->addr, list[i+1-k]->data);
	// 	} else {
	// 		int next = i + k < cnt ? i + k : i + 1; // next node is reversed?
	// 		printf("%05d %d %05d\n", list[i+1-k]->addr, list[i+1-k]->data, list[next]->addr);
	// 	}
	// }
	// for (int i = cnt/k*k; i < cnt; i++) {
	// 	if (i + 1 < cnt) {
	// 		printf("%05d %d %05d\n", list[i]->addr, list[i]->data, list[i+1]->addr);
	// 	} else {
	// 		printf("%05d %d -1\n", list[i]->addr, list[i]->data);
	// 	}
	// }
	return 0;
}
