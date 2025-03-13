#include <iostream>

/*
타일에는 00 또는 1가 쓰여있다.
타일이 n개 있을 때, 만들 수 있는 수는 몇개인가?

*/

using namespace std;

int dp[1000001];

int main() {
	int n;
	cin >> n;
	dp[0] = 0, dp[1] = 1, dp[2] = 2;
	for (int i = 3; i <= n; i++) {
		dp[i] = (dp[i - 2] + dp[i - 1]) % 15746;
	}
	cout << dp[n];
}