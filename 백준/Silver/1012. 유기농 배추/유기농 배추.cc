#include <iostream>

using namespace std;

int n, m, k;
int map[100][100];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

bool isOutOfLine(int x, int y) {
	if (x >= 0 && x < n && y>=0 && y < m)return 1; // 범위 안에 있으면 1
	else return 0; // 밖에 있으면 0
}

void DFS(int x,int y) {
	map[x][y] = 0;
	for (int i = 0; i < 4; i++) {
		int nx = dx[i] + x;
		int ny = dy[i] + y;
		if (isOutOfLine(nx, ny)&& map[nx][ny] == 1) {
			DFS(nx, ny);
		}
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int cnt = 0;
		cin >> n >> m >> k;
		for (int i = 0; i < k; i++) {
			int x, y;
			cin >> x >> y;
			map[x][y] = 1;
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] == 1) {
					DFS(i, j);
					cnt++;
				}
			}
		}
		cout << cnt << "\n";
	}
}