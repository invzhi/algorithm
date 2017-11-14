#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);

	int k = 0; // legal number count
	float sum = 0.0;

	for (int i = 0; i < n; i++) {
		char s[100];
		scanf("%s", s);

		char* dot = strchr(s, '.');
		char* endptr;
		float num = strtof(s, &endptr);

		if (*endptr != '\0' || (dot && endptr-dot > 3) || num < -1000.0 || num > 1000) {
			printf("ERROR: %s is not a legal number\n", s);
		} else {
			sum += num;
			k++;
		}
	}

	if (k == 0) {
		puts("The average of 0 numbers is Undefined");
	} else {
		printf("The average of %d number%s is %.2f\n", k, k > 1 ? "s" : "", sum/k);
	}

	return 0;
}
