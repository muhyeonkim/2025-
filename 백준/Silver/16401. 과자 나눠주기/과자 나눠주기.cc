#include <iostream>
#include <vector>
#include <algorithm>

/*
m명의 조카, n개의 과자
조카 1명에게 줄 수 있는 막대 과자의 최대 길이는?
모든 조카에게 같은 길이의 막대과자를 나눠줄 수 없으면 0을 출력
*/

using namespace std;

int main() {
	int m, n;
	vector<int>v;
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	int left = 1, right = v[n - 1], res = 0;
	while (left <= right) {
		int cnt = 0;
		int mid = (left + right) / 2;
		
		for (int i = 0; i < n; i++) {
			if (mid == 0) break;
			cnt += v[i] / mid;
		}
		
		if (cnt >= m) {
			res = mid;
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	cout << res;
}