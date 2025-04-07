#include <iostream>

using namespace std;

long long arr[1000];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, sum = 0;
	long long res = 0;
	arr[0] = 1;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		sum += a;
		sum = sum % m;
		arr[sum]++;
	}
	for (int i = 0; i < m; i++) {
		res += arr[i] * (arr[i] - 1) / 2;
	}
	cout << res;
}