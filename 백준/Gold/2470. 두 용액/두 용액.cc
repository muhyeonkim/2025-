#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

/*
정렬
left right
mid
값이 양수면 작아져야 하므로 right = mid-1
값이 음수면 left = mid +1
*/

using namespace std;

int res[2];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	vector<int>v;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	int left = 0, right = n - 1, sum = 2000000001;
	while (left < right) {
		if (abs(sum) > abs(v[left] + v[right])) {
			res[0] = v[left], res[1] = v[right];
			sum = v[left] + v[right];
		}
		if (v[left]+v[right] >= 0) {
			right--;
		}
		else {
			left++;
		}
	}
	cout << res[0] << ' ' << res[1];
}