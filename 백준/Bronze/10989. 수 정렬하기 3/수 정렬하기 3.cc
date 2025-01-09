#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, a[10001] = { 0 };
	vector<int>arr;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		a[x]++;
	}
	for (int i = 0; i < 10001; i++) {
		if (a[i] != 0) {
			for (int j = 0; j < a[i]; j++) {
				cout << i  << "\n";
			}
		}
	}
}
