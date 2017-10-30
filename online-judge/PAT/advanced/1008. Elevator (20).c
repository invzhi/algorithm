#include <stdio.h>

// Sample Input:
// 3 2 3 1
// Sample Output:
// 41

// 6 up, 4 down, 5 each step

int main(int argc, char const *argv[])
{
	int n, floor;
	int time = 0, now = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &floor);
		if (floor > now) {
			time += 6 * (floor - now);
		} else {
			time += 4 * (now - floor);
		}
		now = floor;
		time += 5;
	}
	printf("%d", time);
	return 0;
}
