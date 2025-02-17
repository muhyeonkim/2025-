#include <iostream>

using namespace std;

int stick[2][100001];
int dp[3][100001];
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> stick[0][i];
		}
		for (int i = 1; i <= n; i++) {
			cin >> stick[1][i];
		}
		dp[0][1] = stick[0][1];
		dp[1][1] = stick[1][1];
		/*dp[0][1] = stick[1][0] + stick[0][1];
		dp[1][1] = stick[0][0] + stick[1][1];
		dp[2][1] = max(dp[0][0], dp[1][0]);*/
		
		for (int i = 2; i <= n; i++) {
			dp[0][i] = max(dp[1][i - 1], dp[1][i - 2])+ stick[0][i]; // 위의 스티커를 고르는 경우
			dp[1][i] = max(dp[0][i - 1], dp[0][i - 2])+ stick[1][i]; // 아래 스티커를 고르는 경우
		}
		cout << max(dp[0][n], dp[1][n]) << "\n";
	}
}