#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	queue<int>q;
	cin >> n;
	
	for (int i = 0;i < n;i++) {
		string s;
		cin >> s;
		if (s == "push") {
			int x;
			cin >> x;
			q.push(x);
		}
		else if (s == "pop") {
			if (!q.empty()) {
				cout << q.front() << "\n";
				q.pop();
			}
			else cout << "-1\n";
		}
		else if (s == "size") {
			cout << q.size() << "\n";
		}
		else if (s == "empty") {
			cout << q.empty() << "\n";
		}
		else if (s == "front") {
			if (!q.empty()) {
				cout << q.front() << "\n";
			}
			else cout << "-1\n";
		}
		else if (s == "back") {
			if (!q.empty()) {
				cout << q.back() << "\n";
			}
			else cout << "-1\n";
		}
	}
}


