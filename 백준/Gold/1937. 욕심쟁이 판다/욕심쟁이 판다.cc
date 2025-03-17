#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int n;
int board[501][501];
int dist[501][501];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool isOutofLine(int x, int y) {
    return (x >= 0 && y >= 0 && x < n && y < n);
}

int DFS(int x, int y) {
    if (dist[x][y] != -1) return dist[x][y]; // 이미 방문한 경우, 저장된 값 반환
    
    dist[x][y] = 1; // 최소 1칸은 이동 가능
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (isOutofLine(nx, ny) && board[nx][ny] > board[x][y]) {
            dist[x][y] = max(dist[x][y], DFS(nx, ny) + 1);
        }
    }
    return dist[x][y];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    memset(dist, -1, sizeof(dist)); // 초기값 -1로 설정 (방문 체크용)
    
    int max_cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            max_cnt = max(max_cnt, DFS(i, j));
        }
    }

    cout << max_cnt;
}