#include <iostream>

using namespace std;

int prime[1000001];

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	for (int i = 2; i <= m; i++) {
		prime[i] = i;
	}

	for (int i = 2; i <= m; i++) {
		if (prime[i] == 0) continue;
		for (int j = i * 2; j <= m; j += i) {
			prime[j] = 0;
		}
	}
	for (int i = n; i <= m; i++) {
		if (prime[i] != 0) cout << prime[i] << "\n";
	}
}