#include <iostream>
#include <cmath>
/*
*/

using namespace std;

long long int prime(long long int n) {
	if (n == 0 || n == 1) return 2;
	while (1) {
		bool isPrime = true;
		for (int i = 2; i <= sqrt(n); i++) {
			if (n % i == 0) {
				isPrime = false;
				n++;
				break;
			}
		}
		if (isPrime == true) break;
	}
	return n;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		long long int x;
		cin >> x;
		cout << prime(x)<<"\n";
	}
}