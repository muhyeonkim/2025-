#include <iostream>
#include <queue>
using namespace std;
/*
DFS+ㅏ,ㅓ,ㅗ,ㅜ확인

*/
int map[501][501];
bool visited[501][501];
int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,1,-1 };
int n, m;
int res = 0;

queue<pair<int, int>>q;
bool isOutofLine(int y, int x) {
	if (y >= 0 && y < n && x >= 0 && x < m) return true;
	else return false;
}
void DFS(int y, int x, int sum, int d) {
	
	if (d == 4) {
		if (sum > res)
			res = sum;
		return;
	}

	visited[y][x] = 1;

	//cout << y << ' ' << x << ' ' << sum << "\n";
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (isOutofLine(ny, nx) && visited[ny][nx] == 0) {
			visited[ny][nx] = 1;
			DFS(ny, nx, sum + map[ny][nx], d + 1);
			visited[ny][nx] = 0;
		}
	}
	visited[y][x] = 0;
}

void other(int y, int x) {
	int sum = 0;
	if (y + 2 < n && x + 1 < m) { // ㅏ
		sum = max(sum, map[y][x] + map[y + 1][x] + map[y + 2][x] + map[y + 1][x + 1]);
	}
	if (y + 2 < n && x - 1 >= 0) { //ㅓ
		sum = max(sum, map[y][x] + map[y + 1][x] + map[y + 2][x] + map[y + 1][x - 1]);
	}
	if (y - 1 >= 0 && x + 2 < m) { //ㅗ
		sum = max(sum, map[y][x] + map[y][x + 1] + map[y][x + 2] + map[y - 1][x + 1]);
	}
	if (y + 1 < n && x + 2 < m) { //ㅜ
		sum = max(sum, map[y][x] + map[y][x + 1] + map[y][x + 2] + map[y + 1][x + 1]);
	}
	res = max(res, sum);
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			//cout << i << ' ' << j << "\n";
			DFS(i, j, map[i][j], 1);
			other(i, j);
		}
	}
	cout << res;
}