#include <cstdio>
#include <algorithm>

using namespace std;

int x[10000], y[10000];

int main() {
	int n;
	int cnt = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d%d", &x[i], &y[i]);
	sort(x, x + n);
	sort(y, y + n);
	for (int i = 0; i < n; i++) x[i] -= i;
	sort(x, x + n);
	for (int i = 0, j = n - 1; i < j; i++, j--) cnt += (x[j] - x[i]) + (y[j] - y[i]);
	printf("%d\n", cnt);
	return 0;
}
