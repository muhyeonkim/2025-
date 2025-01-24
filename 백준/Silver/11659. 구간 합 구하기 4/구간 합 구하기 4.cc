#include <iostream>
#include <vector>

using namespace std;

/*
입력 들어올 때 i-1에서 입력을 더해서 넣는다.
*/

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	vector<int>v;
	v.push_back(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v.push_back(a + v[i]);
	}

	for (int i = 0; i < m; i++) {
		int j, k;
		cin >> j >> k;
		cout << v[k] - v[j - 1] << "\n";
	}
}