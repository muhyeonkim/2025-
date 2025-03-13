#include <iostream>

/*
n개의 파티장이 있다.
문제점 1. A->B파티장으로 갈 수 있도록 일방통행 도로를 만들었으나 경유해서 더 빨리 갈 수 있다.
문제점 2. C시간 뒤, B 파티장에서 새로운 파티가 열리는데 A->B까지 시간 맞춰갈 수 있는지 쉽게 알 수 없다.
도착할 수 있으면 Enjoy other party, 아니면 Stay here
플로이드-워셜 이용, 
*/

using namespace std;

int n, m;
int map[501][501];

void floyd_washal() {
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
			}
		}
	}
}

int main() {
	cin >> n >> m; 
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}

	floyd_washal();

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (map[a][b] <= c) {
			cout << "Enjoy other party\n";
		}
		else {
			cout << "Stay here\n";
		}
	}
}