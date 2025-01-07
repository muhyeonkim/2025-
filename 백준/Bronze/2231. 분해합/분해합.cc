#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int sum=i, part=i;
		while (part) {
			sum += part % 10;
			part /= 10;
		}
		if (sum == n) {
			cout << i;
			return 0;
		}
	}
	cout << "0";
}