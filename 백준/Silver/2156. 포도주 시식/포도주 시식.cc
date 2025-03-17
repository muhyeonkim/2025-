#include <iostream>

/*
최대 마실 수 있는 포도주의 양은?
포도주를 마실 때는 연속된 3잔은 마실 수 없다.
dp에서 나를 고르지 않는 경우도 넣어야 한다.

*/

using namespace std;

int wine[10001];
int dp[10001];

int main() {
	int n, max_wine = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> wine[i];
	}
	dp[1] = wine[1], dp[2] = dp[1] + wine[2], dp[3] = max(wine[1] + wine[2], max(wine[1] + wine[3], wine[2] + wine[3]));
	for (int i = 4; i <= n; i++) {
		dp[i] = max(dp[i - 2] + wine[i], wine[i] + wine[i - 1] + dp[i - 3]);
		dp[i] = max(dp[i], wine[i - 2] + wine[i - 1] + dp[i - 4]);
	}
	for (int i = 0; i <= n; i++) {
		max_wine = max(dp[i], max_wine);
	}
	cout << max_wine;
	/*for (int i = 0; i <= n; i++) {
		cout << dp[i] << ' ';
	}*/
}