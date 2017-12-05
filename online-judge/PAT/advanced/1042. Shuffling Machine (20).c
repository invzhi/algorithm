#include <stdio.h>

#define N 54

void print_card(int i) {
	char tochar[] = {'S', 'H', 'C', 'D', 'J'};
	printf("%c%d", tochar[i/13], i%13 + 1);
}

// a -> b
void shuffle(int a[], int b[], int order[], int n) {
	if (n == 0) return;
	for (int i = 0; i < N; i++) {
		b[order[i]-1] = a[i];
	}
	shuffle(b, a, order, n-1);
}

int main(int argc, char const *argv[])
{
	int k; // [1, 20]
	scanf("%d", &k);

	int order[N];
	int copy1[N], copy2[N];

	for (int i = 0; i < N; i++) {
		scanf("%d", &order[i]);
		copy1[i] = i;
	}

	shuffle(copy1, copy2, order, k);

	int* cards = (k & 1) ? copy2 : copy1;

	print_card(cards[0]);
	for (int i = 1; i < N; i++) {
		putchar(' ');
		print_card(cards[i]);
	}

	return 0;
}
