#include <iostream>
#include <queue>
using namespace std;

int count(queue<pair<int, int>>q, priority_queue<int>pq,int m) {
	int cnt = 0;
	while (1) {
		if (pq.top() == q.front().second) {
			cnt++;
			if (q.front().first == m) return cnt;
			pq.pop();
			q.pop();
		}
		else {
			q.push(q.front());
			q.pop();
		}
	}
}

int main() {
	int t, cnt = 0;
	cin >> t;
	while (t--) {
		int n, m;
		queue<pair<int, int>>q;
		priority_queue<int>pq;

		cin >> n >> m;

		for (int i = 0; i < n; i++) {
			int pri;
			cin >> pri;
			q.push({ i,pri });
			pq.push(pri);
		}

		cout << count(q, pq, m) << "\n";
	}
}