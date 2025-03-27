#include <iostream>
#include <vector>
#include <algorithm>

/*
최대 랜선 길이?
*/

using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout.tie(0);

	int k, n;
	vector<long long int>v;
	cin >> k >> n;
	for (int i = 0; i < k; i++) {
		long long int x;
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	long long int low = 1, mid = 0, high = v[k - 1], res = 0;
	while (low <= high) {
		int sum = 0; // 만들 수 있는 랜선의 개수
		mid = (low + high) / 2;
		for (int i = 0; i < k; i++) {
			sum += v[i] / mid; 
		}
		if (sum >= n) { //덜 만들어야 하는 경우는 길이를 더 길게
			res = mid;
			low = mid + 1;
		}
		else { // 더 만들어야 하는 경우는 길이를 더 짧게
			high = mid - 1;
		}
	}
	cout << res;
}