#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, m;
	vector<int>a, b;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		a.push_back(x);
	}
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		b.push_back(x);
	}
	for (auto c : b) {
		a.push_back(c);
	}
	sort(a.begin(), a.end());
	for (auto c : a) {
		cout << c << ' ';
	}
}