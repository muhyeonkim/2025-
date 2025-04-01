#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int>v;

bool isPossible(int mid) {
	int sum = mid, cnt = 1;
	for (int i = 0; i < n; i++) {
		if (sum < v[i]) { // 새로 인출해야하는 경우
			sum = mid;
			cnt++;
		}
		sum -= v[i];
	}
	if (cnt > m) return false;
	else return true;
}

int main() {
	int sum = 0, max_money = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
		sum += x;
		max_money = max(max_money, x);
	}
	int left = max_money, right = sum, res = 0;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (isPossible(mid)) { //m이하로 인출할 수 있는 경우
			res = mid;
			right = mid - 1;
		}
		else { // 더 많이 인출해야하는 경우
			left = mid + 1;
		}
	}
	cout << res;
}