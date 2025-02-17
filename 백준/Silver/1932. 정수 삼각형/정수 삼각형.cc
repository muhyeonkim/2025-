#include <iostream>

using namespace std;

int tri[500][500];
int dp[500][500];

int main() {
	int n, res = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> tri[i][j];
		}
	}
	dp[0][0] = tri[0][0];
	for (int i = 1; i < n; i++) {
		dp[i][0] = tri[i][0] + dp[i - 1][0];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i][j] = tri[i][j] + max(dp[i - 1][j - 1], dp[i - 1][j]);
		}
	}
	
	for (int i = 0; i < n; i++) {
		res = max(dp[n - 1][i], res);
	}
	cout << res;
}