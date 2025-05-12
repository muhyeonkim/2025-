#include <iostream>
#include <string>

/*
4*1000000
*/
using namespace std;

int prime[10000001];

bool isPalindrome(int x) {
	string s;
	s = to_string(x);
	for (int i = 0; i < s.length() / 2; i++) {
		if (s[i] != s[s.length() - 1 - i]) {
			return false;
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i <= 10000000; i++) {
		prime[i] = i;
	}

	for (int i = 2; i <= 10000; i++) { // 소수 생성
		if (prime[i] == 0) continue;
		for (int j = i * i; j <= 10000000; j += i) {
			prime[j] = 0;
		}
	}
	if (n == 1) {
		cout << 2;
		return 0;
	}
	for (int i = n; i <= 10000000; i++) {
		if (prime[i] != 0 && isPalindrome(i) == true) {
			cout << i;
			return 0;
		}
	}
}