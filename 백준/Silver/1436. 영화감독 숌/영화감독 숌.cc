#include <iostream>
#include <vector>
using namespace std;

/*
숫자를 하나 씩 증가시킨다.
666이 있는지 확인한다.->?
n번 째 숫자를 출력한다.

  666이 있는지 확인한다
->숫자를 분리시킨다.
->분리시킨 숫자들을 배열에 담는다.
->3번 연속인지 확인한다.
*/

bool check(int n) {
	vector<int>tmp;
	while (n != 0) {
		tmp.push_back(n % 10);
		n /= 10;
	}

	for (int i = 2; i < tmp.size(); i++) {
		if (tmp[i] == 6 && tmp[i - 1] == 6 && tmp[i - 2] == 6) {
			return true;
		}
	}
	return false;
}

int main() {
	int n, num = 1, cnt = 0;
	cin >> n;
	while (1) {
		if (check(num)) cnt++;
		if (cnt == n) break;
		num++;
	}
	cout << num;
}