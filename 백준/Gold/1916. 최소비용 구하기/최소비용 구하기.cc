#include <iostream>
#include <queue>
#include <climits>
using namespace std;

vector<pair<int, int>>map[1001];
vector<int>dist(1001, INT_MAX);
int n, m;

void dijkstra(int x) { //시작 노드
	priority_queue<pair<int, int>>pq;
	dist[x] = 0;
	pq.push({ 0,x });
	while (!pq.empty()) {
		int cost = pq.top().first;
		int nx = pq.top().second;
		pq.pop();

		if (cost > dist[nx]) continue;

		for (auto edge : map[nx]) {
			int next_edge = edge.first;
			int next_cost = cost + edge.second;
			if (next_cost < dist[next_edge]) {
				dist[next_edge] = next_cost;
				pq.push({ next_cost,next_edge });
			}
		}
	}

}

int main() {
	int start, end;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int start, end, cost;
		cin >> start >> end >> cost;
		map[start].push_back({ end,cost });
	}
	cin >> start >> end;

	dijkstra(start);
	cout << dist[end];
}