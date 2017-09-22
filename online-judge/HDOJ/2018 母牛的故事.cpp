#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n;
	int a, b, c, d;
	int num[55];
	a = b = c = 0;
	d = 1;
	num[1] = 1;
	for (int i = 2; i < 55; i++) {
		d += c;
		c = b;
		b = a;
		a = d;
		num[i] = a + b + c + d;
	}
	while (cin >> n && n) cout << num[n] << endl;
	return 0;
}
