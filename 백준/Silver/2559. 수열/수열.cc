#include <iostream>
#include <climits>
#include <vector>

using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	int n, k;
	vector<int>v;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	int left = 0, sum = 0, max_temp = INT_MIN, length = 0;
	for (int right = 0; right < n; right++) {
		sum += v[right];
		length++;
		if (length == k) {
			//cout << sum << "\n";
			max_temp = max(max_temp, sum);
			sum -= v[left];
			left++;
			length--;
		}
	}
	cout << max_temp;
}