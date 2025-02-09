#include <iostream>
#include <string>

using namespace std;

/*
1. pn은 I+OI*n이다. 
2. 현재 위치와 그다음이 OI인지 확인한다.OI가 맞으면 tmp에 추가, 아니면 tmp를 초기화 한다.
3. p와 tmp가 동일하면 cnt를 증가한다.

*/
int main() {
	int n, m, cnt = 0;
	string s;
	cin >> n >> m >> s;

	for (int i = 0; i < m; i++) {
		int len = 0;
		if (s[i] == 'O') continue;
		else {
			while (s[i + 1] == 'O' && s[i + 2] == 'I') {
				len++;
				if (len == n) {
					cnt++;
					len--;
				}
				i += 2;
			}
		}
	}
	cout << cnt;
}