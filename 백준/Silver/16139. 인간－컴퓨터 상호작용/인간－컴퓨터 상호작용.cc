#include <iostream>

/*
문자열에서 특정 알파벳이 몇 번 나타나는지 알아봐서
자주 나타나는 알파벳이 중지나 검지 위치에 오는 알파벳인지 확인
l번째 문자부터 r번째 문자 사이에 a가 나타나는 횟수 출력
누적 합 : s[i]는 0번부터 i-1번째 원소까지의 합
*/

using namespace std;

int arr[200001][26];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	int q;
	cin >> s >> q;
	for (int i = 0; i < s.length(); i++) {
		for (int j = 0; j < 26; j++) {
			arr[i + 1][j] = arr[i][j];
		}
		arr[i + 1][s[i] - 'a']++;
	}

	for (int i = 0; i < q; i++) {
		char a;
		int l, r;
		cin >> a >> l >> r;
		cout << arr[r+1][a - 'a'] - arr[l][a - 'a'] << "\n";
	}

}