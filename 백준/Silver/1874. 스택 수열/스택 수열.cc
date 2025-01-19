#include <iostream>
#include <stack>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;
	int n, cnt = 1;
	stack<int>st;
	cin >> n;
	while (n--) {
		int a;
		cin >> a;
		while (a >=cnt) {
			st.push(cnt);
			cnt++;
			s += "+\n";
		}
		if (st.top() != a) {
			cout << "NO";
			return 0;
		}
		st.pop();
		s += "-\n";
	}
	cout << s;
}