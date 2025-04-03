#include <iostream>
#include <string>

using namespace std;

// 회문 판별 함수
bool isPalindrome(const string& s, int left, int right) {
    while (left < right) {
        if (s[left] != s[right]) return false;
        left++, right--;
    }
    return true;
}

int checkPalindromeType(const string& s) {
    int left = 0, right = s.length() - 1;

    while (left < right) {
        if (s[left] != s[right]) {
            // 하나를 제거해서 회문이 되는지 검사
            if (isPalindrome(s, left + 1, right) || isPalindrome(s, left, right - 1)) {
                return 1; // 유사회문
            }
            return 2; // 일반 문자열
        }
        left++, right--;
    }
    return 0; // 완전한 회문
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;
        cout << checkPalindromeType(s) << "\n";
    }

    return 0;
}