#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n, cnt = 0, last_end_time = 0; // last_end_time은 마지막으로 선택된 회의의 종료 시간
    vector<pair<int, int>> v;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int s, e;
        cin >> s >> e;
        v.push_back({ e, s }); // 종료 시간을 기준으로 정렬하기 위해 순서를 반대로 저장
    }

    sort(v.begin(), v.end()); // 종료 시간 기준으로 정렬

    for (auto a : v) {
        if (a.second >= last_end_time) { // 현재 회의의 시작 시간이 마지막 회의의 종료 시간 이후인 경우 선택
            cnt++;
            last_end_time = a.first; // 마지막 회의의 종료 시간을 갱신
        }
    }

    cout << cnt; // 최대 사용할 수 있는 회의 개수 출력
    return 0;
}