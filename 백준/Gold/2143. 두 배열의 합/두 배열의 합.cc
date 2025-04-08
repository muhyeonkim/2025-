#include <iostream>
#include <unordered_map>

using namespace std;

int arr1[2001];
int arr2[2001];

int main() {
	unordered_map<int, int>unmap;// key value
	int t, n, m;
	long long cnt = 0;
	cin >> t >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr1[i];
		arr1[i] += arr1[i - 1];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < i; j++) {
			unmap[arr1[i] - arr1[j]]++;
		}
	}
	cin >> m;

	for (int i = 1; i <= m; i++) {
		cin >> arr2[i];
		arr2[i] += arr2[i - 1];
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 0; j < i; j++) {
			cnt += unmap[t - (arr2[i] - arr2[j])];
		}
	}
	cout << cnt;
}