#include <iostream>

using namespace std;

int main() {
	int n, m, cnt = 0;
	string s, p = "I";
	cin >> n >> m >> s;
	for (int i = 0; i < n; i++) {
		p += "OI";
	}

	for (int i = 0; i < m-p.length()+1; i++) {
		string tmp = "";
		for (int j = 0; j < p.length(); j++) {
			tmp += s[i+j];
		}
		if (tmp == p) cnt++;
	}
	cout << cnt;
}