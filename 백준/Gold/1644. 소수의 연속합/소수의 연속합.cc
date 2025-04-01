#include <iostream>
#include <vector>
/*

*/
using namespace std;

int prime[4000001];

int main() {
	int n, cnt = 0;
	vector<int>v;
	cin >> n;
	if (n == 1) {
		cout << 0;
		return 0;
	}
	else if (n == 2) {
		cout << 1;
		return 0;
	}
	for (int i = 2; i <= 4000000; i++) {
		prime[i] = i;
	}

	for (int i = 2; i <= 2000; i++) {
		if (prime[i] == 0) continue;
		for (int j = i * i; j <= 4000000; j += i) {
			prime[j] = 0;
		}
	}
	for (int i = 2; i <= n; i++) {
		if (prime[i] != 0) v.push_back(i);
	}

	int left = 0, sum = v[left];
	for (int right = 1; right < v.size(); right++) {
		if (sum < n) {
			sum += v[right];
		}
		while (sum >= n) {
			if (sum == n) cnt++;
			sum -= v[left];
			left++;
		}
		
		//cout << sum << ' ';
	}
	
	cout << cnt;
}