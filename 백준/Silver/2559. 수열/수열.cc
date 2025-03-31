#include <iostream>
#include <climits>
#include <vector>

using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	int n, k;
	vector<int>v;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	int sum = 0, max_temp = INT_MIN;
	for (int i = 0; i < k; i++) {
		sum += v[i];
	}
	max_temp = sum;
	for (int right = k; right < n; right++) {
		sum += v[right] - v[right - k];
		max_temp = max(max_temp, sum);
	}
	cout << max_temp;
}