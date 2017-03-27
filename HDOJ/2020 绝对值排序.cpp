#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

#define MAXN 100

using namespace std;

int num[MAXN];

bool cmp(int a, int b) {
	return abs(a) > abs(b);
}

int main() {
	int i, n;
	while (cin >> n && n) {
		for (i = 0; i < n; i++) {
			cin >> num[i];
		}
		sort(num, num + n, cmp);
		for (i = 0; i < n - 1; i++) {
			cout << num[i] << ' ';
		}
		cout << num[i] << endl;
	}
	return 0;
}