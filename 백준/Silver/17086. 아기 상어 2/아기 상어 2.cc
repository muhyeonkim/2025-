#include <iostream>
#include <queue>
#include <cstring>
/*
한 칸에 아기 상어 최대 1마리
안잔 거리는 그 칸과 가장 가까운 아기 상어와의 거리
두 칸 사이의 거리는 한 칸에서 다른 칸으로 가기 위해 지나가야하는 칸의 수, 방향은 8방향(상하좌우+대각선)
안전 거리가 가장 큰 칸은?

1. 모든 칸에서 DFS를 한다.
2. DFS는 해당 칸과 다른 칸 사이의 거리를 잰다.
3. 아기 상어가 있는 칸과 비교해서 가장 큰 값을 선택한다.

*/

using namespace std;

bool visited[51][51];
int board[51][51];
int dist[51][51];
int dx[8] = { 1,1,1,0,0,-1,-1,-1 };
int dy[8] = { 1,0,-1,1,-1,1,0,-1 };
int n, m;
int max_dist = 0;
vector<pair<int, int>>baby_shark;

bool isOutofLine(int x, int y) {
	if (x >= 0 && y >= 0 && x < n && y < m) return true;
	else return false;
}

void DFS(int x, int y) {
	queue<pair<int, int>>q;
	q.push({ x,y });
	visited[x][y] = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (isOutofLine(nx, ny) && visited[nx][ny] == false) {
				visited[nx][ny] = true;
				q.push({ nx,ny });
				dist[nx][ny] = dist[x][y] + 1;
			}
		}
	}
	int tmp_dist = 50000;
	for (auto a : baby_shark) {
		tmp_dist = min(dist[a.first][a.second], tmp_dist);
	}
	max_dist = max(tmp_dist, max_dist);
	
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 1) baby_shark.push_back({ i,j });
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			DFS(i, j);
			memset(visited, 0, sizeof(visited));
			memset(dist, 0, sizeof(dist));
		}
	}
	cout << max_dist;
}