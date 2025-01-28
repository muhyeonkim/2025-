#include <iostream>
#include <queue>

using namespace std;

int map[1001][1001];
bool visited[1001];
int n, m, v;
queue<int>q;

void DFS(int v) {
	cout << v << ' ';
	visited[v] = 1;
	for (int i = 1; i <= n; i++) {
		if (map[v][i] == 1 && visited[i] == 0) {
			DFS(i);
		}
	}
}
void BFS(int v) {
	q.push(v);
	visited[v] = 1;
	while (!q.empty()) {
		cout << q.front() << ' ';
		for (int i = 1; i <= n; i++) {
			if (map[q.front()][i] == 1 && visited[i] == 0) {
				q.push(i);
				visited[i] = 1;
			}
		}
		q.pop();
	}
}

int main() {
	cin >> n >> m >> v;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		map[x][y] = 1;
		map[y][x] = 1;
	}

	DFS(v);
	cout << "\n";
	fill(visited, visited + 1001, 0);
	BFS(v);


}