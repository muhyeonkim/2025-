#include <iostream>
#include <vector>
#include <cstring>

/*
트리의 지름
트리에서 임의의 두 점 사이의 거리 중 가장 긴 것

*/

using namespace std;
int n, max_dist, idx;
vector<pair<int, int>>v[100001];
bool visited[100001];

void DFS(int x,int y) { //x는 현재 노드, y는 거리
	if (max_dist < y) {
		max_dist = y;
		idx = x;
	}
	max_dist = max(max_dist, y);
	visited[x] = true;
	for (auto a : v[x]) {
		if(visited[a.first]==false)
			DFS(a.first, y + a.second);
	}
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int num, end = 0, cost = 0;
		cin >> num;
		while (1) {
			cin >> end;
			if (end == -1) break;
			cin >> cost;
			v[num].push_back({ end,cost });
		}
	}
	DFS(1, 0);
	memset(visited, 0, sizeof(visited));
	max_dist = 0;
	DFS(idx, 0);
	cout << max_dist;
}