#include <iostream>
#include <vector>
#include <algorithm>

/*
배정된 예산들 중 최댓값 출력
모든 요청이 배정될 수 있는 경우에는 요쳥한 금액을 그대로 배정
모든 요청이 배정될 수 없는 경우는 특정한 정수 상한액을 계산해서 그 이상은 상한액을 배정, 그 이하는 요청한 금액 그대로 배정

최소 금액 : 제일 작은 예산
최대 금액 : 제일 큰 예산
최소 최대로 구한 임시 상한액으로 구한 전체 예산과 전체 금액 비교
*/

using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int n, total, res = 0;
	vector<int>v;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	cin >> total;
	sort(v.begin(), v.end());
	int left = 0, mid, right = v[n - 1];
	while (left <= right) {
		int sum = 0;
		int mid = (left + right) / 2;
		for (int i = 0; i < n; i++) {
			if (mid >= v[i]) {
				sum += v[i];
			}
			else {
				sum += mid;
			}
		}
		if (total >= sum) { // 예산을 더 배정해도 됨
			res = max(res, mid);
			left = mid + 1;
		}
		else { // 예산을 줄여야 함
			right = mid - 1;
		}
	}
	cout << res;
}