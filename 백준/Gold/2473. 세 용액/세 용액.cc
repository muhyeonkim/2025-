#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

/*
포인터 시작 0, n-1
3개의 합
절댓값과 비교

*/

int arr[3];
using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	int n;
	vector<int>v;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());

	long long res = 3000000001;

	for (int i = 0; i < n - 2; i++) {
		int left = i + 1, right = n - 1;
		while (left < right) {
			long long sum = static_cast<long long>(v[i]) + v[left] + v[right];
			if (abs(sum) < abs(res)) {
				res = sum;
				arr[0] = v[i], arr[1] = v[left], arr[2] = v[right];
			}

			if (sum > 0) {
				right--;
			}
			else if (sum < 0) {
				left++;
			}
			else {
				cout << arr[0] << ' ' << arr[1] << ' ' << arr[2];
				return 0;
			}
		}
	}

	cout << arr[0] << ' ' << arr[1] << ' ' << arr[2];
}