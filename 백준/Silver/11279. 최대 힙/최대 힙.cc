#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	priority_queue<int>pq;
	cin >> n;
	while (n--) {
		long long x;
		cin >> x;
		if (x == 0) {
			if (pq.empty()) cout << 0 << "\n";
			else {
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
		else {
			pq.push(x);
		}
	}
}