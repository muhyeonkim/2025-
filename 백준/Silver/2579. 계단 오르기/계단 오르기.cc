#include <iostream>
#include <vector>
using namespace std;

int dp[301];
int str[301];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> str[i];
	}
	for (int i = 1; i <= n; i++) {
		if (i == 1) {
			dp[1] = str[1];
		}
		else if (i == 2) {
			dp[2] = str[1] + str[2];
		}
		else {
			dp[i] = max(dp[i - 2], dp[i - 3] + str[i - 1]) + str[i];
		}
	}
	cout << dp[n];
}