#include <iostream>
#include <algorithm>
#include <queue>

/*
다익스트라 후 x로 가는 값 저장 해야함

*/

using namespace std;

vector<pair<int, int>>v[1001];
int dist[1001];

void dijkstra(int x) {
	fill(dist, dist + 1001, 10000000);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>>pq; // 비용 간선
	pq.push({ 0,x });
	dist[x] = 0;
	while (!pq.empty()){
		int cur_cost = pq.top().first;
		int cur_edge = pq.top().second;
		pq.pop();
		if (cur_cost > dist[cur_edge]) continue;
		for (auto a : v[cur_edge]) {
			int next_edge = a.first;
			int next_cost = a.second + dist[cur_edge];
			if (next_cost < dist[next_edge]) {
				dist[next_edge] = next_cost;
				pq.push({ next_cost,next_edge });
			}
		}
	}
}

int main() {
	vector<int>total;
	int n, m, x, max_cost = 0;
	cin >> n >> m >> x;
	for (int i = 1; i <= m; i++) {
		int start, end, t;
		cin >> start >> end >> t;
		v[start].push_back({ end,t });
	}

	for (int i = 1; i <= n; i++) {
		dijkstra(i);
		total.push_back(dist[x]);
	}
	dijkstra(x);
	for (int i = 1; i <= n; i++) {
		max_cost = max(max_cost, dist[i] + total[i-1]);
	}
	cout << max_cost;
}