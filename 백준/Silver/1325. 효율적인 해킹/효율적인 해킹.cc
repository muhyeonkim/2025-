#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

/*
A가 B를 신뢰하면 B를 해킹시 A도 해킹 가능
한 번에 가장 많은 컴퓨터를 해킹할 수 있는 컴퓨터 번호?
1부터 n까지 전부 DFS를 돌려서 해킹 가능한 컴퓨터의 개수를 세고 가장 많은 개수를 출력하기?
3 1이 있으면 3은 1을 신뢰하지만 1은 3을 신뢰하지 않는다.
3 1, 1 4가 있다면 3은 1을, 1은 4를 신뢰한다. 그러면 4를 해킹하면 1과 3을 해킹할 수 있다.
*/

using namespace std;

vector<int>v[10001];
bool visited[10001];
int computer[10001];
int max_computer;

void DFS(int x) {
	int cnt = 1;
	queue<int>q;
	visited[x] = true;
	q.push(x);
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (auto a : v[x]) {
			if (visited[a] == false) {
				visited[a] = true;
				cnt++;
				q.push(a);
			}
		}
	}
	computer[x] = cnt;
	max_computer = max(cnt, max_computer);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		DFS(i);
		memset(visited, 0, sizeof(visited));
	}
	for (int i = 1; i <= n; i++) {
		if (computer[i] == max_computer) cout << i << ' ';
	}
}