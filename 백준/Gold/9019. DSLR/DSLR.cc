#include <iostream>
#include <queue>
#include <cstring> // memset 사용을 위한 헤더

using namespace std;

bool visited[10000];

int main() {
    int t;
    cin >> t;
    while (t--) {
        int A, B;
        cin >> A >> B;
        memset(visited, 0, sizeof(visited)); // visited 배열 초기화

        queue<pair<int, string>> q;
        q.push({A, ""});
        visited[A] = true;

        while (!q.empty()) {
            int x = q.front().first;
            string s = q.front().second;
            q.pop();

            if (x == B) {
                cout << s << "\n";
                break;
            }

            // D 연산
            int d = (x * 2) % 10000;
            if (!visited[d]) {
                visited[d] = true;
                q.push({d, s + 'D'});
            }

            // S 연산
            int s_val = (x == 0) ? 9999 : x - 1;
            if (!visited[s_val]) {
                visited[s_val] = true;
                q.push({s_val, s + 'S'});
            }

            // L 연산
            int l = (x % 1000) * 10 + x / 1000;
            if (!visited[l]) {
                visited[l] = true;
                q.push({l, s + 'L'});
            }

            // R 연산
            int r = (x % 10) * 1000 + x / 10;
            if (!visited[r]) {
                visited[r] = true;
                q.push({r, s + 'R'});
            }
        }
    }
}