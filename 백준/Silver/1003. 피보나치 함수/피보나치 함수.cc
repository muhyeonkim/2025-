#include <iostream>

using namespace std;

int dp_0[41];
int dp_1[41];



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    dp_0[0] = 1;
    dp_0[1] = 0;
    dp_1[0] = 0;
    dp_1[1] = 1;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 2; i <= n; i++) {
            dp_0[i] = dp_0[i - 1] + dp_0[i - 2];
            dp_1[i] = dp_1[i - 1] + dp_1[i - 2];
        }
        cout << dp_0[n] << ' ' << dp_1[n] << "\n";
    }
}