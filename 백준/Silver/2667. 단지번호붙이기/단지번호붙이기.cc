#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
/*
반복문 횟수 cnt
*/

using namespace std;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
bool map[26][26];
bool visited[26][26];

int n;

bool isOutofLine(int x, int y) {
	if (x >= 0 && x < n && y >= 0 && y < n) return true;
	else return false;
}

int BFS(int x, int y) {
	queue<pair<int, int>>q;
	int cnt = 1;
	visited[x][y] = 1;
	q.push({ x,y });
	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = a + dx[i];
			int ny = b + dy[i];
			if (isOutofLine(nx, ny) && map[nx][ny] == 1 && !visited[nx][ny]) {
				visited[nx][ny] = 1;
				cnt++;
				q.push({ nx,ny });
			}
		}
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector<int>v;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < n; j++) {
			map[i][j] = s[j] - '0';
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 1 && visited[i][j] == 0) {
				v.push_back(BFS(i, j));
			}
		}
	}

	sort(v.begin(), v.end());
	cout << v.size() << "\n";
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << "\n";
	}
}