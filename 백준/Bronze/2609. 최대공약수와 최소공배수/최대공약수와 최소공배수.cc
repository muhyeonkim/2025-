#include <iostream>

using namespace std;
/*
유클리드 호제법
a/b = c... d
c/d = e... f
24/18 = 1 ... 6
6 / 

100 / 35 = 2 ... 30
35 / 30 = 1 .. 5
30 / 5 = 6 ... 0
두 수의 최소 공배수 : 
*/

int gcd(int a, int b) {
	while (a % b != 0) {
		if (a < b) { // b가 크면 swap
			swap(a, b);
		}
		int tmp;
		tmp = b;
		b = a % b;
		a = tmp;
	}
	return b;
}

int main() {
	int a, b;
	cin >> a >> b;
	if (a < b) { // b가 크면 swap
		swap(a, b);
	}
	cout << gcd(a, b) << "\n" << a / gcd(a, b) * b;
}