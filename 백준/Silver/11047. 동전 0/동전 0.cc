#include <iostream>
#include <vector>

using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	int n, k, cnt = 0;
	vector<int>v;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	while (k != 0) {
		while (k >= v[n - 1]) {
			k -= v[n - 1];
			cnt++;
		}
		n--;
	}
	cout << cnt;
}