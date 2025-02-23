#include <iostream>
#include <vector>
#include <climits>
#include <queue>
/*
한 정점에서 다른 정점으로 가는 최단거리 -> 다익스트라
1번 노드에서 v1,v2의 최소 거리를 구한다.
v1의 노드에서 v2와 n까지의 최소 거리를 구한다.
v2의 노드에서 v3와 n까지의 최소 거리를 구한다.
비교해서 제일 짧은 걸로 정한다.
단 INT_MAX면 -1 출력한다.
*/

using namespace std;

int n, e;
vector<pair<int, int>>map[801];
vector<int>dist(801, INT_MAX);

void dijkstra(int x) {
	priority_queue<pair<int, int>>pq; // 비용 간선
	dist[x] = 0;
	pq.push({ 0,x });
	
	while (!pq.empty()) {
		int cost = pq.top().first;
		int now_edge = pq.top().second;
		pq.pop();
		if (cost > dist[now_edge]) continue;
		for (auto a : map[now_edge]) {
			int next_edge = a.first;
			int next_cost = cost+a.second;
			if (dist[next_edge] >  next_cost) {
				dist[next_edge] = next_cost;
				pq.push({ next_cost,next_edge });
			}
		}
	}
	
}


int main() {
	cin >> n >> e;
	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		map[a].push_back({ b,c });// 간선 비용
		map[b].push_back({ a,c });
	}
	int v1, v2;
	cin >> v1 >> v2;
	dijkstra(1);
	int a, b, c, d, e, f;
	a = dist[v1], b = dist[v2];
	dist.assign(801, INT_MAX);
	dijkstra(v1);
	c = dist[v2], d = dist[n];
	dist.assign(801, INT_MAX);
	dijkstra(v2);
	e = dist[n], f = dist[v1];

	if (a == INT_MAX || c == INT_MAX || e == INT_MAX) {
		if (b == INT_MAX || d == INT_MAX || f == INT_MAX) {
			cout << -1;
		}
		else
			cout << b + d + f;
	}
	else if (b == INT_MAX || d == INT_MAX || f == INT_MAX) {
		cout << a + c + e;
	}
	else { // 못 가는 경우가 없을 때
		cout << min(a + c + e, b + d + f);
	}
	//cout << "\n" << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << ' ' << f;
}