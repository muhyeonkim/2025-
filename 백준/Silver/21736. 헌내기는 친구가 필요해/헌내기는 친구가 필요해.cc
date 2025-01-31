#include <iostream>

using namespace std;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
char map[601][601];
bool visited[601][601];
int n, m, x, y, cnt = 0;

bool isOutofLine(int a, int b) {
	if (a >= 0 && a < n && b >= 0 && b < m) return true;
	else return false;
}

void BFS(int a,int b) {
	visited[a][b] = 1;
	if (map[a][b] == 'P') cnt++;
	for (int i = 0; i < 4; i++) {
		int nx = dx[i] + a;
		int ny = dy[i] + b;
		if (isOutofLine(nx, ny) && visited[nx][ny] == 0&&map[nx][ny]!='X') {
			BFS(nx, ny);
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'I') {
				x = i;
				y = j;
			}
		}
	}
	BFS(x, y);
	if (cnt == 0) cout << "TT";
	else cout << cnt;

}