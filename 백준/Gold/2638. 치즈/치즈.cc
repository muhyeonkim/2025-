#include <iostream>
#include <queue>
#include <cstring>
/*
"바깥"과 "2면"이상 접촉하면 사라진다.
몇 시간 뒤에 다 사라지는가?
가장자리에서 DFS를 시작한다.
탐색하다가 치즈 발견하면 해당 위치에 1증가
탐색 종료 후 치즈가 2번 접촉했으면 해당 위치의 치즈를 제거한다.
*/

using namespace std;

int n, m;
int map[101][101];
int isOutside[101][101];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
bool visited[101][101];

bool isOutofLine(int x, int y) {
	if (x >= 0 && y >= 0 && x < n && y < m) return true;
	else return false;
}

void BFS(int x, int y) {
	queue<pair<int, int>>q;
	q.push({ x, y });
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (isOutofLine(nx, ny) && visited[nx][ny] == 0 && map[nx][ny] == 0) {
				q.push({ nx,ny });
				visited[nx][ny] = 1;
			}
			if (map[nx][ny] == 1) {
				isOutside[nx][ny]++;
			}
		}
	}
}

int main() {
	int t = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	while (1) {
		int cnt = 0;
		BFS(0,0);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (isOutside[i][j] >= 2) { // 2변 이상 공기와 접촉한 치즈 제거
					map[i][j] = 0;
					cnt++;
				}
			}
		}
		if (cnt == 0) break;
		memset(visited, 0, sizeof(visited));
		memset(isOutside, 0, sizeof(isOutside));
		t++;
		
	}
	
	cout << t;
}