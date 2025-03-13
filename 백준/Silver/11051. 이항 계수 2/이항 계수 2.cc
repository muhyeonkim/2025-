#include <iostream>

using namespace std;

int dp[1002][1002];

int main() {
	int n, k;
	cin >> n >> k;
	dp[1][1] = 1,dp[2][1] = 2, dp[2][2] = 1;

	for (int i = 1; i <= n; i++) {
		dp[i][0] = 1;
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < n + 2; j++) {
			dp[i + 1][j + 1] = (dp[i][j] + dp[i][j + 1]) % 10007;
		}
	}

	cout << dp[n][k] << "\n";
}