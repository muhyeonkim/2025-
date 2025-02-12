#include <iostream>
#include <queue>

using namespace std;

struct tomato {
	int z, y, x;
};

queue<tomato>q;

int m, n, h;
int map[100][100][100];
bool vistied[100][100][100];
int dz[6] = { 1,-1,0,0,0,0 };
int dy[6] = { 0,0,1,-1,0, 0 };
int dx[6] = { 0,0,0,0,1,-1 };

bool isOutofLine(int z, int y, int x) {
	if (z >= 0 && z < h && y >= 0 && y < n && x >= 0 && x < m) {
		return true;
	}
	else
		return false;
}

void BFS() {
	while (!q.empty()) {
		int z = q.front().z;
		int y = q.front().y;
		int x = q.front().x;
		q.pop();
		for (int i = 0; i < 6; i++) {
			int nz = z + dz[i];
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (isOutofLine(nz, ny, nx) && vistied[nz][ny][nx] == 0 && map[nz][ny][nx] == 0) {
				map[nz][ny][nx] += map[z][y][x] + 1;
				vistied[nz][ny][nx] = 1;
				q.push({ nz,ny,nx });
			}
		}
	}
}

int main() {
	int max_t = 0;
	cin >> m >> n >> h;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				cin >> map[i][j][k];
				if (map[i][j][k] == 1) {
					q.push({ i,j,k });
					vistied[i][j][k] = 1;
				}
			}
		}
	}
	BFS();
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				max_t = max(max_t, map[i][j][k]);
				if (map[i][j][k] == 0) {
					cout << -1;
					return 0;
				}
			}
		}
	}
	cout << max_t - 1;
}