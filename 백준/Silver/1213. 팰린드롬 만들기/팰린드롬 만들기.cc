#include <iostream>

/*
영어 이름을 알파벳 순서를 적절히 바꿔서 회문으로 만들어 출력
만들 수 없다면 I'm Sorry Hansoo 출력
적절히 바꿔서 회문을 만들 수 있는 조건 : 홀수 개의 알파벳이 1개 이하
영어 이름을 입력받는다.
알파벳의 개수를 센다.
홀수 개의 알파벳이 1개이하인지 확인한다.
초과한다면 불가능하다는 문구 출력
1개라면 일단 사전순으로 절반을 출력 1개인 알파벳을 가운데, 나머지를 회문에 맞춰 출력
0개면 이전 과정에서 알파벳 가운데 넣는거 제외하고 구현
*/


int arr[26];

using namespace std;

int main() {
	string s, res = "";
	int odd_cnt = 0;
	char odd_alpha = ' ';
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		arr[s[i] - 'A']++;
	}

	for (int i = 0; i < 26; i++) {
		if (arr[i] % 2 == 1) {
			odd_cnt++;
			odd_alpha = char('A' + i);
			arr[i]--;
		}
	}

	if (odd_cnt > 1) { 
		cout << "I'm Sorry Hansoo"; 
		return 0;
	}
	else { // 회문이 가능한 경우
		for (int i = 0; i < 26; i++) {
			if (arr[i] % 2 == 0 && arr[i] != 0) {
				for (int j = 0; j < arr[i] / 2; j++) {
					res += char('A' + i);
				}
			}
		}
	}
	cout << res;
	if (odd_alpha != ' ') { // 홀수인 알파벳이 있을 때
		cout << odd_alpha;
	}

	for (int i = res.length() - 1; i >= 0; i--) {
		cout << res[i];
	}
}