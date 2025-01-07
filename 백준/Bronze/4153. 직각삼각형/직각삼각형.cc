#include <iostream>
#include <queue>
using namespace std;

int main() {
	int a, b, c;
	while (cin >> a >> b >> c) {
		if (a == 0 && b == 0 && c == 0) {
			break;
		}

		priority_queue <int> q;
		q.push(a);
		q.push(b);
		q.push(c);
		a = q.top() * q.top();
		q.pop();
		b = q.top() * q.top();
		q.pop();
		c = q.top() * q.top();
		q.pop();
		if (a==b+c)
			cout << "right\n";
		else
			cout << "wrong\n";
	}
	
}