#include <iostream>
/*
10000000000
*/
using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
	long long int n, k, res = 0;
	cin >> n >> k;
	long long int left = 1, right = n * n;
	while (left <= right) {
		long long int mid = (left + right) / 2;
		long long int cnt = 0;
		for (int i = 1; i <= n; i++) {
			cnt += min(mid / i, n);
		}
		if (cnt >= k) { // mid보다 큰 숫자가 더 많을 경우
			right = mid - 1;
			res = mid;
		}
		else if (cnt < k) {
			left = mid + 1;
		}
	}
	cout << res;
}