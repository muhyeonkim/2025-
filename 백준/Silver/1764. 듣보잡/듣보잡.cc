#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, m;
	set<string>st;
	vector<string>v;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		st.insert(s);
	}

	for (int i = 0; i < m; i++) {
		string s;
		cin >> s;
		if (st.find(s) != st.end()) {
			v.push_back(s);
		}
	}
	sort(v.begin(), v.end());
	cout << v.size()<<"\n";
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << "\n";
	}
}
