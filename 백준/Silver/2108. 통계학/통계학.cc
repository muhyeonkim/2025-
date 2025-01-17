#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, a[8001] = { 0 }, max = 0, index = 0, max_cnt = 0;
	double sum = 0;
	vector<int>arr;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		arr.push_back(x);
		a[x + 4000]++;
	}
	sort(arr.begin(), arr.end());
	for (int i = 0; i < n; i++) {
		sum += arr[i];
	}
	for (int i = 0; i < 8001; i++) {
		if (max < a[i]) {
			max = a[i];
			index = i;
		}
	}
	for (int i = 0; i < 8001; i++) {
		if (max == a[i]) {
			max_cnt++;
		}
		if (max_cnt == 2) {
			index = i;
			break;
		}
	}
	if (round(sum / n) == -0) {
		cout << 0 << "\n" << arr[n / 2] << "\n" << index - 4000 << "\n" << arr[n - 1] - arr[0];
	}
	else {
		cout << round(sum / n) << "\n" << arr[n / 2] << "\n" << index-4000 << "\n" << arr[n - 1] - arr[0];
	}
	
}
