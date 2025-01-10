#include <iostream>

using namespace std;

int main() {
	int n, k, sum = 1;
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		sum *= n;
		n--;
	}
	for (int i = 1; i <= k; i++) {
		sum /= i;
	}
	cout << sum;
}