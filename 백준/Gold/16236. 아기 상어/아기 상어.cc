#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int n, start_x, start_y, t;

bool visited[21][21];
bool fish_eat = true;
int map[21][21];
int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,-1,1,0 };
pair<int, int>shark = { 2,0 };//크기 먹은 물고기 수

bool isOutofLine(int x, int y) {
	if (x >= 0 && y >= 0 && x < n && y < n) return true;
	else return false;
}

void BFS(int x, int y) {
	queue<pair<int, pair<int, int>>>q; //시간 x y
	priority_queue<pair<int, pair<int, int>>,vector<pair<int, pair<int, int>>>,greater<>>pq;
	q.push({ 0, { x,y } });
	visited[x][y] = 1;
	while (!q.empty()){
		int x = q.front().second.first;
		int y = q.front().second.second;
		int cur_t = q.front().first;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (isOutofLine(nx, ny) && visited[nx][ny] == 0&&map[nx][ny]<=shark.first) {
				visited[nx][ny] = 1;
				q.push({ cur_t + 1,{nx,ny} });
				if (map[nx][ny] != 0&&map[nx][ny]<shark.first) { //해당 위치가 먹을 수 있는 물고기인 경우
					pq.push({ cur_t + 1,{nx,ny} });
				}
			}
		}
	}
	if (!pq.empty()) { // 먹을 수 있는 물고기가 있을 때
		t += pq.top().first;
		start_x = pq.top().second.first;
		start_y = pq.top().second.second;
		shark.second++;
		if (shark.first == shark.second) {
			shark.first++;
			shark.second = 0;
		}
		map[start_x][start_y] = 0;
	}
	else {
		fish_eat = false;
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) {
				start_x = i;
				start_y = j;
				map[i][j] = 0;
			}
		}
	}
	while (fish_eat) {
		BFS(start_x, start_y);
		//cout << start_x << ' ' << start_y << "\n";
		memset(visited, 0, sizeof(visited)); // 탐색 후 visit 초기화
	}
	cout << t;
}