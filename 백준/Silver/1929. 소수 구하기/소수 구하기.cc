#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
int main() {
	int m, n;
	cin >> m >> n;
	vector<int>v;
	for (int i = 0; i <= n; i++) {
		v.push_back(i);
	}

	for (int i = 2; i <= n; i++) {
		if (v[i] == 0) continue;
		for (int j = i + i; j <= n; j += i) {
			v[j] = 0;
		}
	}

	for (int i = m; i <= n; i++) {
		if (v[i] != 0 && v[i] >= 2) cout << v[i] << "\n";
	}

}