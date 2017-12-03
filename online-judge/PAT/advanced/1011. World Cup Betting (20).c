#include <stdio.h>

int main() {
	char best[] = {'W', 'T', 'L'};
	float res = 1.0;

	for (int i = 0; i < 3; i++) {
		float max = -1.0;
		int max_i;

		for (int j = 0; j < 3; j++) {
			float info;
			scanf("%f", &info);
			if (info > max) {
				max = info;
				max_i = j;
			}
		}

		printf("%c ", best[max_i]);
		res *= max;
	}

	printf("%.2f", (res*0.65 - 1.0)*2);

	return 0;
}
