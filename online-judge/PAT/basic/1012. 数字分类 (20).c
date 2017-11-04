#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);

	int num;
	int a[5];
	char flag[5];
	memset(a, 0, sizeof(a));
	memset(flag, 0, sizeof(flag));

	int sign = 1; // a2: sign
	float cnt = 0.0; // a4: average

	for (int i = 0; i < n; i++) {
		scanf("%d", &num);
		switch (num % 5) {
			case 0:
				if ((num & 1) == 0) {
					flag[0] = 1;
					a[0] += num;
				}
				break;
			case 1:
				flag[1] = 1;
				a[1] += num * sign;
				sign = -sign;
				break;
			case 2:
				flag[2] = 1;
				a[2]++;
				break;
			case 3:
				flag[3] = 1;
				a[3] += num;
				cnt += 1.0;
				break;
			case 4:
				flag[4] = 1;
				if (num > a[4]) {
					a[4] = num;
				}
				break;
		}
	}

	for (int i = 0; i < 5; i++) {
		if (flag[i]) {
			if (i == 3) {
				printf(" %.1f", a[i]/cnt);
			} else {
				printf(i ? " %d" : "%d", a[i]);
			}
		} else {
			printf(i ? " N" : "N");
		}
	}
	return 0;
}
