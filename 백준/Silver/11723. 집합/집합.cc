#include <iostream>
#include <set>

using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	int m;
	set<int>st;

	cin >> m;
	while (m--) {
		string s;
		cin >> s;
		if (s == "add") {
			int x;
			cin >> x;
			st.insert(x);
		}
		else if (s == "remove") {
			int x;
			cin >> x;
			st.erase(x);
		}
		else if (s == "check") {
			int x;
			cin >> x;
			if (st.find(x) == st.end()) { // 없다.
				cout << 0 << "\n";
			}
			else cout << 1 << "\n"; // 있다
		}
		else if (s == "toggle") {
			int x;
			cin >> x;
			if (st.find(x) == st.end()) { // 없다
				st.insert(x);
			}
			else st.erase(x); // 있다
		}
		else if (s == "all") {
			for (int i = 1; i <= 20; i++) {
				st.insert(i);
			}
		}
		else if (s == "empty") {
			for (int i = 1; i <= 20; i++) {
				st.erase(i);
			}
		}
	}
}