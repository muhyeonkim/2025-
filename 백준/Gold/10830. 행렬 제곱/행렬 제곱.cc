#include <iostream>

/*
행렬 계산 어떻게 할 것인가?
aij= ai1*a1j + ai2*a2j +...
*/

using namespace std;

long long int n, b;

int map[5][5];

int res[5][5] = {
{1,0,0,0,0},
{0,1,0,0,0},
{0,0,1,0,0},
{0,0,0,1,0},
{0,0,0,0,1}
};

void matrix_multiple(int a[5][5],int b[5][5]) { // 행렬끼리 곱하는 법
	int tmp[5][5] = {};
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				tmp[i][j] += a[i][k] * b[k][j];
			}
			tmp[i][j] %= 1000;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] = tmp[i][j];
		}
	}
}

void power(long long int x) { //거듭 제곱 분할

	while (x > 0) {
		if (x % 2 == 1) { // 지수가 홀수일 때
			matrix_multiple(res, map);
		}

		matrix_multiple(map, map);

		x /= 2;
	}

}

int main() {

	cin >> n >> b;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	power(b);

	for (int i = 0; i <n; i++) {
		for (int j = 0; j < n; j++) {
			cout << res[i][j] << ' ';
		}
		cout << "\n";
	}
}