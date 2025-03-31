#include <iostream>
#include <vector>

using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	int n, s;
	vector<int>v;
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	int left = 0, min_length = n + 1, sum = 0;
	for (int i = 0; i < n; i++) {
		sum += v[i];

		while (sum >= s) {
			min_length = min(min_length, i - left + 1);
			sum -= v[left];
			left++;
			//cout << sum << ' ' << min_length << "\n";
		}
	}
	if (min_length == n + 1) cout << 0;
	else cout << min_length;
}