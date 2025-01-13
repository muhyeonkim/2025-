#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;
	while (1) {
		bool res = true;
		stack<char>st;
		getline(cin, s);
		if (s == ".") {
			return 0;
		}
		for (char c : s) {
			if (c == '(' || c == '[') {
				st.push(c);
			}
			else if (c == ')') {
				if (st.empty() || st.top() != '(') res = false;
				else if (st.top() == '(') st.pop();
				
			}
			else if (c == ']') {
				if (st.empty() || st.top() != '[') res = false;
				else if (st.top() == '[') st.pop();
			}
		}
		if (!st.empty()) res = false;
		
		if (res) cout << "yes\n";
		else cout << "no\n";
	}
}