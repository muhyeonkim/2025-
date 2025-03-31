#include <iostream>
#include <vector>
#include <algorithm>
/*
막걸리 주전자 n개, k명에게 같은 양으로 막걸리 나눠주기
분배 후 나눠 줄 수 없으면 버림
인당 분배할 수 있는 최대 막걸리는?
*/

using namespace std;

int main() {
	int n, k;
	vector<int>v;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	int left = 1, right = v[n - 1], res = 0;
	while (left <= right) {
		int mid = left + (right - left) / 2;
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			cnt += v[i] / mid;
		}
		if (cnt >= k) {
			res = mid;
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	cout << res;
}