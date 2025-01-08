#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, c = 0, a1 = 0;
	cin >> n;
	a1 = 1;
	while (n>a1) {
		c++;
		a1 = a1 + c * 6;
	}
	cout << c+1;
}