#include <iostream>
#include <cstring>

using namespace std;

/*
내리막으로만 가는 경우가 몇개?
*/

int board[501][501];
int dp[501][501];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int n, m, cnt = 0;

bool isOutofLine(int x, int y) {
	if (x >= 0 && y >= 0 && x < n && y < m) return true;
	else return false;
}

int DFS(int x, int y) {
	if (x == n - 1 && y == m - 1) return 1;
	if (dp[x][y] != -1) return dp[x][y];
	dp[x][y] = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (isOutofLine(nx, ny) && board[nx][ny] < board[x][y]) {
			dp[x][y] += DFS(nx, ny);
		}
	}
	return dp[x][y];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}
	memset(dp, -1, sizeof(dp));
	cout << DFS(0, 0);
}