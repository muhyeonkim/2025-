#include <iostream>

using namespace std;

int main() {
    long long a, b, cnt = 0;
    cin >> a >> b;

    while (a != b) {
        if (a > b) {  // A가 B보다 크면 만들 수 없음
            cout << -1;
            return 0;
        }

        if (b % 2 == 0) {
            b /= 2;
        }
        else if (b % 10 == 1) {
            b /= 10;
        }
        else {  // 2로 나눌 수도 없고, 끝이 1도 아닌 경우
            cout << -1;
            return 0;
        }
        cnt++;
    }

    cout << cnt + 1; // 연산 횟수 + 1 출력
}