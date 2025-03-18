#include <iostream>
#include <vector>
/*
x가 부모 y가 자식
*/

using namespace std;

int board[101][101];
bool visited[101][101];
bool isFamiliy = false;

int n, a, b, m;

void dfs(int x, int cnt) {
	for (int i = 1; i <= n; i++) {
		if (board[x][i] == 1 && visited[x][i] == 0) {
			if (i == b) { // 계산해야하는 사람의 번호를 찾았을 때
				cout << cnt;
				isFamiliy = true;
			}
			visited[i][x] = 1;
			dfs(i, cnt + 1);
		}
	}
}

int main() {
	cin >> n >> a >> b >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		board[x][y] = 1;
		board[y][x] = 1;
	}
	dfs(a, 1);
	if (isFamiliy == false) cout << -1;
}