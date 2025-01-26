#include <iostream>

using namespace std;

int main() {
	int n, cnt = 1;
	cin >> n;
	for (int i = 0; i < 225; i++) {
		for (int j = i; j < 225; j++) {
			for (int k = j; k < 225; k++) {
				for (int l = k; l < 225; l++) {
					if (i != 0)
						cnt = 4;
					else if (j != 0)
						cnt = 3;
					else if (k != 0)
						cnt = 2;
					if (i * i + j * j + k * k + l * l == n) {
						cout << cnt;
						return 0;
					}
				}
			}
		}
	}
}