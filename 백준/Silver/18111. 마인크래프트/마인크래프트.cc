#include <iostream>
#include <climits>
/*
제거 2초 설치 1초
최소 시간 및 그에 따른 높이는?
최소 시간이 같다면 가장 높은 높이 출력
가중치 고려해서 다 더한 다음 평균의 반올림으로 높이 설정?

1. 최고 높이, 최소 높이 찾기
2. 높이마다 걸리는 시간 측정
크면 자르고 작으면 쌓기
3. 최소 시간 찾기?
*/

using namespace std;

int map[500][500];
int n, m, b, max_h = 0, min_h = 256, min_t = INT_MAX, h;

int cal(int std,int tmp_b) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] > std) { // 제거하는 경우
				tmp_b += map[i][j] - std;
				sum += (map[i][j] - std) * 2;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] < std) { //  설치하는 경우
				if (tmp_b<std-map[i][j]) {
					return -1; // 블럭이 없어 설치가 불가능한 경우
				}
				tmp_b -= std - map[i][j];
				sum += (std - map[i][j]);
			}
		}
	}
	return sum;
}

int main() {
	cin >> n >> m >> b;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			max_h = max(map[i][j], max_h);
			min_h = min(map[i][j], min_h);
		}
	}

	for (int i = max_h; i >= min_h; i--) {
		if (cal(i,b) < min_t && cal(i,b) != -1) {
			min_t = cal(i, b);
			h = i;
		}
	}
	cout << min_t << ' ' << h;
}