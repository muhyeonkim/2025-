#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[101][100001];

int main() {
	vector<pair<int, int>>bp; // 무게,가치
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int w, v;
		cin >> w >> v;
		bp.push_back({ w,v });
	}
	sort(bp.begin(), bp.end());
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			if (j < bp[i - 1].first) { // 정해진 무게보다 i번째 가방이 더 무거울 때
				dp[i][j] = dp[i - 1][j];
			}
			else { // 정해진 무게보다 i번째 가방이 더 가벼울 때
				dp[i][j] = max(bp[i - 1].second + dp[i-1][j - bp[i - 1].first], dp[i - 1][j]);
			}
		}
	}
	

	cout << dp[n][k];
}