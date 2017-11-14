#include <stdio.h>

int main(int argc, char const *argv[])
{
	int n, d;
	float e;
	scanf("%d %f %d", &n, &e, &d);

	int pempty = 0, empty = 0;

	for (int i = 0; i < n; i++) {
		int k;
		scanf("%d", &k);

		int lowday = 0;

		for (int j = 0; j < k; j++) {
			float energy;
			scanf("%f", &energy);
			if (energy < e) {
				lowday++;
			}
		}

		if (lowday > k/2) {
			if (k > d) {
				empty++;
			} else {
				pempty++;
			}
		}
	}

	printf("%.1f%% %.1f%%", 100.0*pempty/n, 100.0*empty/n);
	
	return 0;
}
