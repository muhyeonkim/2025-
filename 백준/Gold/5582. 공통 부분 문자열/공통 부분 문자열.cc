#include <iostream>
#include <algorithm>

using namespace std;

int dp[4001][4001];

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    int maxLength = 0; // 최댓값 저장

    for (int i = 1; i <= s1.length(); i++) {
        for (int j = 1; j <= s2.length(); j++) {
            if (s1[i - 1] == s2[j - 1]) { // 같은 문자인 경우
                dp[i][j] = dp[i - 1][j - 1] + 1;
                maxLength = max(maxLength, dp[i][j]); // 최댓값 갱신
            }
        }
    }

    cout << maxLength << '\n'; // 가장 긴 공통 부분 문자열의 길이 출력
}