#include <iostream>
#include <stack>
using namespace std;

bool solve(string s) {
	stack<int>stk;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(')
			stk.push('(');
		else { // s[i] == ')'
			if (stk.empty()) return false;
			stk.pop();
		}
	}
	if (stk.empty()) return true;
	else return false;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		if (solve(s)) cout << "YES\n";
		else cout << "NO\n";
	}
}