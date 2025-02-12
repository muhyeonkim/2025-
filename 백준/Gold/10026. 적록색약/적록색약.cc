#include <iostream>
#include <queue>
/*
queue를 4개 준비하기
적록색약 아닌 사람은 빨 파 초
적록색약인 사람은 파 
*/

using namespace std;
int n;
char map[100][100];
bool visited[100][100];
bool visited2[100][100];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0 ,1,-1 };

bool isOutofLine(int x, int y) {
	if (x >= 0 && x < n && y >= 0 && y < n) {
		return true;
	}
	else return false;
}

void BFS(int x, int y, char color) {
	queue<pair<int, int>>q;
	q.push({ x,y });
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (map[nx][ny] == color && isOutofLine(nx, ny) && visited[nx][ny] == 0) {
				q.push({ nx,ny });
				visited[nx][ny] = 1;
			}
		}
	}
}

void BFS2(int x, int y,char color) {
	queue<pair<int, int>>q;
	q.push({ x,y });
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (color== 'B') {
				if (map[nx][ny] == 'B' && isOutofLine(nx, ny) && visited2[nx][ny] == 0) {
					q.push({ nx,ny });
					visited2[nx][ny] = 1;
				}
			}
			else {
				if (map[nx][ny] != 'B' && isOutofLine(nx, ny) && visited2[nx][ny] == 0) {
					q.push({ nx,ny });
					visited2[nx][ny] = 1;
				}
			}
		}
	}
}

int main() {
	int cnt1 = 0, cnt2 = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j] == 0) {
				BFS(i, j, map[i][j]);
				cnt1++;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited2[i][j] == 0) {
				BFS2(i, j, map[i][j]);
				cnt2++;
			}
		}
	}

	cout << cnt1<<' '<<cnt2;
}