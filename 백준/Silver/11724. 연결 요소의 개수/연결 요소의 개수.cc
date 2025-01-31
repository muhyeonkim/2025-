#include <iostream>

using namespace std;
int n, m;
int map[1001][1001];
bool visited[1001];

void DFS(int x) {
	visited[x] = 1;
	for (int i = 1; i <= n; i++) {
		if (map[x][i] == 1 && visited[i] == 0) {
			DFS(i);
		}
	}
}

int main() {
	int cnt = 0;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		map[u][v] = 1;
		map[v][u] = 1;
	}

	for (int i = 1; i <= n; i++) {
		if (visited[i] == 0) {
			DFS(i);
			cnt++;
		}
	}
	cout << cnt;
}