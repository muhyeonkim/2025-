#include <iostream>
#include <vector>
#include <cstring>
/*
DFS
정점의 집합을 둘로 분할, 각 집합에 속한 정점끼리는 서로 인접하지 않도록 분할 가능이면 이분 그래프
즉, 같은 집합에 있는 정점끼리는 연결 x
정점의 개수 v 간선의 개수 e 정점은 1번부터 v번까지
이분 그래프이면 yes 아니면 no
그러면 짝수번째 도착하는 정점을 0번 그룹(시작을 0이라할 때) 홀수번째를 1번 그룹이라하기
단, 방문하지 않은 정점만
*/

using namespace std;

vector<int>board[20001];
int visited[20001]; // 0은 미방문, 1은 red(짝수),2는 blue(홀수)
int v, e;
void DFS(int x, int cnt) {
	if (cnt % 2 == 0) visited[x] = 1;
	else visited[x] = 2;
	for (auto a : board[x]) {
		if (visited[a] == 0) {
			DFS(a, cnt + 1);
		}
	}
}

bool check() {
	for (int i = 1; i <= v; i++) {
		for (auto a : board[i]) {
			if (visited[a] == visited[i]) { // 같은 그룹 내에서 인접한 경우
				return false;
			}
		}
	}
	return true;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		memset(board, 0, sizeof(board));
		memset(visited, 0, sizeof(visited));
		cin >> v >> e;
		for (int i = 0; i < e; i++) {
			int x, y;
			cin >> x >> y;
			board[x].push_back(y);
			board[y].push_back(x);
		}
		for (int i = 1; i <= v; i++) {
			if (visited[i] == 0) {
				DFS(i, 0);
			}
		}
		if (check()) cout << "YES\n";
		else cout << "NO\n";
	}
}