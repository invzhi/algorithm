#include <stdio.h>
#include <string.h>
#include <ctype.h>

int tonum(char c) {
	if (isdigit(c)) {
		return c - '0';
	} else {
		return c - 'a' + 10;
	}
}

long todecimal(char str[], int n, long radix) {
	long res = 0;
	for (int i = 0; i < n; i++) {
		res = res*radix + tonum(str[i]);
	}
	return res;
}

int max_num(char str[]) {
	int max = 0;
	for (int i = 0; str[i] != '\0'; i++) {
		int num = tonum(str[i]);
		if (num > max) {
			max = num;
		}
	}
	return max;
}

int main(int argc, char const *argv[])
{
	char n1[11], n2[11];
	int tag;
	long radix;
	scanf("%s %s %d %ld", n1, n2, &tag, &radix);

	long decimal;
	char* other;
	if (tag == 1) {
		decimal = todecimal(n1, strlen(n1), radix);
		other = n2;
	} else {
		decimal = todecimal(n2, strlen(n2), radix);
		other = n1;
	}

	int impossible = 1;

	int n = strlen(other);
	long low = max_num(other) + 1, high = decimal + 1;
	while (low <= high) {
		long mid = low + (high - low) / 2;
		long num = todecimal(other, n, mid);
		if (num < 0 || num > decimal) { // attention: be careful about overflow
			high = mid - 1;
		} else if (num < decimal) {
			low = mid + 1;
		} else {
			printf("%ld", mid);
			impossible = 0;
			break;
		}
	}
	if (impossible) {
		puts("Impossible");	
	}

	return 0;
}
