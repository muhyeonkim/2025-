#include <iostream>

/*
분할 정복을 이용한 거듭 제곱
행렬 이용

*/

using namespace std;

long long int n;

long long int map[2][2] = { {1,1},{1,0} };

long long int res[2][2] = { {1,0},{0,1} };

void matrix_multiply(long long int a[2][2], long long int b[2][2]) {
	long long int tmp[2][2] = {};
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++) {
				tmp[i][j] += a[i][k] * b[k][j];
			}
			tmp[i][j] %= 1000000007;
		}
	}

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			a[i][j] = tmp[i][j];
		}
	}
	
}

void power(long long int x) {
	while (x > 0) {
		if (x % 2 == 1) {
			matrix_multiply(res, map);
		}
		matrix_multiply(map, map);
		x /= 2;
	}
	
	cout << res[0][0];
}

int main() {
	cin >> n;
	if (n == 0) cout << 0;
	else
		power(n - 1);
}