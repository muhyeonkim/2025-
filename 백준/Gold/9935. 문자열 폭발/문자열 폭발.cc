#include <iostream>
#include <string>
#include <stack>
using namespace std;

/*
c
*/

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s1, s2, res, tmp;
	cin >> s1 >> s2;
	for (int i = 0; i < s1.length(); i++) {
		if (s2.find(s1[i]) != string::npos) { // s2중에 해당 단어가 있으면
			tmp.push_back(s1[i]);
		}
		else {
			tmp = "";
		}
		res.push_back(s1[i]);
		if (tmp.length() >= s2.length()) {
			bool isSame = true;
			for (int i = 0;i<s2.length();i++) {
				if (tmp[i+tmp.length()-s2.length()] != s2[i]) {
					isSame = false;
				}
			}
			if (isSame == true) {
				for (int i = 0; i < s2.length(); i++) {
					res.pop_back();
					tmp.pop_back();
				}
			}
		}
	}
	if (res == "")
		cout << "FRULA";
	else
		cout << res;
}