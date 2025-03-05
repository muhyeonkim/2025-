#include <iostream>

/*
출발 점을 감싸고 있는 행성이 몇개인가
도착 점을 감싸고 있는 원이 몇개인가
둘의 합이 정답
한 점을 감싸고 있다는 걸 계산하기
점과 원의 중심 사이의 거리와 반지름 계산하기
반지름보다 작으면 안에 있는 것
*/

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int x1, y1, x2, y2, n, cnt = 0;//출발점 도착점
		cin >> x1 >> y1 >> x2 >> y2>>n;
		for (int i = 0; i < n; i++) {
			int x, y, r, d, d2, d3;
			cin >> x >> y >> r;
			d = (x - x1) * (x - x1) + (y - y1) * (y - y1); //시작점과 행성
			d2 = (x - x2) * (x - x2) + (y - y2) * (y - y2); // 도착점과 행성
			d3 = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2); // 시작점과 도착점
			if (d < r * r && d2 < r * r) { //둘 다 한 행성안에 있는 경우
				continue;
			}
			else if (d < r * r) { // 안에 있는 경우
				cnt++;
			}
			else if (d2 < r * r) {
				cnt++;
			}
		}
		cout << cnt << "\n";
	}
}