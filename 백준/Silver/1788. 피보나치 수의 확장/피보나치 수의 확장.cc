#include <iostream>
#include <cmath>
using namespace std;

long long int dp[2000001];

int main() {
	int n;
	cin >> n;
	dp[1000000] = 0, dp[1000001] = 1;
	if (n >= 0) { // 일반 피보나치
		for (int i = 2; i <= n; i++) {
			dp[i + 1000000] = (dp[i + 999999] + dp[i + 999998]) % 1000000000;
		}
	}

	else {
		for (int i = 1; i <= n * -1; i++) {
			dp[1000000 - i] = (dp[1000002 - i] - dp[1000001 - i]) % 1000000000;
		}
	}
	if (dp[1000000 + n] == 0) cout << 0 << "\n";
	else if (dp[1000000 + n] > 0) cout << 1 << "\n";
	else if (dp[1000000 + n] < 0) cout << -1 << "\n";
	
	if (dp[1000000 + n] >= 0) cout << dp[1000000 + n];
	else cout << dp[1000000 + n] * -1;
}