#include <stdio.h>

void insert(int a[], int i) {
	int tmp = a[i];
	for (; i > 0 && a[i-1] > tmp; i--) {
		a[i] = a[i-1];
	}
	a[i] = tmp;
}

void quick_merge(int a[], int t[], int lo, int mid, int hi) {
	for (int i = lo; i <= mid; i++) {
		t[i] = a[i];
	}
	for (int i = hi; i > mid; i--) {
		t[i] = a[hi - i + mid + 1];
	}

	int i = lo, j = hi;
	for (int k = lo; k <= hi; k++) {
		if (t[i] < t[j]) a[k] = t[i++];
		else             a[k] = t[j--];
	}
}

int main(int argc, char const *argv[])
{
	int n; // 0 < n <= 100
	scanf("%d", &n);

	int src[n], dest[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &src[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &dest[i]);
	}

	int i = 1;
	while (i < n && dest[i-1] <= dest[i]) {
		i++;
	}
	int j = i;
	while (j < n && src[j] == dest[j]) {
		j++;
	}

	if (j == n) {
		puts("Insertion Sort");
		insert(dest, i);
	} else {
		puts("Merge Sort");
		int t[n];
		for (int l = 1; l <= n; l += l) {
			int ismerged = 1;
			for (int lo = 0; lo + l < n; lo += l + l) {
				int mid = lo + l - 1;
				if (ismerged == 0 || dest[mid] > dest[mid+1]) {
					ismerged = 0;
					int hi = lo + l + l - 1;
					hi = hi < n ? hi : n - 1;
					quick_merge(dest, t, lo, mid, hi);
				}
			}
			if (ismerged == 0) {
				break;
			}
		}
	}

	printf("%d", dest[0]);
	for (int i = 1; i < n; i++) {
		printf(" %d", dest[i]);
	}
	return 0;
}
