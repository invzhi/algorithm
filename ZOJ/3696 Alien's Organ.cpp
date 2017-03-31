#include <cstdio>
#include <cmath>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <climits>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int T;
	int N;
	double n;
	cin >> T;
	while (T--) {
		double ans = 0;
		cin >> N >> n;
		for (int i = 0; i <= N; i++) {
			double tmp = pow(n, i);
			for (int j = 2; j <= i; j++) tmp /= j;
			ans += tmp;
		}
		printf("%.3f\n", ans/exp(n));
	}
	return 0;
}