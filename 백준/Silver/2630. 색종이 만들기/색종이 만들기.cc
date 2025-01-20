#include <iostream>
#include <vector>

using namespace std;

/*
1. 맨위 오른쪽 숫자를 추출한다.
2. 정사각형이 모두 그 숫자로 되있는지 확인한다.
2.1 다 그렇게 되있으면 그 숫자의 종이 개수를 1증가한다.
2.2 아니면 4등분한 다음 1로 돌아간다.


*/

vector<vector<int>>v;
int w_cnt = 0, b_cnt = 0;
void count(int x, int y, int n) {
	int std = v[x][y];
	for (int i = x; i < x + n; i++) {
		for (int j = y; j < y + n; j++) {
			if (v[i][j] != std) {
				count(x, y, n / 2);
				count(x, y + n / 2, n / 2);
				count(x + n / 2, y, n / 2);
				count(x + n / 2, y + n / 2, n / 2);
				return;
			}
		}
	}
	if (std == 0) {
		w_cnt++;
	}
	else
		b_cnt++;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		vector<int>tmp;
		for (int j = 0; j < n; j++) {
			int a;
			cin >> a;
			tmp.push_back(a);
		}
		v.push_back(tmp);
	}
	count(0, 0, n);
	cout << w_cnt << "\n" << b_cnt;
}