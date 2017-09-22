#include <cstdio>
#include <algorithm>

using namespace std;

typedef struct {
	int begin;
	int end;
} timeSolt;

int cmp(timeSolt a, timeSolt b) {
	return a.end < b.end;
}

timeSolt list[100];

int main() {
	int n;
	while (scanf("%d", &n) && n) {
		for (int i = 0; i < n; i++) {
			scanf("%d%d", &list[i].begin, &list[i].end);
		}
		sort(list, list + n, cmp);
		int pre = list[0].end;
		int cnt = 1;
		for (int i = 1; i < n; i++) {
			if (pre <= list[i].begin) {
				pre = list[i].end;
				cnt++;
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}
