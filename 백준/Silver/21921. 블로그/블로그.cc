#include <iostream>

using namespace std;

int arr[250001];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n, x, cnt = 0, max_visit = 0;
	cin >> n >> x;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		arr[i] += arr[i - 1];
	}
	for (int i = x; i <= n; i++) {
		if (arr[i] - arr[i - x] > max_visit) {
			max_visit = arr[i] - arr[i - x];
			cnt = 1;
		}
		else if (arr[i] - arr[i - x] == max_visit) {
			cnt++;
		}
	}
	if (max_visit == 0) {
		cout << "SAD";
	}
	else {
		cout << max_visit << "\n" << cnt;
	}
}