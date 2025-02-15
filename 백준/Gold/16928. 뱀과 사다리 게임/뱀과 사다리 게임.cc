#include <iostream>
#include <queue>
using namespace std;

/*
i+6과 사다리와 뱀을 queue에 넣기
x+6이 아니라 사다리(혹은 뱀)이 없는 칸 중 가장 큰 칸으로 가기
100번 째 칸에 도착하면 cnt return하기
*/

int map[101];

int search() {
	queue<pair<int,int>>q; // 위치, 주사위 횟수
	q.push({ 1,0 });
	while (!q.empty()) {
		int x = q.front().first;
		int cnt = q.front().second;
		int max = 1;
		q.pop();
		//cout << x << ' ' << cnt << "\n";
		for (int i = 1; i <= 6; i++) {
			if (x + i == 100)
				return cnt + 1;
			if (x + i < 100 && map[x + i] != 0) { // 사다리 혹은 뱀이 있는 경우
				q.push({ map[x + i],cnt + 1 });
			}
			else {
				max = i;
			}
		}
		q.push({ x + max,cnt + 1 });
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		map[x] = y;
	}
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		map[x] = y;
	}
	cout << search();
}