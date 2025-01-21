#include <iostream>
#include <vector>
using namespace std;

/*
1. 배열에 동전 종류를 담는다.
2. 배열의 뒤에서 부터 확인한다.
k보다 동전의 가치가 더 크면 이전 원소로 넘어간다.
k보다 동전의 가치가 같거나 작으면 커질 때 까지 동전의 가치를 뺀다.
이를 k가 0원이 될 때 까지 반복한다.
*/

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k, cnt = 0;
	vector<int>v;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}

	for (int i = n - 1; i >= 0; i--) {
		while (k >=v[i]) {
			k -= v[i];
			cnt++;
		}
	}
	cout << cnt;
}