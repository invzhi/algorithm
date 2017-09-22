#include <cstdio>
#include <algorithm>

using namespace std;

int out[10000];

int main() {
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &out[i]);
	sort(out, out + N);
	printf("%d", out[(N - 1) / 2]);
	return 0;
}
