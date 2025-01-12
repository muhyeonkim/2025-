#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	vector<vector<int>>arr;
	cin >> n;
	for (int i = 0; i < n; i++) {
		vector<int>temp;
		int x, y;
		cin >> x >> y;
		temp.push_back(x);
		temp.push_back(y);
		arr.push_back(temp);
	}
	sort(arr.begin(), arr.end());

	for (vector<int> v : arr) {
		for (int a : v) {
			cout << a << ' ';
		}
		cout << "\n";
	}
}
