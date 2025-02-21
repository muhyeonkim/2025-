#include <iostream>
using namespace std;

int n;
int map[16][16];
int dp[3][16][16]; // 0: 가로, 1: 대각선, 2: 세로

int main() {
    cin >> n;

    // 집 상태 입력
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }

    // 초기 상태: 가로 방향 (0,0) -> (0,1)
    dp[0][0][1] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n; j++) {
            // 가로 → 가로, 가로 → 대각선
            if (j + 1 < n && map[i][j + 1] == 0) {
                dp[0][i][j + 1] += dp[0][i][j]; // 가로 → 가로
            }
            if (i + 1 < n && j + 1 < n && map[i][j + 1] == 0 && map[i + 1][j] == 0 && map[i + 1][j + 1] == 0) {
                dp[1][i + 1][j + 1] += dp[0][i][j]; // 가로 → 대각선
            }

            // 대각선 → 가로, 대각선 → 대각선, 대각선 → 세로
            if (j + 1 < n && map[i][j + 1] == 0) {
                dp[0][i][j + 1] += dp[1][i][j]; // 대각선 → 가로
            }
            if (i + 1 < n && j + 1 < n && map[i][j + 1] == 0 && map[i + 1][j] == 0 && map[i + 1][j + 1] == 0) {
                dp[1][i + 1][j + 1] += dp[1][i][j]; // 대각선 → 대각선
            }
            if (i + 1 < n && map[i + 1][j] == 0) {
                dp[2][i + 1][j] += dp[1][i][j]; // 대각선 → 세로
            }

            // 세로 → 세로, 세로 → 대각선
            if (i + 1 < n && map[i + 1][j] == 0) {
                dp[2][i + 1][j] += dp[2][i][j]; // 세로 → 세로
            }
            if (i + 1 < n && j + 1 < n && map[i][j + 1] == 0 && map[i + 1][j] == 0 && map[i + 1][j + 1] == 0) {
                dp[1][i + 1][j + 1] += dp[2][i][j]; // 세로 → 대각선
            }
        }
    }

    // (N-1, N-1) 위치에 도달하는 모든 경우의 수 합산
    cout << dp[0][n - 1][n - 1] + dp[1][n - 1][n - 1] + dp[2][n - 1][n - 1] << "\n";

    return 0;
}
