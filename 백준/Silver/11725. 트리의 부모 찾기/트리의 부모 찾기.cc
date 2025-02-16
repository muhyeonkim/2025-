#include <iostream>
#include <vector>
#include <queue>

/*
1. 양 방향으로 일단 설정
*/

using namespace std;

int parent[100001];
vector<int>v[100001];

void BFS(int x) {
	queue<int>q;
	q.push(x);
	parent[x] = -1;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		
		for (int next : v[x]) {
			if (parent[next] == 0) {
				parent[next] = x;
				q.push(next);
			}
		}
	}
}

int main() {
	int n;
	cin >> n;

	for (int i = 1; i < n; i++) {
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	BFS(1);
	for (int i = 2; i <= n; i++) {
		cout << parent[i] << "\n";
	}
}
