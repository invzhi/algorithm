#include <stdio.h>
#include <string.h>

// Sample Input: 0 < N < 100, M < N
// 2 1
// 01 1 02
// Sample Output
// 0 1

#define N 100

typedef struct node {
	struct node* child;
	struct node* brother;
} node_t;

node_t nodes[N];
int max_level;

void count_leaves(int leaves[], int level, node_t* node) {
	max_level = level;

	while (node) {
		if (node -> child) {
			count_leaves(leaves, level + 1, node -> child);
		} else {
			leaves[level]++;
		}
		node = node -> brother;
	}
}

int main(int argc, char const *argv[])
{
	int n, m; // n is not be used
	scanf("%d%d", &n, &m);

	int id, child_cnt, child_id;
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &id, &child_cnt);
		
		scanf("%d", &child_id);
		node_t* child = nodes[id].child = &nodes[child_id];
		for (int j = 1; j < child_cnt; j++) {
			scanf("%d", &child_id);
			child = child -> brother = &nodes[child_id];
		}
		child -> brother = NULL;
	}

	int leaves[N];
	memset(leaves, 0, sizeof(int) * N);
	count_leaves(leaves, 1, &nodes[1]);

	for (int i = 1; i < max_level; i++) {
		printf("%d ", leaves[i]);
	}
	printf("%d", leaves[max_level]);
	return 0;
}
