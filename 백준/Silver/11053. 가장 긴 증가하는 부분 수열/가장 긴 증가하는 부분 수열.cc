#include <iostream>
#include <vector>

using namespace std;

/*
지금 순회하는 과정 중에서 가장 큰 원소보다 더 큰 원소를 만났을 때
그 원소를 포함 하느냐 안하느냐

*/

int dp[1000];

int main() {
	int n, res = 0;
	vector<int>v;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (v[j]<v[i])
				dp[i] = max(dp[i], dp[j] + 1);
		}
	}
	for (int i = 0; i < n; i++) {
		res = max(res, dp[i]);
	}
	cout << res + 1;
	
}