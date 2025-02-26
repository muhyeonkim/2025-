#include <iostream>
#include <vector>
#include <cstring>
/*
1. 플루이드-워셜로 자기 지역에서 다른 지역까지 거리 구하기
2. 나의 수색범위 안에서 아이템을 최대로 구할 수 있도록 하는 지역 구하기

*/

using namespace std;

int item[101];

int graph[101][101];
int n, m, r, max_item;

void floyd_washal() {
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == j) graph[i][j] = 0;
				else graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
			}
		}
	}
}

void backtracking(int index) {
	int total = 0;
	for (int i = 1; i <= n; i++) {
		if (graph[index][i] <= m) {
			total += item[i];
		}
	}
	max_item = max(total, max_item);
}

int main() {
	memset(graph, 10000, sizeof(graph));
	cin >> n >> m >> r;
	for (int i = 1; i <= n; i++) {
		int t;
		cin >> t;
		item[i] = t;
	}
	for (int i = 0; i < r; i++) {
		int a, b, l;
		cin >> a >> b >> l;
		graph[a][b] = l;
		graph[b][a] = l;
	}
	floyd_washal();

	for (int i = 1; i <= n; i++) {
		backtracking(i);
	}
	cout << max_item;
}