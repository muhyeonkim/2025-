#include <iostream>
#include <queue>
/*
최소 값끼리 계속 곱하기
long long int
*/

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		long long int sum = 1;
		priority_queue<long long int, vector<long long int>, greater<>>pq;
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			long long int x;
			cin >> x;
			pq.push(x);
		}
		if (n == 1) { 
			cout << 1 << "\n"; 
			continue;
		}
	
		while (pq.size() > 1) {
			long long int first = pq.top();
			pq.pop();
			long long int second = pq.top();
			pq.pop();
			long long energy= (first * second) % 1000000007;
			sum = (sum*energy) %1000000007;
			//cout << first * second << ' ';
			pq.push(first * second);
		}
		cout << sum<<"\n";
	}
}