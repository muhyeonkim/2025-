#include <iostream>
#include <vector>

/*
한 라인에서 한 군데 두고 거기서 공격할 수 있는 칸을
true로 만들고 다음 칸으로 넘어 가기
*/

using namespace std;
int n;
int cnt = 0;
vector<int> col;           // 각 행의 퀸이 놓인 열 위치
vector<bool> used_col;     // 각 열에 퀸이 놓였는지 여부
vector<bool> diag;     // '/' 대각선
vector<bool> anti_diag;    // '\' 대각선

void backtracking(int row) {
	if (row == n) {
		cnt++;
		return;
	}
	for (int i = 0; i < n; i++) {
		if (used_col[i] == true || diag[row - i + n - 1] == true || anti_diag[row + i] == true) {
			continue;
		}
		col[row] = i;
		used_col[i] = true;
		diag[row - i + n - 1] = true;
		anti_diag[row + i] = true;

		backtracking(row + 1);

		used_col[i] = false;
		diag[row - i + n - 1] = false;
		anti_diag[row + i] = false;
	}
}

int main() {
	cin >> n;
	col.resize(n);
	used_col.resize(n, false);
	diag.resize(2 * n - 1, false);
	anti_diag.resize(2 * n - 1, false);
	backtracking(0);
	cout << cnt;
}