#include <iostream>

using namespace std;

int dp[12]={0,1,2,4};

int main() {
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		for (int i = 4; i <= n; i++) {
			dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
		}
		cout << dp[n] << "\n";
	}
}