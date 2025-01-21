#include <iostream>
#include <unordered_map>

using namespace std;
/*
map에 사이트,비밀 번호를 넣는다.
원하는 사이트를 입력하면 find함수를 사용해서 비밀 번호를 찾는다.
*/
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n, m;
	unordered_map<string, string>um;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s1, s2;
		cin >> s1 >> s2;
		um.insert({ s1,s2 });
	}

	for (int i = 0; i < m; i++) {
		string s;
		cin >> s;
		cout << um.find(s)->second << "\n";
	}
}