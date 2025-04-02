#include <iostream>
#include <vector>
#include <algorithm>
/*
n개의 캐릭터, 각 캐릭터의 레벨은 xi, 최대 총합 k만큼 올릴 수 있다.
팀 목표레벨이 T=min(xi)일때, 최대 팀 목표레벨 T를 출력하기
*/

using namespace std;

int n, k;
vector<int>v;

bool isimpossible(int mid) {
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		if (mid > v[i]) { // 해당 원소가 팀 목표레벨(mid)보다 레벨이 낮을 경우 해당 레벨까지 올리기
			sum += mid - v[i];
		}
		if (sum > k) {
			return false;
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	int left = v[0], right = k + v[n - 1], res = 0;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (isimpossible(mid)) { // mid가 가능하면 mid를 더 올리기
			res = mid;
			left = mid + 1;
		}
		else { //k안에 불가능하면 mid를 더 줄이기 
			right = mid - 1;
		}
	}
	cout << res;
}