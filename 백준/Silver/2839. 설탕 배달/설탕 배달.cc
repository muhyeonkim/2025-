#include <iostream>

using namespace std;
/*
n을 3,5로 나눔, 가장 적은 봉지 수는? 
3을 계속 빼다가 5로 나눌 수 있으면 그때 몫을 cnt에 더하기
*/
int main() {
	int n, cnt = 0;
	cin >> n;
	while (n % 5 != 0) {
		n -= 3;
		cnt++;
	}
	if (n < 0) cout << -1;
	else cout << cnt + n / 5;
}