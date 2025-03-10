#include <iostream>

using namespace std;

int gcd(int x, int y) {
	if (x < y) swap(x, y);
	while (y != 0) {
		int tmp = x;
		x = y;
		y = tmp % y;
	}
	return x;
}
int lcm(int x, int y) {
	return x * y / gcd(x, y);
}

int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int upper, lower;
	lower = lcm(b, d);
	upper = (b * c + a * d) / gcd(b, d);
	cout << upper / gcd(upper, lower) << ' ' << lower / gcd(upper, lower);
}