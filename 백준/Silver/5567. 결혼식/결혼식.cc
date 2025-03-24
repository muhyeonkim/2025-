#include <iostream>
#include <vector>

/*
자신의 친구와 친구의 친구 초대
상근이 학번은 1
root의 depth가 0일 때 depth가 2까지만 초대하기
*/
using namespace std;

int board[501][501];
int friends[501];
bool visited[501][501];
int n, m, cnt;

void DFS(int x, int depth) {
	if (depth >= 2) return;
	for (int i = 1; i <= n; i++) {
		if (board[x][i] == 1 && visited[x][i] == 0) {
			friends[i] = 1;
			visited[i][x] = 1;
			DFS(i, depth + 1);
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		board[a][b] = 1;
		board[b][a] = 1;
	}
	DFS(1, 0);
	for (int i = 1; i <= n; i++) {
		if (friends[i] == 1) cnt++;
	}
	cout << cnt;
}