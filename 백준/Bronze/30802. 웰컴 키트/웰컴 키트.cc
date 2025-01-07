#include <iostream>
using namespace std;

int main() {
	int n, arr[6], t, p, sum = 0;
	cin >> n;
	for (int i = 0; i < 6; i++) {
		cin >> arr[i];
	}
	cin >> t >> p;

	for (int i = 0; i < 6; i++) {
		if (arr[i] %t==0)
			sum += arr[i] / t;
		else
			sum += arr[i] / t + 1;
	}
	cout << sum << "\n" << n / p << ' ' << n % p;
}