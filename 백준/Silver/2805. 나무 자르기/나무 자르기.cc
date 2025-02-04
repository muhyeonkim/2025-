#include <iostream>
#include <algorithm>
#include <vector>
/*
매개변수
*/

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector<long long int>v;
	long long n, m, max_h = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		long long int h;
		cin >> h;
		v.push_back(h);
	}
	sort(v.begin(), v.end());
	long long left = 0, right = v[n - 1], sum = 0, mid = 0;
	while (left <= right) {
		sum = 0;
		mid = (left + right) / 2;
		for (int i = 0; i < n; i++) {
			if (mid < v[i]) {
				sum += v[i] - mid;
			}
		}
		if (m <= sum) {
			max_h = mid;
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	cout << max_h;
}