#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int m, n, x, y, ans = -1;
		cin >> m >> n >> x >> y;
		while (x <= m * n) {
			if (x % n == y % n) {
				ans = x;
				break;
			}
			else
				x += m;
		}
		cout << ans << "\n";
	}
}