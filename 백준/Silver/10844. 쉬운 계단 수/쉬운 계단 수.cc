#include <iostream>

using namespace std;

long long int dp[100][11]; //i길이의 마지막 숫자가 j인 계단 수의 개수

int main() {
	long long int n, sum = 0;
	cin >> n;
	for (int i = 1; i <= 9; i++) {
		dp[1][i] = 1;
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			if (j == 0) dp[i][j] = dp[i - 1][j + 1] % 1000000000;
			else dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1])%1000000000;
		}
	}
	for (int i = 0; i <= 9; i++) {
		sum += dp[n][i];
	}
	cout << sum % 1000000000;

	
}