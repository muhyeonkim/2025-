#include <iostream>
#include <cstring>
/*
한 덩어리의 빙산이 두 덩어리 이상이 될 때 까지 걸리는 시간은?
다 녹을 때까지 두 덩어리로 분리되지 않으면 0을 출력
빙산은 동서남북 네 방향에 붙어있는 0이 저장된 칸의 개수만큼 줄어든다.
덩어리 판별 방법
0이 아닌 칸에서 탐색을 시작해서 모든 0이 아닌 칸을 방문할 수 있으면 한 덩어리이다. 여기서 BFS사용
얼음 녹이기
감소 방법은 0이 아닌 칸에서 상하좌우에 0 개수 확인해서 빼기, 한 번에 빼야함

*/

using namespace std;

int board[301][301]; //빙하
int zero_cnt[301][301]; // 주변에 0이 몇개인지 확인
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
bool visited[301][301];

int n, m;

bool isOutofLine(int x, int y) {
	if (x >= 0 && y >= 0 && x < n && y < m) return true;
	else return false;
}

void melting() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < 4; k++) { // 주변에 0 개수 세기
				int nx = i + dx[k];
				int ny = j + dy[k];
				if (isOutofLine(nx, ny) && board[nx][ny] == 0) {
					zero_cnt[i][j]++;
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			board[i][j] -= zero_cnt[i][j]; // 주변 0 만큼 빙하 녹음
			if (board[i][j] < 0) board[i][j] = 0;//높이는 0이하로 떨어질 수 없음
		}
	}
	memset(zero_cnt, 0, sizeof(zero_cnt));//zero_cnt 초기화
}

void DFS(int x, int y) {
	visited[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (isOutofLine(nx, ny) && board[nx][ny] != 0 && visited[nx][ny] == false) {
			DFS(nx, ny);
		}
	}
}

void check() {

}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	int year = 0;

	while (true) {
		int cnt = 0;
		year++;
		memset(visited, 0, sizeof(visited));
		melting();// 녹이기, 한번에 안녹이면 다른 빙하 영향 받을 수 있음
		/*cout << "\n";
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << board[i][j] << ' ';
			}
			cout << "\n";
		}*/

		int x = 0, y = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (board[i][j] != 0 && visited[i][j] == false) {
					DFS(i, j);
					cnt++;
				}
			}
		}
		//cout << x << ' ' << y << "\n";
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (board[i][j] != 0 && visited[i][j] == false) {
					cout << year;
					return 0;
				}
			}
		}

		if (cnt == 0) {
			cout << 0;
			return 0;
		}
		else if (cnt >= 2) {
			cout << year;
			return 0;
		}
	}
}