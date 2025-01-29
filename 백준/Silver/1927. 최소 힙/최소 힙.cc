#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	priority_queue<long long,vector<long long>,greater<>>pq;
	for (int i = 0; i < n; i++) {
		long long a;
		cin >> a;
		if (a!= 0) {
			pq.push(a);
		}
		else {
			if (pq.empty()) cout << 0 << "\n";
			else {
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
	}

}