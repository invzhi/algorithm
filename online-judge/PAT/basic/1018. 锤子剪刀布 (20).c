#include <stdio.h>
#include <string.h>

int tonum(char c) {
	int num;
	switch (c) {
		case 'B':
			num = 0;
			break;
		case 'C':
			num = 1;
			break;
		case 'J':
			num = 2;
			break;
	}
	return num;
}

int maxi(int a[], int n) {
	int max = 0, max_i = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] > max) {
			max = a[i];
			max_i = i;
		}
	}
	return max_i;
}

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);

	int cnt[2][3]; // win, draw, lose
	int bcj[2][3]; // win time for B, C, J
	memset(cnt, 0, sizeof(cnt));
	memset(bcj, 0, sizeof(bcj));

	for (int i = 0; i < n; i++) {
		char a, b;
		scanf(" %c %c", &a, &b);

		int an = tonum(a), bn = tonum(b);
		int d = bn - an;
		switch (d) {
			case 1:
			case -2:
				cnt[0][0]++; // a win
				cnt[1][2]++; // b lose
				bcj[0][an]++;
				break;
			case -1:
			case 2:
				cnt[1][0]++; // b win
				cnt[0][2]++; // a lose
				bcj[1][bn]++;
				break;
			default:
				cnt[0][1]++; // a draw
				cnt[1][1]++; // b draw
				break;
		}
	}

	for (int i = 0; i < 2; i++) {
		printf("%d %d %d\n", cnt[i][0], cnt[i][1], cnt[i][2]);
	}

	char tobcj[] = {'B', 'C', 'J'};
	int maxai = maxi(bcj[0], 3);
	int maxbi = maxi(bcj[1], 3);
	printf("%c %c", tobcj[maxai], tobcj[maxbi]);
	return 0;
}
