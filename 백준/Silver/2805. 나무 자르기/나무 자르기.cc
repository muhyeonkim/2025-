#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	vector<int>v;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	int low = 0, mid = 0, high = v[n - 1], res = 0;
	while (low <= high) {
		long long int sum = 0;
		mid = (low + high) / 2;
		for (int i = 0; i < n; i++) {
			if (v[i] > mid) {
				sum += v[i] - mid;
			}
		}
		if (sum >= m) {
			res = mid;
			low = mid + 1;
		}
		else  high = mid - 1;
	}
	cout << res;
}