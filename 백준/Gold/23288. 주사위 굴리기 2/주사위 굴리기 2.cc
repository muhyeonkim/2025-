#include <iostream>
#include <queue>
#include <cstring>
/*
r : 북쪽으로부터 떨어진 칸의 개수
c : 서쪽으로부터 떨어진 칸의 개수
1. 주사위가 이동 방향으로 한 칸 굴러간다, 이동 방향에 칸이 없으면 반대 방향으로 한 칸 굴러간다. 처음 주사위의 이동 방향은 동쪽이다.
2. 주사위가 도착한 칸 (x,y)에 대한 점수를 획득한다.
3. 주사위의 아랫면에 있는 정수 A와 주사위가 있는 칸 (x,y)에 있는 정수 B를 비교해 이동 방향을 결정한다.
점수는 B*C이다.
C는 (x,y)에서 동서남북 방향으로 연속해서 이동할 수 있는 칸의 수 이다.

이동 방향으로 굴러가기
점수 획득 (DFS or BFS)
방향 결정
*/

using namespace std;

int board[21][21];
int dice[6] = { 1,2,3,4,5,6 };
int top = 0, bottom = 5, front = 1, back = 4, Left = 3, Right = 2;

int dir_x[4] = { 0,1,0,-1 }; // // 남 북
int dir_y[4] = { 1,0,-1,0 }; // 동 서 
int cur_x = 1, cur_y = 1;
int n, m, k, score, dir;// 방향 0 : 동 1 : 남 2 : 서  3 : 북

void rollEast() {
	int tmp = dice[top];
	dice[top] = dice[Left];
	dice[Left] = dice[bottom];
	dice[bottom] = dice[Right];
	dice[Right] = tmp;
}

void rollWest() {
	int tmp = dice[top];
	dice[top] = dice[Right];
	dice[Right] = dice[bottom];
	dice[bottom] = dice[Left];
	dice[Left] = tmp;
}



void rollSouth() {
	int tmp = dice[top];
	dice[top] = dice[front];
	dice[front] = dice[bottom];
	dice[bottom] = dice[back];
	dice[back] = tmp;
}

void rollNorth() {
	
	int tmp = dice[top];
	dice[top] = dice[back];
	dice[back] = dice[bottom];
	dice[bottom] = dice[front];
	dice[front] = tmp;
}
bool isOutofLine(int x, int y) {
	if (x >= 1 && y >= 1 && x <= n && y <= m) return true;
	else return false;
}

void BFS(int x, int y, int b) {
	bool visited[21][21] = { 0 };  // BFS 실행 시마다 초기화
	int cnt = 1;
	queue<pair<int, int>>q;// x,y
	visited[x][y] = 1;
	q.push({ x,y });
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dir_x[i];
			int ny = y + dir_y[i];
			if (isOutofLine(nx, ny) && board[nx][ny] == b && visited[nx][ny] == 0) {
				q.push({ nx,ny });
				visited[nx][ny] = 1;
				cnt++;
			}
		}
	}
	score += cnt * b;
}


int main() {
	
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> board[i][j];
		}
	}
	for (int i = 0; i < k; i++) {
		if (isOutofLine(cur_x + dir_x[dir], cur_y + dir_y[dir])) {
			cur_x += dir_x[dir]; //일단 이동 방향으로 이동중
			cur_y += dir_y[dir];
			if (dir == 0) rollEast();
			else if (dir == 1) rollSouth();
			else if (dir == 2) rollWest();
			else if (dir == 3) rollNorth();
		}
		else { // 이동 방향에 칸이 없을 경우
			dir = (dir + 2) % 4; // 방향을 180도 회전
			cur_x += dir_x[dir];
			cur_y += dir_y[dir];

			if (dir == 0) rollEast();
			else if (dir == 1) rollSouth();
			else if (dir == 2) rollWest();
			else if (dir == 3) rollNorth();

		}
		
		BFS(cur_x, cur_y, board[cur_x][cur_y]); // 점수 획득 

		//이동 방향 설정
		if (dice[bottom] > board[cur_x][cur_y]) {
			dir = (dir + 1) % 4; // 90도 시계 방향 회전
		}
		else if (dice[bottom] < board[cur_x][cur_y]) {
			dir = (dir + 3) % 4; // 90도 반시계 방향 회전
		}

		/*for (int i = 0; i < 6; i++) {
			cout << dice[i] << ' ';
		}
		cout << "\n";*/
	}
	cout << score;
}