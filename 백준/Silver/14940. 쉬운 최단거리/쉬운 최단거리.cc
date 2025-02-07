#include <iostream>
#include <queue>
using namespace std;

/*
BFS 사용
2가 시작위치
시작 위치에서 BFS사용
map, visited, dist 배열 만들어서 사용하기
dist는 초기화를 -1로 시키기
*/

bool visited[1001][1001];
int map[1001][1001];
int dist[1001][1001];
int dx[4] = {1,0,-1,0};
int dy[4] = { 0,1,0,-1 };
int n, m;

bool isOutofLine(int x, int y) {
	if (x >= 0 && x < n && y >= 0 && y < m) return true;
	else return false;
}

void BFS(int a, int b) {
	queue<pair<int, int>>q;
	q.push({ a,b });
	visited[a][b] = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (isOutofLine(nx, ny) && map[nx][ny] == 1 && !visited[nx][ny]) {
				q.push({ nx,ny });
				dist[nx][ny] = dist[x][y] + 1;
				visited[nx][ny] = 1;
			}
		}
	}
}

int main() {
	int x = 0, y = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0) dist[i][j] = 0; // 0이면 거리가 0
			else if (map[i][j] == 2) {
				dist[i][j] = 0; // 시작 위치도 0
				x = i, y = j;
			}
			else dist[i][j] = -1; // 이외에는 -1로 초기화
		}
	}
	BFS(x, y);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << dist[i][j] << ' ';
		}
		cout << "\n";
	}
}