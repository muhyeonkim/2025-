#include <iostream>

using namespace std;

int stick[2][100000];
int dp[3][100000];
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> stick[0][i];
		}
		for (int i = 0; i < n; i++) {
			cin >> stick[1][i];
		}
		dp[0][0] = stick[0][0];
		dp[1][0] = stick[1][0];
		/*dp[0][1] = stick[1][0] + stick[0][1];
		dp[1][1] = stick[0][0] + stick[1][1];
		dp[2][1] = max(dp[0][0], dp[1][0]);*/
		
		for (int i = 1; i < n; i++) {
			dp[0][i] = max(dp[1][i - 1] + stick[0][i], dp[2][i - 1] + stick[0][i]); // 위의 스티커를 고르는 경우
			dp[1][i] = max(dp[0][i - 1] + stick[1][i], dp[2][i - 1] + stick[1][i]); // 아래 스티커를 고르는 경우
			dp[2][i] = max(dp[0][i - 1], dp[1][i - 1]);//아무것도 안 고르는 경우
			//cout << dp[0][i] << ' ' << dp[1][i] << "\n";
		}
		cout << max(dp[0][n - 1], dp[1][n - 1]) << "\n";
	}
}