#include <stdio.h>

typedef struct {
	char id[15];
	int seat;
} student;

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);

	student stus[n];
	for (int i = 0; i < n; i++) {
		int test;
		student s;
		scanf("%s %d %d", &s.id, &test, &s.seat);
		stus[test] = s;
	}

	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int test;
		scanf("%d", &test);
		printf("%s %d\n", stus[test].id, stus[test].seat);
	}

	return 0;
}
