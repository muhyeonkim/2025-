#include <iostream>

using namespace std;

int dp[12];
int main() {
	int n, min_score = 0, max_score = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int first, second, third;
		cin >> first >> second >> third;
		dp[0] = first + max(dp[3], dp[4]);
		dp[1] = second + max(dp[3], max(dp[4], dp[5]));
		dp[2] = third + max(dp[4], dp[5]);
		
		dp[3] = dp[0];
		dp[4] = dp[1];
		dp[5] = dp[2];

		dp[6] = first + min(dp[9], dp[10]);
		dp[7] = second + min(dp[9], min(dp[10], dp[11]));
		dp[8] = third + min(dp[10], dp[11]);

		dp[9] = dp[6];
		dp[10] = dp[7];
		dp[11] = dp[8];
	}
	cout << max(dp[3], max(dp[4], dp[5])) << ' ' << min(dp[9], min(dp[10], dp[11]));
}