#include <iostream>
#include <vector>

using namespace std;
/*
k개의 랜선으로 n개의 랜선을 만든다
단, n개의 랜선은 모두 길이가 같고 최대한 길게 만들어야 한다.
left<=right
*/
int k, n;
vector<long long>v;

long long parm(long long left, long long right) {
	long long result = 0;
	while (left <= right) {
		int cnt = 0;

		long long mid = (left + right) / 2;
		for (int i = 0; i < k; i++) {
			cnt += v[i] / mid;
		}
		if (cnt >= n) {
			result = mid;
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	return result;
}

int main() {
	long long maxlen = 0;
	cin >> k >> n;
	for (int i = 0; i < k; i++) {
		long long a;
		cin >> a;
		v.push_back(a);
		maxlen = max(a, maxlen);
	}

	cout << parm(1, maxlen);
}