#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

int main() {
	int n;
	double score;
	while (cin >> n) {
		double max = -1, min = 101;
		double sum = 0;
		for (int i = 0; i < n; i++) {
			cin >> score;
			if (score > max) max = score;
			else if (score < min) min = score;
			sum += score;
		}
		sum = sum - max - min;
		cout << setprecision(2) << fixed << sum / (n - 2) << endl;
	}
	return 0;
}