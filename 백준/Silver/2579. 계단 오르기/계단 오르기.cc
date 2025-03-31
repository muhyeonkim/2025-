#include <iostream>
#include <vector>

using namespace std;

int dp[301];

int main() {
	int n;
	vector<int>v;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	dp[0] = v[0], dp[1] = v[0] + v[1], dp[2] = max(v[0] + v[2], v[1] + v[2]);
	for (int i = 3; i < n; i++) {
		dp[i] = max(dp[i - 3] + v[i - 1] + v[i], dp[i - 2] + v[i]);
	}
	cout << dp[n - 1];
}