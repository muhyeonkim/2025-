#include <iostream>

/*
목표 : 같은 색 볼 끼리 모아놓는 최소 횟수는?
방법 : 
1.바로 옆에 다른 색깔 볼이 있으면 다 뛰어넘을 수 있다.
2.옮길 수 있는 볼의 색은 한 가지이다. 한 번 빨간색을 옮기면 다음에도 빨간색, 파란색이면 파란색을 옮겨야 한다.
그냥 빨강 맨 뒤로, 파랑 맨 뒤로 한 다음 횟수 비교해서 가장 작은거 고르기?
무조건 오른쪽으로 모으는게 아니라 한 쪽으로 몰면 됨
*/

using namespace std;

int main() {
	int n, red_right_cnt = 0, blue_right_cnt = 0, red_left_cnt = 0, blue_left_cnt = 0;
	string s;
	bool isRed = true;
	bool isBlue = true;
	cin >> n >> s;
	for (int i = n - 1; i >= 0; i--) { // 빨강 뒤로 보내기
		if (s[i] == 'B') {
			isRed = false;
		}
		if (s[i] == 'R' && isRed == false) {
			red_right_cnt++;
		}
	}
	isRed = true;
	for (int i = 0; i <n ; i++) { // 빨강 앞으로 보내기
		if (s[i] == 'B') {
			isRed = false;
		}
		if (s[i] == 'R' && isRed == false) {
			red_left_cnt++;
		}
	}

	for (int i = n - 1; i >= 0; i--) { // 파랑 뒤로 보내기
		if (s[i] == 'R') {
			isBlue = false;
		}
		if (s[i] == 'B' && isBlue == false) {
			blue_right_cnt++;
		}
	}
	isBlue = true;
	for (int i = 0; i < n; i++) { // 파랑 앞으로 보내기
		if (s[i] == 'R') {
			isBlue = false;
		}
		if (s[i] == 'B' && isBlue == false) {
			blue_left_cnt++;
		}
	}
	
	cout << min(min(red_right_cnt, blue_right_cnt), min(red_left_cnt, blue_left_cnt));
}