#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
	int t, n;
	cin >> t;
	while (t--) {
		int result = 1;
		unordered_map<string, int>um;
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			string s1, s2;
			cin >> s1 >> s2;
			um[s2]++;
		}

		for (auto i : um) {
			if(i.second!=0)
				result *= i.second+1;
		}
		cout << result - 1 << "\n";
	}
}