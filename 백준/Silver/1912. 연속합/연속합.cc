#include <iostream>

/*
dp의 이전 인덱스를 더하는 것과 더하지 않는 것 중 더 큰 경우를 고른다.
100000000
*/

using namespace std;

int dp[100001];
int arr[100001];

int main(){
	int n, res = -10000;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	dp[0] = arr[0];
	for (int i = 1; i < n; i++) {
		dp[i] = max(arr[i], arr[i] + dp[i - 1]);
	}
	for (int i = 0; i < n; i++) {
		res = max(res, dp[i]);
	}
	cout << res;
	
}