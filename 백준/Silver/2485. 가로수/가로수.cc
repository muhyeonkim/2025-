#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int x, int y) {
	if (x < y) swap(x, y);
	while (x % y != 0) {
		int tmp = x;
		x = y;
		y = tmp % y;
	}
	return y;
}

int main() {
	int n, x, y, sum = 0, cnt = 0;
	vector <int>v;
	vector <int>dist;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	for (int i = 1; i < n; i++) {
		x = v[i - 1], y = v[i];
		dist.push_back(y - x);
	}
	int res = gcd(dist[0], dist[1]);
	for (int i = 2; i < dist.size(); i++) {
		res = gcd(res, dist[i]);
	}
	sum = v[0] + res;
	//cout << res;
	for (int i = 1; i < n; sum += res) {
		if (v[i] == sum) {
			i++;
			continue;
		}
		else {
			//cout << sum << ' ';
			cnt++;
		}
	}
	cout << cnt;
}