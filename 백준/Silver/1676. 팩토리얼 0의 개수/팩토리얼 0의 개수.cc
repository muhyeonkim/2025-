#include <iostream>

using namespace std;

int main() {
	int n, cnt = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int tmp = i;
		while (tmp % 5 == 0) {
			cnt++;
			tmp /= 5;
		}
	}
	cout << cnt;
}