#include <iostream>

using namespace std;

int dp[31];

int main() {
	int d, k;
	cin >> d >> k;
	dp[1] = 1, dp[2] = 1;
	for (int i = 3; i <= d; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	for (int a = 1; a <= k; a++) {
		for (int b = 1; a + b <= k; b++) {
			if (a * dp[d - 2] + b * dp[d - 1]==k){
				cout << a << "\n" << b;
				return 0;
			}
		}
	}

}