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

char max3(int a[]) {
	char tobcj[] = {'B', 'C', 'J'};
	int res = a[0] >= a[1] ? 0 : 1;
	res = a[res] >= a[2] ? res : 2;
	return tobcj[res];
}

int sum(int a[]) {
	return a[0] + a[1] + a[2];
}

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);

	int bcj[2][3]; // win times for B, C, J
	memset(bcj, 0, sizeof(bcj));

	for (int i = 0; i < n; i++) {
		char a, b;
		scanf(" %c %c", &a, &b);

		int an = tonum(a), bn = tonum(b);
		switch (bn - an) {
			case 1:
			case -2:
				bcj[0][an]++;
				break;
			case -1:
			case 2:
				bcj[1][bn]++;
				break;
		}
	}

	int win = sum(bcj[0]), lose = sum(bcj[1]), draw = n - win - lose; // a
	printf("%d %d %d\n%d %d %d\n", win, draw, lose, lose, draw, win);
	printf("%c %c", max3(bcj[0]), max3(bcj[1]));
	return 0;
}
