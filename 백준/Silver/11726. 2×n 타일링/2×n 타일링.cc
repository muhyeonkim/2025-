#include <iostream>

using namespace std;

long long int dp[10001];

int main() {
	int n;
	cin >> n;
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= n; i++) {
		dp[i] = (dp[i - 2] + dp[i - 1])%10007;
	}
	cout << dp[n] % 10007;
}