#include <iostream>
#include <algorithm>
#include <vector>

/*
서로 다른 l개의 알파벳 소문자로 구성, 최소 한 개의 모음과 최소 두개의 자음으로 구성
기본 백트래킹(모든 경우를 다 살펴보는)에서 모음 자음 조건 포함한 백트래킹을 완성하기
*/

using namespace std;

vector<char>v;
vector<char>res;
int l, c;

void backtracking(int idx, int cnt, int mo_cnt, int ja_cnt) {
	if (cnt == l) { //최소한의 조건(모음1개, 자음2개)만족한 경우만 출력하기
		if (mo_cnt >= 1 && ja_cnt >= 2) {
			for (auto ch : res) {
				cout << ch;
			}
			//cout << ' ' << mo_cnt << ' ' << ja_cnt;
			cout << "\n";
		}

		return;
	}
	else {
		for (int i = idx; i < c; i++) {
			res.push_back(v[i]);
			if (v[i] == 'a' || v[i] == 'e' || v[i] == 'i' || v[i] == 'o' || v[i] == 'u') {
				backtracking(i + 1, cnt + 1, mo_cnt+1, ja_cnt);
			}
			else {
				backtracking(i + 1, cnt + 1, mo_cnt, ja_cnt+1);
			}
			res.pop_back();
		}
	}
}

int main() {
	cin >> l >> c;
	for (int i = 0; i < c; i++) {
		char ch;
		cin >> ch;
		v.push_back(ch);
	}
	sort(v.begin(), v.end());
	backtracking(0,0, 0, 0);
}