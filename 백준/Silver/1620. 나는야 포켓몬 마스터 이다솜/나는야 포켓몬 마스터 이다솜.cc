#include <iostream>
#include <string>
#include <unordered_map>

/*
1번부터 n번까지 포켓몬을 등록한다.

m번 개의 줄에서 포켓몬 번호 혹은 포켓몬 이름을 입력한다. 이에 해당하는 포켓몬 이름 혹은 번호를 출력한다.

*/

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	unordered_map<string, int>um1;
	unordered_map<int, string>um2;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		um1.insert({ s, i });
		um2.insert({ i, s });
	}
	for (int i = 0; i < m; i++) {
		string s;
		cin >> s; 
		if (s[0] <= '9') { // 포켓몬 번호가 들어오는 경우
			int a = stoi(s);
			cout << um2.find(a)->second << "\n";
		}
		else {
			cout << um1.find(s)->second << "\n";
		}
	}
	
}