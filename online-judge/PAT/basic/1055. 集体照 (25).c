#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char name[9];
	int height;
} person;

int cmp(const void* a, const void* b) {
	person *p1 = (person*)a, *p2 = (person*)b;
	if (p1->height != p2->height) {
		return p2->height - p1->height;
	} else {
		return strcmp(p1->name, p2->name);
	}
}

void printRow(person p[], int n) { // careful if n == 1
	for(int i = n / 2 * 2 - 1; i > 0; i -= 2) {
		printf("%s ", p[i].name);
	}
	for(int i = 0; i < n; i += 2) {
		printf("%s%c", p[i].name, i + 2 < n ? ' ' : '\n');
	}
}

int main(int argc, char const *argv[])
{
	int n, k;
	scanf("%d %d", &n, &k);

	person ps[n];
	for (int i = 0; i < n; i++) {
		scanf("%s %d", &ps[i].name, &ps[i].height);
	}
	qsort(ps, n, sizeof(person), cmp);

	int m = n / k;
	printRow(ps, m + n%k);
	for (int i = m + n%k; i < n; i += m) {
		printRow(ps+i, m);
	}

	return 0;
}
