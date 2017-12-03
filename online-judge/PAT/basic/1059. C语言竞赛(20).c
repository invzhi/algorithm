#include <stdio.h>
#include <string.h>

#define N 10000

int is_prime(int num) {
	if (num <= 2) { // 1 or 2
		return num == 1 ? 0 : 1;
	} else if ((num & 1) == 0) {
		return 0;
	}
	for (int i = 3; i * i <= num; i += 2) {
		if (num % i == 0) {
			return 0;
		}
	}
	return 1;
}

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);

	int order[N]; // none: 0, checked: -1
	memset(order, 0, sizeof(order));
	for (int i = 0; i < n; i++) {
		int id;
		scanf("%d", &id);
		order[id] = i+1;
	}

	int k;
	scanf("%d", &k);

	for (int i = 0; i < k; i++) {
		int id;
		scanf("%d", &id);
		printf("%04d: ", id);
		switch (order[id]) {
		case -1:
			puts("Checked");
			break;
		case 0:
			puts("Are you kidding?");
			break;
		case 1:
			puts("Mystery Award");
			order[id] = -1;
			break;
		default:
			if (is_prime(order[id])) {
				puts("Minion");
			} else {
				puts("Chocolate");
			}
			order[id] = -1;
		}
	}

	return 0;
}
