#include <iostream>
#include <vector>
/*
n명의 스태프가 m개의 풍선을 만드는 최소 시간
풍선 제조 시간 입력
정렬
left = 0, right =m
mid =left+right
가장 오래 걸리는 시간 * mid
해당 시간동안 각 스태프가 만들 수 있는 풍선 더하기
풍선 개수가 m보다 크면 right = mid-1
풍선 개수가 m보다 작으면 left = mid+1
*/

using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n, m;
	vector <long long> v;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		long long x;
		cin >> x;
		v.push_back(x);
	}
	long long left = 0, right = 1000000000000;
	long long res = 0;
	while (left <= right) {
		long long mid = (left + right) / 2;
		long long cnt = 0;
		for (int i = 0; i < n; i++) {
			cnt += mid / v[i];
		}
		if (cnt >= m) {
			res = mid;
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	cout << res;
}