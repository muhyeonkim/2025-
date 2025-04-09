#include <iostream>

/*
f(A) : A의 모든 약수의 합
g(x) : x보다 작거나 같은 모든 y의 f(y)값을 더한 값
*/

using namespace std;

long long num[1000001];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	for (long long i = 1; i <= 1000000; i++) {
		for (long long j = i; j <= 1000000; j += i) {
			num[j] += i; // 소수의 합
		}
	}

	for (long long i = 1; i <= 1000000; i++) {
		num[i] += num[i - 1]; // 누적합
	}

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		cout << num[n] << "\n";
	}
}