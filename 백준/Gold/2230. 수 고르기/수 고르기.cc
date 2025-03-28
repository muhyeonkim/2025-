#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    int res = INT_MAX;
    int left = 0, right = 0;

    while (right < n) {
        if (v[right] - v[left] >= m) {
            res = min(res, v[right] - v[left]);
            left++; // 최소 차이를 찾기 위해 left 증가
            if (v[right] - v[left] == m) {
                cout << m;
                return 0;
            }
        }
        else right++;
    }

    cout << res;
}