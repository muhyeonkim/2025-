#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int sum = i, tmp = i;
		while (tmp != 0) {
			sum += tmp % 10;
			tmp = tmp / 10;
		}
		if (sum == n) {
			cout << i;
			return 0;
		}
	}
	cout << 0;
}