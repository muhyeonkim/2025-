#include <bits/stdc++.h>

using namespace std;

int n, m;
int num[10], arr[10];
bool issued[10];
void func(int k) {
	if (k == m) {
		for (int i = 0;i < m;i++) {
			cout << num[arr[i]] << ' ';
		}
		cout << '\n';
		return;
	}
	int tmp = 0, st = 0;
	if (k != 0) st = arr[k - 1];
	for (int i = st;i < n;i++) {
		if (tmp != num[i]) {
			arr[k] = i;
			issued[i] = 1;
			tmp = num[i];
			func(k + 1);
			issued[i] = 0;
		}
	}
}
int main() {
	ios::sync_with_stdio;
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0;i < n;i++) {
		cin >> num[i];
	}
	sort(num, num + n);
	func(0);
}