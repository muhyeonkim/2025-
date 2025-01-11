#include <iostream>

using namespace std;

/*
앞에서 부터 n/2번
뒤에서 부터 n/2번
배열에 담기
*/

int main() {
	string s;
	while (cin >> s && s != "0") {
		bool prob = true;
		for (int i = 0; i < s.length() / 2; i++) {
			if (s[i] != s[s.length() - 1 - i]) {
				prob = false;
			}
		}
		if (prob == true) {
			cout << "yes\n";
		}
		else
			cout << "no\n";
	}
}