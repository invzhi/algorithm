#include <cstdio>
#include <map>

using namespace std;

int main(int argc, char const *argv[])
{
	int m, n;
	scanf("%d %d", &m, &n);

	map<int, int> cnt;
	int pixels = n * m;
	int half = pixels / 2;
	for (int i = 0; i < pixels; i++) {
		int color;
		scanf("%d", &color);
		cnt[color]++;
		if (cnt[color] > half) {
			printf("%d", color);
		}
	}

	return 0;
}
