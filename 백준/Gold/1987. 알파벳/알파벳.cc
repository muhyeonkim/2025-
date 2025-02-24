#include <iostream>
#include <queue>
/*
DFS로 탐색
탐색 끝나고 나면 visit(alpha)를 되돌려 놓기
*/
using namespace std;

char map[21][21];
bool visited[21][21];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

bool alpha[27];
int r, c, max_dist;

bool isOutofLine(int y, int x) {
	if (y >= 0 && y < r && x >= 0 && x < c) return true;
	else return false;
}

void DFS(int y,int x,int cnt) {
	visited[y][x] = true;
	alpha[map[y][x] - 'A'] = true;
	if (max_dist < cnt) {
		max_dist = cnt;
	}
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (isOutofLine(ny, nx) && visited[ny][nx] == false && alpha[map[ny][nx] - 'A'] == false) {
			DFS(ny, nx, cnt + 1);
			visited[ny][nx] = false;
			alpha[map[ny][nx] - 'A'] = false;
		}
	}
}


int main() {
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> map[i][j];
		}
	}
	DFS(0, 0, 1);
	cout << max_dist;
}