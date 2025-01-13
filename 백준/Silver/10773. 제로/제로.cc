#include <iostream>
#include <stack>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, res = 0, temp = 0;
	stack<int>st;
	cin >> n;
	for (int i = 0;i < n;i++) {
		int a;
		cin >> a;
		if (a == 0) {
			st.pop();
		}
		else {
			st.push(a);
		}
	}
	temp = st.size();
	for (int i = 0;i < temp;i++) {
		res += st.top();
		st.pop();
	}
	cout << res;
}
