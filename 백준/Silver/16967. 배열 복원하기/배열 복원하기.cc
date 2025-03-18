#include <iostream>

/*
첫줄은 원래 값
다음 줄 부터 바껴있음

*/

using namespace std;

int res[301][301];
int board[600][600];

int main() {
	int h, w, x, y;
	cin >> h >> w >> x >> y;
	for (int i = 0; i < h + x; i++) {
		for (int j = 0; j < w + y; j++) {
			cin >> board[i][j];
		}
	}
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (i < x || j < y) res[i][j] = board[i][j];
			else res[i][j] = board[i][j] - res[i - x][j - y];
		}
	}
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cout << res[i][j] << ' ';
		}
		cout << "\n";
	}
}