#include <iostream>
#include <set>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int m;
	set<int>s1;
	cin >> m;
	while (m--) {
		string s;
		cin >> s;
		if (s == "add") {
			int x;
			cin >> x;
			s1.insert(x);
		}
		else if (s == "remove") {
			int x;
			cin >> x;
			s1.erase(x);
		}
		else if (s == "check") {
			int x;
			cin >> x;
			if (s1.find(x) != s1.end()) cout << 1 << "\n";
			else cout << 0 << "\n";
		}
		else if (s == "toggle") {
			int x;
			cin >> x;
			if (s1.find(x) != s1.end()) s1.erase(x);
			else s1.insert(x);
		}
		else if (s == "all") {
			for (int i = 1; i <= 20; i++) {
				s1.insert(i);
			}
		}
		else if (s == "empty") {
			set<int>tmp;
			s1 = tmp;
		}
	}
}