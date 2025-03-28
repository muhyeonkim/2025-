#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	long long int n, sum = 0;
	vector<int>v;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++) {
		for (int j = n - i - 1; j >= 0; j--) {
			sum += v[j];
		}
	}
	cout << sum;
}