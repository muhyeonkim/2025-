#include <iostream>

using namespace std;

bool map[101][101];
int n;

void FlWa() {
	for (int i = 0; i < n; i++) { // 경유
		for (int j = 0; j < n; j++) { // 시작
			for (int k = 0; k < n; k++) { // 도착
				if (map[j][i] == 1 && map[i][k] == 1) {
					map[j][k] = 1;
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << map[i][j] << ' ';
		}
		cout << "\n";
	}
}

int main() {

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	FlWa();
}