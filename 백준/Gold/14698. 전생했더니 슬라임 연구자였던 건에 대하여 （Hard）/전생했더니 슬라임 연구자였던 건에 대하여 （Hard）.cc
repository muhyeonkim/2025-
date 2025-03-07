#include <iostream>
#include <queue>

using namespace std;

const long long MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
	cin.tie(0);
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;

        priority_queue<long long, vector<long long>, greater<long long>> pq;
        
        for (int i = 0; i < n; i++) {
            long long x;
            cin >> x;
            pq.push(x);
        }

        if (n == 1) { // 슬라임이 1마리면 비용 1 출력
            cout << 1 << "\n";
            continue;
        }

        long long cost = 1; // 결과값 (곱셈이므로 초기값 1)
        
        while (pq.size() > 1) {
            long long first = pq.top(); pq.pop();
            long long second = pq.top(); pq.pop();

            long long energy = (first * second) % MOD; // 곱할 때마다 MOD 연산
            cost = (cost * energy) % MOD; // 총 비용도 MOD 연산

            pq.push(first * second); // 새로운 슬라임 추가
        }

        cout << cost << "\n";
    }
    
    return 0;
}