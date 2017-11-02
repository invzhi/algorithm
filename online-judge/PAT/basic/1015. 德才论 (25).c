#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int id;
	int a;
	int b;
	int sum;
	int rank;
} student;

int cmp(const void* a, const void* b) {
	student *s1 = (student*)a, *s2 = (student*)b;
	int res;
	if (s1->rank != s2->rank) { // rank
		res = s1->rank - s2->rank; // asc
	} else if (s1->sum != s2->sum) { // sum
		res = s2->sum - s1->sum; // desc
	} else if (s1->a != s2->a) { // a
		res = s2->a - s1->a; // desc
	} else { // id
		res = s1->id - s2->id; // asc
	}
	return res;
}

int get_rank(int h, int a, int b) {
	int rank;
	if (a >= h && b >= h) {
		rank = 1;
	} else if (a >= h) {
		rank = 2;
	} else if (a >= b) {
		rank = 3;
	} else {
		rank = 4;
	}
	return rank;
}

int main(int argc, char const *argv[])
{
	int n, l, h;
	scanf("%d %d %d", &n, &l, &h);
	student stus[n];
	int m = 0;
	for (int i = 0; i < n; i++) {
		int id, a, b;
		scanf("%d %d %d", &id, &a, &b);
		if (a >= l && b >= l) {
			stus[m].id = id;
			stus[m].a = a;
			stus[m].b = b;
			stus[m].sum = a + b;
			stus[m].rank = get_rank(h, a, b);
			m++;
		}
	}
	qsort(stus, m, sizeof(student), cmp);
	
	printf("%d\n", m);
	for (int i = 0; i < m; i++) {
		printf("%d %d %d\n", stus[i].id, stus[i].a, stus[i].b);
	}
	return 0;
}
