#include <iostream>

using namespace std;

int map[1025][1025];
int sum[1025][1025];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int tmp = 0;
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
			tmp += map[i][j];
			sum[i][j] = tmp;
		}
	}

	for (int i = 0; i < m; i++) {
		int x1, y1, x2, y2, tmp = 0;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int j = x1; j <= x2; j++) {
			tmp += sum[j][y2] - sum[j][y1 - 1];
		}
		cout << tmp << "\n";
	}
}