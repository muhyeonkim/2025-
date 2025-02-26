#include <iostream>
#include <queue>

using namespace std;

int map[100001];  // 최단 시간을 기록
int n, k;
int cnt = 0, t = 100000;

void BFS() {
    queue<int> q;
    q.push(n);
    map[n] = 0;

    while (!q.empty()) {
        int x = q.front();
        q.pop();

        if (x == k) {
            if (map[x] < t) {
                t = map[x];
                cnt = 1;  // 처음 도달한 경우
            }
            else if (map[x] == t) {
                cnt++;   // 같은 시간에 도달한 경우의 수 증가
            }
            continue;
        }

        int next_positions[] = { x + 1, x - 1, x * 2 };
        for (int next : next_positions) {
            if (next >= 0 && next <= 100000) {
                if (map[next] == 0 || map[next] == map[x] + 1) {
                    map[next] = map[x] + 1;
                    q.push(next);
                }
            }
        }
    }
}

int main() {
    cin >> n >> k;

    if (n == k) {
        cout << "0\n1";
        return 0;
    }

    BFS();
    cout << t << "\n" << cnt;
}