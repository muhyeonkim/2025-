#include <iostream>
#include <queue>
#include <climits>
using namespace std;

vector<pair<int, int>>graph[20001];
vector<int>dist(20001, INT_MAX);

void dijkstra(int x) {
	priority_queue<pair<int, int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;// 비용 간선
	pq.push({ 0,x });
	dist[x] = 0;
	while (!pq.empty()) {
		int cost = pq.top().first;
		int current_edge = pq.top().second;
		pq.pop();
		if (dist[current_edge] < cost) continue;
		for (auto a : graph[current_edge]) {
			int next_edge = a.first;
			int next_cost = cost + a.second;
			if (next_cost < dist[next_edge]) {
				dist[next_edge] = next_cost;
				pq.push({ next_cost,next_edge });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int v, e, k;
	cin >> v >> e >> k;
	for (int i = 0; i < e; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back({ v, w }); // 간선 비용
	}

	dijkstra(k);
	for (int i = 1; i <= v; i++) {
		if (dist[i] == INT_MAX)
			cout << "INF\n";
		else
			cout << dist[i] << "\n";
	}
}