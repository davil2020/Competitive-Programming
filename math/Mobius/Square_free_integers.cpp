#include <iostream>
#include <vector>

using namespace std;

const int VALMAX = 1e7;

int mobius[VALMAX];

int main() {
	int test_num;
	cin >> test_num;

	mobius[1] = -1;
	for (int i = 1; i < VALMAX; i++) {
		if (mobius[i]) {
			mobius[i] = -mobius[i];
			for (int j = 2 * i; j < VALMAX; j += i) { mobius[j] += mobius[i]; }
		}
	}

	for (int t = 0; t < test_num; t++) {
		long long n;
		long long ans = 0;
		cin >> n;
		for (int i = 1; 1LL * i * i <= n; i++) {
			ans += mobius[i] * n / ((long long)i * i);
		}
		cout << ans << '\n';
	}
}