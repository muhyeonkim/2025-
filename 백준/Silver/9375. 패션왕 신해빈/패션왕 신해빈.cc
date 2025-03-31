#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, res = 1;
		unordered_map<string, int>um;
		cin >> n;
		for (int i = 0; i < n; i++) {
			string name, type;
			cin >> name >> type;
			um[type]++;
		}
		for (auto a : um) {
			res *= a.second + 1;
		}
		cout << res - 1 << "\n";
	}
}