#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	char face[3][10][5];

	int cnt[3];
	memset(cnt, 0, sizeof(cnt));

	char c;
	for (int i = 0; i < 3; ) {
		c = getchar();
		if (c == '[') {
			scanf("%[^]]", face[i][cnt[i]]);
			cnt[i]++;
		} else if (c == '\n') {
			i++;
		}
	}

	int k;
	scanf("%d", &k);

	for (int i = 0; i < k; i++) {
		int id[5];
		int isexist = 1;
		for (int j = 0; j < 5; j++) {
			scanf("%d", &id[j]);
			if (id[j] <= 0 || id[j] > cnt[2-abs(j-2)]) {
				isexist = 0;
			} else {
				id[j]--;
			}
		}
		if (isexist) {
			printf("%s(%s%s%s)%s\n", face[0][id[0]], face[1][id[1]], face[2][id[2]], face[1][id[3]], face[0][id[4]]);
		} else {
			puts("Are you kidding me? @\\/@");
		}
	}
	
	return 0;
}
