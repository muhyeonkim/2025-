#include <iostream>
#include <queue>

/*
목표 : (1,1) -> (n,m)으로 가는 최단 경로 구하기(시작 칸과 마지막 칸 포함), 못 가면 -1출력
벽 하나를 깰 수 있다. 깬 것도 거리에 포함
벽 깨기 없으면 BFS
벽을 뚫고 나간 경로와 안 깨고 나간 경로를 분리 해야함.

*/

using namespace std;

struct moving{
	int x, y;
	bool pierce;
};

int map[1001][1001];
int dist[1001][1001][2]; // [x][y][0] : 벽 안 부심, [x][y][1] : 벽 부심
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int n, m;


bool isOutofLine(int x, int y) {
	if (x >= 1 && x <= n && y >= 1 && y <= m) return true;
	else return false;
}

void BFS() {
	queue<moving> q;
	q.push({ 1, 1, 0 });
	dist[1][1][0] = 1;

	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		bool pierce = q.front().pierce;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (isOutofLine(nx, ny)) {
				// 벽을 만나고 부수지 않은 경우
				if (map[nx][ny] == 1 && pierce == 0 && dist[nx][ny][1] == 0) {
					dist[nx][ny][1] = dist[x][y][0] + 1;
					q.push({ nx, ny, 1 });
				}
				// 벽이 아니고 방문하지 않은 경우
				if (map[nx][ny] == 0 && dist[nx][ny][pierce] == 0) {
					dist[nx][ny][pierce] = dist[x][y][pierce] + 1;
					q.push({ nx, ny, pierce });
				}
			}
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		for (int j = 1; j <= m; j++) {
			map[i][j] = s[j - 1] - '0';
		}
	}

	BFS();
	int res1 = dist[n][m][0];
	int res2 = dist[n][m][1];

	if (res1 == 0 && res2 == 0) cout << -1;
	else if (res1 != 0 && res2 == 0) cout << res1;
	else if (res1 == 0 && res2 != 0) cout << res2;
	else cout << min(res1, res2);
	/*
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << dist[i][j] << ' ';
		}
		cout << "\n";
	}

	cout << "\n";

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << broken_dist[i][j] << ' ';
		}
		cout << "\n";
	}*/
}