#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

/*
k에 가까운 정수의 조합이 몇 개?
두 포인터를 더한다.
두 포인터와 k의 차를 구한다.(두 포인터와 k의 차가 0에 가까워야 함)
두 포인터와 k의 차와 res 값 중 더 작은 값을 min값으로 정한다.
두 포인터와 k의 차와 res 값이 0이면 cnt를 1증가한다.
res값이 변경되면 cnt를 초기화 한다.
두 포인터와 k의 차가 0보다 크고 작음에 따라 left,right를 조정함.

*/

using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		vector<int>v;
		int n, k;
		cin >> n >> k;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			v.push_back(x);
		}
		sort(v.begin(), v.end());
		int left = 0, right = n - 1, res = k + 1, sum = 0, cnt = 1;
		while (left < right) {
			sum = v[left] + v[right] - k;

			if (abs(sum) < abs(res)) {
				res = sum;
				cnt = 1;
			}
			else if (abs(sum) == abs(res)) {
				cnt++;
			}

			if (sum >= 0) {
				right--;
			}
			else if (sum < 0) {
				left++;
			}
		}
		cout << cnt << "\n";
	}
}