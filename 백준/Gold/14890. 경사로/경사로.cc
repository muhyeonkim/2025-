#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

int board[101][101];
int cnt, n, l;

bool check(int line[],bool visited[]) {
	for (int i = 0; i < n - 1; i++) {
		if (line[i] == line[i + 1]) continue; // 앞에 칸이랑 높이가 같으면 패스

		if (abs(line[i] - line[i + 1]) > 1) return false; // 앞에랑 높이 차이가 1보다 크면 false;

		if (line[i] > line[i + 1]) { //내려가는 경우
			int lower = line[i + 1];
			for (int j = 1; j <= l; j++) {
				if (visited[i + j] == true || line[i + j] != lower || i + j >= n) return false;
				visited[i + j] = true;
			}
		}
		else { //올라 가는 경우
			int higher = line[i];
			for (int j = 0; j < l; j++) {
				if (visited[i - j] == true || line[i - j] != higher || i - j < 0) return false;
				visited[i - j] = true;
			}
		}
	}
	return true;
}

void solve() {
	for (int i = 0; i < n; i++) {
		int row[101], col[101];
		bool visited[101] = { false };
		for (int j = 0; j < n; j++) {
			row[j] = board[i][j];
			col[j] = board[j][i];
		}

		if (check(row, visited) == true) cnt++; //가로 체크
		memset(visited, 0, sizeof(visited));
		if (check(col, visited) == true) cnt++; //세로 체크
	}
}

int main() {
	cin >> n >> l;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}
	solve();
	cout << cnt;
}