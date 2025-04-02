#include <iostream>
#include <vector>
#include <algorithm>

/*
인원 m명, 입국심사대 n개, k번 심사대에서 심사하는데 걸리는 시간 Tk
심사받는데 걸리는 시간의 최솟값 출력하기
1000000000(10억)
*/

using namespace std;

int n, m;
vector<int>v;

bool isImpossible(long long mid) {
	long long cnt = 0;
	for (int i = 0; i < n; i++) {
		cnt += mid / v[i];
	}
	if (m > cnt) {  // m명을 심사할 수 없으면 false
		return false;
	}
	else { // m명이상을 심사할 수 있음
		return true; 
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	long long left = 1, right = (long long)v[0] * m, res = right;
	while (left <= right) {
		long long mid = (left + right) / 2;
		if (isImpossible(mid)) {// 해당 시간안에 모두 받을 수 있을 때 더 줄일 수 있는지 확인
			res = mid;
			right = mid - 1;
		}
		else { // 해당 시간안에 모두 못 받음, 시간 늘려야 함
			left = mid + 1;
		}
		//cout << mid << "\n";
	}
	cout << res;
}