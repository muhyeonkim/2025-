#include <iostream>
#include <queue>
using namespace std;

int main() {
	double n, sum = 0;
	priority_queue<double>q;
	cin >> n;
	for (int i = 0; i < n; i++) {
		double a;
		cin >> a;
		q.push(a);
	}
	int max = q.top();
	for (int i = 0; i < n; i++) {
		sum += (q.top() / max) * 100;
		q.pop();
	}
	cout << sum / n;
}