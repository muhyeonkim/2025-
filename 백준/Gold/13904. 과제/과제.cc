#include <iostream>
#include <vector>
#include <algorithm>

/*
얻을 수 있는 점수의 최댓값 출력하기
d는 마감일까지 남은 일수, w는 과제의 점수
하루에 한 과제를 끝낼 수 있다.
어떤거 순으로 해야하지?
제일 마감일이 길게 남은 날 부터 차례로 하루씩 빼면서
해당 날까지 남은 과제 중 가장 점수가 높은 것 부터 해결하기.
*/

using namespace std;

int main() {
	int n, day = 0, score = 0;
	vector<pair<int, int>>v;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int d, w;
		cin >> d >> w;
		v.push_back({ d,w });
	}
	sort(v.begin(), v.end(),greater<pair<int,int>>());
	day = v[0].first;
	while (day != 0) {
		int max_score = 0, idx = 0;
		for (int i = 0; i < v.size(); i++) {
			if (day <= v[i].first&&max_score<v[i].second) { // 수행할 과제 찾기
				max_score = max(max_score, v[i].second);
				idx = i;
			}
		}
		day--;
		if (max_score == 0) continue; // 수행할 과제가 없으면 넘어가기
		v.erase(v.begin() + idx); // 있으면 점수 더하고 해당 과제 제거하기

		score += max_score;
		
	}
	cout << score;
}