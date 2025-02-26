#include <iostream>
#include <queue>

/*
빈 칸 중 3개를 선택한 다음(백트래킹)
2를 확산시킨 다음(탐색)
0의 개수를 센다.
*/

using namespace std;

vector<vector<int>> map(9, vector<int>(9));
vector<vector<int>> tmp(9, vector<int>(9));
int n, m, max_zone;
int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,1,-1 };

bool isOutofLine(int y, int x) {
	if (y >= 0 && y < n && x >= 0 && x < m) return true;
	else return false;
}

void BFS(int y,int x) {
	queue<pair<int, int>>q;
	q.push({ y, x });
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (isOutofLine(ny, nx) && tmp[ny][nx] == 0) {
				tmp[ny][nx] = 2;
				q.push({ ny,nx });
			}
		}
	}
}

void count() {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (tmp[i][j] == 0) {
				cnt++;
			}
		}
	}
	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << tmp[i][j] << ' ';
		}
		cout << "\n";
	}
	cout << "\n";*/
	max_zone = max(cnt, max_zone);
}

void pick(int y, int x, int cnt) {
	if (cnt == 3) {
		tmp = map;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (tmp[i][j] == 2) {
					BFS(i, j);
				}
			}
		}
		count();
		return;
	}
	for (int i = y; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0) {
				map[i][j] = 1;
				pick(i, j, cnt + 1);
				map[i][j] = 0;
			}
		}
	}
}



int main() {
    ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	pick(0, 0, 0);

	cout << max_zone;
}