#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(int a, int b) {
	return a > b;
}

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
		temp.push_back(y);
		temp.push_back(x);
		arr.push_back(temp);
	}
	sort(arr.begin(), arr.end());

	for (int i = 0; i < arr.size(); i++) {
		for (int j = 1; j >= 0; j--) {
			cout << arr[i][j] << ' ';
		}
		cout << "\n";
	}
}
