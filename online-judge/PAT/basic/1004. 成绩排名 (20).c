#include <stdio.h>
#include <string.h>

#define N 11

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);

	char name[N], id[N];
	char name_max[N], id_max[N];
	char name_min[N], id_min[N];

	int score; // 0-100
	int max = -1, min = 101;
	for (int i = 0; i < n; i++) {
		scanf("%s %s %d", name, id, &score);
		if (score > max) {
			max = score;
			strcpy(name_max, name);
			strcpy(id_max, id);
		}
		if (score < min) {
			min = score;
			strcpy(name_min, name);
			strcpy(id_min, id);
		}
	}
	printf("%s %s\n", name_max, id_max);
	printf("%s %s\n", name_min, id_min);
	return 0;
}
