#include <iostream>

/*
꼭짓점에 쓰여 있는 수가 모두 같은 가장 큰 정사각형 찾기
정사각형의 크기(넓이) 출력
크기(가로,세로)가 1부터 시작 or 만들 수 있는 가장 큰 정사각형부터 시작?
왼쪽 위를 기준으로 (x,y),(x,y+l),(x+l,y),(x+l,y+l)가 같은지 확인하기

*/

using namespace std;

int board[51][51];

int main() {
	int n, m, size = 0;
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			board[i][j] = s[j] - '0';
		}
	}

	for (int k = 0; k < min(n, m); k++) { // 길이
		for (int i = 0; i + k < n; i++) {
			for (int j = 0; j + k < m; j++) {
				if (board[i][j] == board[i][j + k] &&
					board[i][j] == board[i + k][j] &&
					board[i][j] == board[i + k][j + k]) {
					size = (k + 1) * (k + 1);
				}
			}
		}
	}
	cout << size;
}