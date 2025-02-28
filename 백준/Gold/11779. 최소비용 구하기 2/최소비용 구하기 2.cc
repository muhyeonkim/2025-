#include <iostream>
#include <queue>
#include <algorithm>
/*
1. 출발 도시에서 도착 도시까지 최소 비용 -> dijkstra
2. 최소 비용 경로 상의 도시 개수 (출발 도시 및 도착 도시 포함)
3. 최소 비용을 방문하는 순서 출력(여러 개면 아무거나)

*/

using namespace std;

vector<pair<int, long long int>>map[1001];
int prev_edge[1001];
long long int dist[1001];
int n, m;

void dijkstra(int start) {
	fill(dist, dist + 1001, 20000000000);
	priority_queue<pair<long long int, int>, vector<pair<long long int, int>>, greater<>>pq; //비용 간선
	dist[start] = 0;

	pq.push({ 0,start });
	while (!pq.empty()) {
		int cur_cost = pq.top().first;
		int cur_edge = pq.top().second;
		pq.pop();
		if (dist[cur_edge] < cur_cost) continue;
		for (auto a : map[cur_edge]) {
			int next_edge = a.first;
			int next_cost = a.second + cur_cost;
			if (next_cost < dist[next_edge]) {
				dist[next_edge] = next_cost;
				prev_edge[next_edge] = cur_edge;
				pq.push({ next_cost,next_edge });
			}
		}
	}
}

int main() {
	vector<int>path;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int start, end, cost;
		cin >> start >> end >> cost;
		map[start].push_back({ end,cost });
	}

	int start, end;
	cin >> start >> end;
	dijkstra(start);
	for (int v = end; v != start; v = prev_edge[v]) {
		path.push_back(v);
	}
	path.push_back(start);

	cout << dist[end] << "\n" << path.size() << "\n";
	for (int i = path.size() - 1; i >= 0; i--) {
		cout << path[i] << ' ';
	}
}