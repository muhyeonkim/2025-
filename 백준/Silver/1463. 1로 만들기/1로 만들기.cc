#include <iostream>
/*
1000000 (백만)
dp에서 n-1에서 1더한 값과 계산해서 구한 값중 더 작은 것을 dp에 넣는다?
dp[n] = d[n-1]+1
*/
using namespace std;

int dp[1000001];

int main() {
	int n, cnt = 0;
	cin >> n;
	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + 1;
		if (i % 3 == 0) {
			dp[i] = min(dp[i / 3]+1, dp[i]);
		}
		if (i % 2 == 0) {
			dp[i] = min(dp[i / 2] + 1, dp[i]);
		}
	}
	cout << dp[n];
}