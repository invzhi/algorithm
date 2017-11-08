#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int k;
	int a;
	int b;
} number;

long get_gcd(long a, long b) {
	if (b) while ((a %= b) && (b %= a));
	return a + b;
}

number* get_num(long a, long b) {
	long gcd = get_gcd(a, b);
	a /= gcd;
	b /= gcd;
	if (b < 0) {
		b = -b;
		a = -a;
	}
	number* new_num = (number*)malloc(sizeof(number));
	if (b != 0) {
		new_num->k = a / b;
		new_num->a = a % b;
		if (new_num->k < 0 && a < 0) {
			new_num->a *= -1;
		}
	}
	new_num->b = b;
	return new_num;
}

void print_num(number* num) {
	if (num->b == 0) {
		printf("Inf");
		return;
	}
	if (num->k < 0 || num->a < 0) {
		printf("(");
	}
	if (num->k != 0 && num->a != 0) {
		printf("%d %d/%d", num->k, num->a, num->b);
	} else if (num->a != 0) { // num->k == 0
		printf("%d/%d", num->a, num->b);
	} else {
		printf("%d", num->k);
	}
	if (num->k < 0 || num->a < 0) {
		printf(")");
	}
}

int main(int argc, char const *argv[])
{
	long a1, b1, a2, b2;
	scanf("%ld/%ld %ld/%ld", &a1, &b1, &a2, &b2);

	number* num1 = get_num(a1, b1);
	number* num2 = get_num(a2, b2);

	char operators[4] = {'+', '-', '*', '/'};
	for (int i = 0; i < 4; i++) {
		number* res;
		print_num(num1);
		printf(" %c ", operators[i]);
		print_num(num2);
		printf(" = ");
		switch (i) {
			case 0:
				res = get_num(a1*b2 + a2*b1, b1*b2);
				break;
			case 1:
				res = get_num(a1*b2 - a2*b1, b1*b2);
				break;
			case 2:
				res = get_num(a1*a2, b1*b2);
				break;
			case 3:
				res = get_num(a1*b2, b1*a2);
				break;
		}
		print_num(res);
		printf("\n");
	}
	return 0;
}
