#include <stdio.h>
#include <ctype.h>

int main(int argc, char const *argv[])
{
	int n; // 0 < n <= 100
	scanf("%d", &n);

	int weights[] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
	char m[] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};

	int pass = 1;
	for (int i = 0; i < n; i++) {
		char id[19];
		scanf("%s", id);
		int sum = 0;
		int notdight = 0;
		for (int j = 0; j < 17; j++) {
			if (isdigit(id[j])) {
				sum += weights[j] * (id[j] - '0');
			} else {
				notdight = 1;
				break;
			}
		}
		if (notdight || id[17] != m[sum % 11]) {
			pass = 0;
			puts(id);
		}
	}
	if (pass) {
		puts("All passed");
	}

	return 0;
}
