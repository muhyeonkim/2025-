#include <iostream>
#include <vector>

using namespace std;

/*
현재 상태에서 다른 index를 확인해서 나보다 덩치가 큰 애들이 있는지 확인
*/

bool cmp(pair<int, int>p1, pair<int, int>p2) {
	return p1.first > p2.first && p1.second > p2.second;
}

int main() {
	int n;
	cin >> n;
	vector<pair<int, int>>v;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		v.push_back({ x,y });
	}
	for (int i = 0; i < n; i++) {
		int cnt = 1;
		for (int j = 0; j < n; j++) {
			if (v[i].first < v[j].first && v[i].second < v[j].second) {
				cnt++;
			}
		}
		cout << cnt << ' ';
	}
}