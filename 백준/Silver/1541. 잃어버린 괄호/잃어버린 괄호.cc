#include <iostream>
#include <queue>
#include <string>
using namespace std;

/*
1.숫자와 연산자 분리
2.-가 나오면 다음 -나올 때 까지 해당 계산식을 괄호로 묶는게 가장 작다?
a-(b+c)-d-e
a-(b+c+d)-e-f
-가 나오기 전까지는 그냥 더하기
-가 나오기 시작하면 더한 결과를 따로 빼두기

*/

int main() {
	string s, tmp = "";
	queue<int>iv;
	queue<char>cv;
	queue<int>result;
	int n = 0;
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] >= '0') {
			tmp += s[i];
		}
		else {
			iv.push(stoi(tmp));
			cv.push(s[i]);
			tmp = "";
		}
	}
	iv.push(stoi(tmp));
	/*while (!iv.empty()) {
		cout << iv.front() << ' ';
		iv.pop();
	}
	while (!cv.empty()) {
		cout << cv.front() << ' ';
		cv.pop();
	}*/
	n = iv.front();
	iv.pop();
	while (!iv.empty()) {
		char c = cv.front();
		cv.pop();
		if (c == '+') {
			n += iv.front();
			iv.pop();
		}
		if (c == '-') {
			result.push(n);
			n = iv.front();
			iv.pop();
		}
	}
	result.push(n);

	n = result.front();
	result.pop();

	while (!result.empty()) {
		n -= result.front();
		result.pop();
	}
	cout << n;
}
