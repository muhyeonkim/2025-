#include <iostream>
#include <queue>
/*
그냥 순서대로 가기
bfs느낌으로
1. +1
2. -1
3. +a
4. -a
5. +b
6. -b
7. *a
8  *b
*/
using namespace std;

bool visited[100001];
int a, b, n, m;
int dx[6] = { 1,-1};

bool isOutofLine(int x) {
	if (x >= 0 && x <= 100000) return true;
	else return false;
}

void dps(int x) {
	queue<pair<int, int>>q;// 위치 횟수
	q.push({ x,0 });
	while (!q.empty()) {
		int x = q.front().first;
		int cnt = q.front().second;
		q.pop();
		if (x == m) {
			cout << cnt;
			break;
		}
		for (int i = 0; i < 6; i++) {
			int nx = x + dx[i];
			if (isOutofLine(nx) && visited[nx] == false) {
				visited[nx] = true;
				q.push({ nx,cnt + 1 });
			}
		}
		int nx = x * a;
		if (isOutofLine(nx) && visited[nx] == false) {
			visited[nx] = true;
			q.push({ nx,cnt + 1 });
		}
		nx = x * b;
		if (isOutofLine(nx) && visited[nx] == false) {
			visited[nx] = true;
			q.push({ nx,cnt + 1 });
		}
	}
}

int main() {
	cin >> a >> b >> n >> m;
	dx[2] = a, dx[3] = -a, dx[4] = b, dx[5] = -b;
	dps(n);
}