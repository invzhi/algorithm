#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int id;
	int score[4];
	int order[4];
	int best;
} student;

int flag = -1;
int stu_i[1000000];

int cmp(const void* a, const void* b) {
	return (*((student**)b))->score[flag] - (*((student**)a))->score[flag];
}

student* get_student(int id, int c, int m, int e) {
	student* stu = (student*) malloc(sizeof(student));
	stu->id = id;
	stu->score[0] = (c + m + e) / 3.0 + 0.5;
	stu->score[1] = c;
	stu->score[2] = m;
	stu->score[3] = e;
	return stu;
}

void print(student* s) {
	printf("%d ", s->id);
	for (int i = 0; i < 4; i++) {
		printf(" %d", s->order[i]);
	}
	printf(" %d\n", s->best);
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	student* students[n];

	for (int i = 0; i < n; i++) { // store
		int id, c, m, e;
		scanf("%d %d %d %d", &id, &c, &m, &e);
		student* stu = get_student(id, c, m, e);
		students[i] = stu;
	}

	for (flag = 0; flag < 4; flag++) { // get order
		qsort(students, n, sizeof(student*), cmp);
		for (int i = 0; i < n; i++) {
			if (i > 0 && students[i]->score[flag] == students[i-1]->score[flag]) {
				students[i]->order[flag] = students[i-1]->order[flag];
			} else {
				students[i]->order[flag] = i + 1;
			}
		}
	}

	memset(stu_i, 0, sizeof(stu_i));
	for (int i = 0; i < n; i++) {
		int best, min = 101;
		for (int j = 0; j < 4; j++) {
			if (students[i]->order[j] < min) {
				min = students[i]->order[j];
				best = j;
			}
		}
		students[i]->best = best; // get best
		stu_i[students[i]->id] = i + 1; // build index
	}

	char tochar[] = {'A', 'C', 'M', 'E'};
	for (int i = 0; i < m; i++) {
		int id;
		scanf("%d", &id);

		int idx = stu_i[id];
		if (idx) {
			int best = students[idx-1]->best;
			printf("%d %c\n", students[idx-1]->order[best], tochar[best]);
		} else {
			puts("N/A");
		}
	}

	return 0;
}
