#include <bits/stdc++.h>
using namespace std;

template <class T> class BIT {
  private:
	int size;
	vector<T> bit;
	vector<T> arr;
  public:
	BIT(int size) : size(size), bit(size + 1), arr(size) {}
	void set(int ind, T val) { add(ind, val - arr[ind]); }
	void add(int ind, T val) {
		arr[ind] += val;
		ind++;
		for (; ind <= size; ind += ind & -ind) { bit[ind] += val; }
	}
	T pref_sum(int ind) {
		ind++;
		T total = 0;
		for (; ind > 0; ind -= ind & -ind) { total += bit[ind]; }
		return total;
	}
};
const int MAX_POS = 1e6;
int main() {
	int n;
	cin >> n;
	vector<array<int, 4>> v;
	for (int i = 0, x1, y1, x2, y2; i < n; ++i) {
		cin >> x1 >> y1 >> x2 >> y2;
		if (y1 == y2) v.push_back({y1, 2, x1, x2});
		else {
			v.push_back({y1, 1, x1, 1});
			v.push_back({y2, 3, x1, 1});
		}
	}
	sort(begin(v), end(v));
	BIT<int> bit(2 * MAX_POS + 1);
	long long ans = 0;
	for (auto [y, type, x1, x2] : v) {
		x1 += MAX_POS;
		x2 += MAX_POS;
		if (type == 1) {
			bit.add(x1, 1);
		} else if (type == 2) {
			ans += bit.pref_sum(x2) - bit.pref_sum(x1 - 1);
		} else {
			bit.add(x1, -1);
		}
	}
	cout << ans << endl;
}