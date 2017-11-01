#include <stdio.h>
#include <stdlib.h>

typedef struct {
	float cnt;
	float price;
} mooncake;

int cmp(const void* a, const void* b) {
	float f = ((mooncake*)b)->price - ((mooncake*)a)->price;
	int res;
	if (f > 0.0) {
		res = 1;
	} else if (f < 0.0) {
		res = -1;
	} else {
		res = 0;
	}
	return res;
}

int main(int argc, char const *argv[])
{
	int n, d;
	scanf("%d %d", &n, &d);

	mooncake cake[n];
	for (int i = 0; i < n; i++) {
		scanf("%f", &(cake[i].cnt));
	}
	for (int i = 0; i < n; i++) {
		scanf("%f", &(cake[i].price));
		cake[i].price /= cake[i].cnt;
	}
	qsort(cake, n, sizeof(mooncake), cmp);

	float money = 0.0;
	for (int i = 0; i < n; i++) {
		if (d >= cake[i].cnt) {
			money += cake[i].price * cake[i].cnt;
			d -= cake[i].cnt;
		} else {
			money += cake[i].price * d;
			break;
		}
	}

	printf("%.2f", money);
	return 0;
}
