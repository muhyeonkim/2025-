#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	int n, m;
	set<string>name;
	vector<string>res;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		name.insert(s);
	}

	for (int i = 0; i < m; i++) {
		string s;
		cin >> s;
		if (name.find(s) != name.end()) { //듣도 못한 사람 명단에 있을 때
			res.push_back(s);
		}
	}
	sort(res.begin(), res.end());
	cout << res.size() << "\n";
	for (auto a : res) {
		cout << a << "\n";
	}
}