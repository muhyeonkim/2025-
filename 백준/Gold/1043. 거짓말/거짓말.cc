#include <iostream>
#include <vector>
using namespace std;

int n, m, k;
vector<int> p(51), r(51, 1);
vector<vector<int>> party;
vector<int> truth;

int find(int x) {
    if (p[x] == x) return x;
    return p[x] = find(p[x]);
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);
    p[a] = b;
}

int main() {
    cin >> n >> m >> k;

  
    for (int i = 1; i <= n; i++) p[i] = i;

    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        truth.push_back(x);
    }

    for (int i = 0; i < m; i++) {
        int a, first;
        cin >> a >> first;
        vector<int> tmp;
        tmp.push_back(first);
        for (int j = 1; j < a; j++) {
            int x;
            cin >> x;
            tmp.push_back(x);
            unite(first, x);  // 파티 참석자들을 하나의 집합으로 Union
        }
        party.push_back(tmp);
    }

    // 4. 거짓말 가능 여부 확인
    int cnt = 0;
    for (auto a : party) {
        bool canLie = false;
        for (auto b : a) {
            for (auto c : truth) {
                if (find(b) == find(c)) {  // 진실 아는 집합과 연결된 경우
                    canLie = true;
                    break;
                }
            }
        }
        if (canLie) cnt++;
    }

    // 5. 출력
    cout << m - cnt;
}