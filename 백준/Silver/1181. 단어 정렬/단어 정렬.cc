#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(string a, string b) {
	if (a.length() == b.length()) {
		return a < b;
	}
	else {
		return a.length() < b.length();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	vector <string>str;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		str.push_back(s);
	}
	sort(str.begin(), str.end(), compare);

	for (int i = 0; i < n; i++) {
		if (i != 0) {
			if (str[i] == str[i - 1]) {
				continue;
			}
		}
		cout << str[i] << "\n";
	}
}
