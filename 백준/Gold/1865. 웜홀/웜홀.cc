#include <iostream>
#include <vector>
#include <cstring>
#include <climits>
/*
도로: 방향없음 (양방향)
웜홀: 방향있음 (단방향), 시간 뒤로 감

*/

struct edges {
	int start = 0, end = 0, cost = 0;
};
using namespace std;
int n, m, w;
vector<edges>v;
int dist[501];

bool bellman_ford() {
	memset(dist, INT_MAX, sizeof(dist));
	dist[1] = 0;
	for (int i = 1; i <= n; i++) {
		for (auto edge : v) {
			if (dist[edge.start] == INT_MAX) continue;
			if (dist[edge.end] > dist[edge.start] + edge.cost) {
				if (i == n) return true;
				dist[edge.end] = dist[edge.start] + edge.cost;
			}
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		v.clear();
		cin >> n >> m >> w;
		for (int i = 0; i < m; i++) { //도로
			int s, e, t; // 시작 끝 시간
			cin >> s >> e >> t;
			v.push_back({ s,e,t });
			v.push_back({ e,s,t });
		}
		for (int i = 0; i < w; i++) { //웜홀
			int s, e, t; // 시작 끝 시간
			cin >> s >> e >> t;
			v.push_back({ s,e,-t });
		}

		string result = "NO";
		
		if (bellman_ford() == true) {
			result = "YES";
		}
		cout << result << "\n";
	}
}