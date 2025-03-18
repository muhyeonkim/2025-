#include <iostream>
#include <vector>
#include <algorithm>

int dp[501];

/*
교차하지 않게 하기 위해 없애야 하는 전깃줄의 최소 개수는?
1. a를 기준으로 오름차순으로 정렬한다.
2. b를 기준으로 최장 증가 부분 수열을 찾는다.
*/

using namespace std;

int main() {
	vector<pair<int, int>>v;
	int n, res = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (v[i].second > v[j].second) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		res = max(res, dp[i]);
	}
	res++;

	cout << n - res;
}