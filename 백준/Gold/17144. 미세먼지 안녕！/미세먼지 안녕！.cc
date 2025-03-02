#include <iostream>
#include <cmath>
#include <queue>
/*
바람 가운데에 먼지는 확산은 되지만 바람에 이해 이동하지는 않는다
먼지가 있는 좌표들을 모아서 한 번에 처리해야함
먼지를 발견했을 때
1. 먼지의 좌표와 크기를 기록한다.
2. map의 탐색이 종료 후 기록지를 탐색한다.
3. 확산되는 양 만큼 좌표에서 빼고 상 하 좌 우에 더한다.(map에서 양을 정하는 것이 아닌 기록지를 보고 정한다, map에서 정하면 동시에 일어난 확산이 영향을 받을 수 있기 때문)

*/

using namespace std;

int r, c, t, air_x, air_y;
int map[51][51];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

struct dust{
	int x, y, mess;
};

bool isOutofLine(int x, int y) {
	if (x >= 0 && y >= 0 && x < r && y < c) return true;
	else return false;
}

void diffuse() {
	queue<dust>q;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (map[i][j] != 0 && map[i][j] != -1) { //먼지를 발견 했을 때
				q.push({ i,j,map[i][j] });
			}
		}
	}
	while (!q.empty()) {
		for (int i = 0; i < 4; i++) {
			int nx = q.front().x + dx[i]; 
			int ny = q.front().y + dy[i];
			int nmess = q.front().mess / 5;
			if (isOutofLine(nx, ny) && map[nx][ny] != -1) { 
				map[nx][ny] += nmess;
				map[q.front().x][q.front().y] -= nmess;
			}
		}
		q.pop();
	}
}

void wind_blow() {
	map[air_x - 1][air_y];//공기청정기 윗부분의 위치
	map[air_x][air_y];//공기청정기 밑부분의 위치

	for (int i = air_x - 3; i >= 0; i--) { // 위에서 밑으로 밀기
		map[i + 1][0] = map[i][0];
	}
	for (int i = air_x + 2; i < r; i++) { // 밑에서 위로 밀기
		map[i - 1][0] = map[i][0];
	}

	for (int i = 0; i < c - 1; i++) {// 왼쪽으로 밀기
		map[0][i] = map[0][i + 1];
		map[r - 1][i] = map[r - 1][i + 1];
	}

	for (int i = 0; i < air_x - 1; i++) { // 밑에서 위로 밀기
		map[i][c-1] = map[i + 1][c-1];
	}
	

	for (int i = r - 1; i > air_x; i--) { // 위에서 밑으로 밀기
		map[i][c-1] = map[i - 1][c-1];
	}
	
	for (int i = c - 1; i > 1; i--) {// 오른쪽으로 밀기
		map[air_x - 1][i] = map[air_x - 1][i - 1];
		map[air_x][i] = map[air_x][i - 1];
	}
	map[air_x - 1][1] = 0;
	map[air_x][1] = 0;

}

int main() {
	int total = 0;
	cin >> r >> c >> t;
	pair<int, int>air;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> map[i][j];
			if (map[i][j] == -1) {
				air_x = i;
				air_y = j;
			}
		}
	}

	for (int i = 0; i < t; i++) {
		diffuse();
		wind_blow();
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			total += map[i][j];
			//cout << map[i][j] << ' ';
		}
		//cout << "\n";
	}
	cout << total + 2;
}