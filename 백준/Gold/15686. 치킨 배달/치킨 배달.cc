#include <iostream>
#include <vector>
#include <climits>
#include <cmath>

/*
치킨집 m개의 조합을 만든다.
그 조합에서 치킨 거리를 계산한다.
최솟값을 구한다.
*/
using namespace std;

int map[51][51];
int n, m, min_dist = INT_MAX;
vector<pair<int, int>>chicken;
vector<pair<int, int>>tmp;
vector<pair<int, int>>house;

void backtracking(int cnt, int idx) {
	if (cnt == m) {
		int sum = 0;
		for (auto a : house) { // 그냥 집
			int min_value = INT_MAX;
			for (auto b : tmp) { // 치킨 집
				min_value = min(abs(b.first - a.first) + abs(b.second - a.second), min_value); // 그냥 집에서 가장 가까운 치킨 집을 찾는 경우
			}
			sum += min_value;
		}
		min_dist = min(sum, min_dist);
		return;
	}
	for (int i = idx; i < chicken.size(); i++) {
		tmp.push_back(chicken[i]);
		backtracking(cnt + 1, i + 1);
		tmp.pop_back();
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int x;
			cin >> x;
			if (x == 1) {
				house.push_back({ i,j });
			}
			else if (x == 2) {
				chicken.push_back({ i,j });
			}
		}
	}
	backtracking(0, 0);
	cout << min_dist;
}