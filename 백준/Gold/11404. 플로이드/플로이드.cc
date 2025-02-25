#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int map[101][101];
vector<pair<int,int>>v[101];

int n, m;

void floyd_washal() {
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				map[i][j] = min(map[i][k] + map[k][j], map[i][j]);
			}
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			map[i][j] = 1000000000;
		}
	}

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		map[a][b] = min(map[a][b], c);
	}
	
	floyd_washal();

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (map[i][j] >= 1000000000 || i == j) {
				cout << 0 << ' ';
			}
			else
				cout << map[i][j] << ' ';
		}
		cout << "\n";
	}

}