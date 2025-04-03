#include <iostream>
#include <queue>
#include <cstring>

/*
bfs
지역의 높이 정보 파악
잠기지 않는 영역이 최대 몇 개?
일정 높이 이하의 모든 지점은 물에 잠긴다고 가정
물에 잠기지 않은 안전한 '영역'의 최대 개수?

*/

using namespace std;

bool visited[101][101];
int board[101][101];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0 ,1,-1 };
int max_area = 1;
int n;

bool isOutofLine(int x, int y) {
	if (x >= 0 && y >= 0 && x < n && y < n) return true;
	else return false;
}

void BFS(int x, int y,int depth) {
	queue<pair<int, int>>q;
	q.push({ x,y });
	visited[x][y] = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (isOutofLine(nx, ny) && visited[nx][ny] == 0 && board[nx][ny] > depth) {
				visited[nx][ny] = 1;
				q.push({ nx,ny });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int min_depth = 100, max_depth = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			max_depth = max(max_depth, board[i][j]);
			min_depth = min(min_depth, board[i][j]);
		}
	}
	for (int k = min_depth; k <= max_depth; k++) { //min_depth부터 max_depth까지 
		int tmp_area = 0;
		for (int i = 0; i < n; i++) { //depth가 작은 애들은 미리 침수
			for (int j = 0; j < n; j++) {
				if (k >= board[i][j]) {
					visited[i][j] = 1;
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (visited[i][j] == 0) {
					BFS(i, j, k);
					tmp_area++;
				}
			}
		}
		max_area = max(max_area, tmp_area);
//		cout << tmp_area << ' ' << k << "\n";
		memset(visited, 0, sizeof(visited));
	}
	cout << max_area;
}