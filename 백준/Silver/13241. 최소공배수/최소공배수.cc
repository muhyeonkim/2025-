#include <iostream>
#include <algorithm>

/*
두 수의 최소 공배수는 최대 공약수로 나누고 남은 수와 최대 공약수 곱하기


*/
using namespace std;

long long int gcd(long long int x, long long int y) {
	if (x < y) {
		swap(x, y);
	}

	while (y != 0) {
		long long int tmp = x;
		x = y;
		y = tmp % y;
	}
	return x;
}

long long int lcm(long long int x, long long int y) {
	return x * y / gcd(x, y);
}

int main() {
	long long int a, b;
	cin >> a >> b;
	cout << lcm(a, b) << "\n";
}