#include <iostream>
#include <stack>

using namespace std;

int precedence(char op) {
	if (op == '(') return 0;
	if (op == '+' || op == '-') return 1;
	if (op == '*' || op == '/') return 2;
}

int main() {
	stack<char>stk;
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if (isalpha(s[i])) cout << s[i];
		else {
			if (s[i] == '(') stk.push(s[i]);

			else if (s[i] == ')') {
				while (!stk.empty() && stk.top() != '(') {
					cout << stk.top();
					stk.pop();
				}
				stk.pop();
			}

			else {
				while (!stk.empty() &&precedence(s[i])<=precedence(stk.top())) {
					cout << stk.top();
					stk.pop();
				}
				stk.push(s[i]);
			}

		}
	}
	while (!stk.empty()){
		cout << stk.top();
		stk.pop();
	}
}