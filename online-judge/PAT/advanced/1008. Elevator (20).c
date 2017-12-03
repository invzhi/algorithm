#include <stdio.h>

// Sample Input:
// 3 2 3 1
// Sample Output:
// 41

// 6 up, 4 down, 5 each step

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);

	int time = 0, now = 0;

	for (int i = 0; i < n; i++) {
		int request;
		scanf("%d", &request);

		if (request > now) {
			time += 6 * (request - now);
		} else {
			time += 4 * (now - request);
		}
		now = request;
		time += 5;
	}

	printf("%d", time);

	return 0;
}
