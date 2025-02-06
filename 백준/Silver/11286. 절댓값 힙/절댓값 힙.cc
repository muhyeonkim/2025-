#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

struct compare1 {
	bool operator()(long long int a,long long int b) {
		if (abs(a) == abs(b))
			return a > b;
		return abs(a) > abs(b);
	}
};

int main() {
	int n;
	priority_queue<long long int, vector<long long int>, compare1>pq;
	cin >> n;
	while (n--) {
		long long int x;
		cin >> x;
		if (x == 0) {
			if (pq.empty()) {
				cout << 0 << "\n";
			}
			else {
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
		else
			pq.push(x);
	}
}