#include <iostream>
#include <vector>
#include <algorithm>

/*
"두 공유기 사이의 거리 𝑑라 할 때
d 이상을 유지하면서 C개의 공유기를 설치할 수 있는가?"
1,000,000,000
*/
using namespace std;

int n, c;

int main() {
	vector<int>v;
	cin >> n >> c;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	int low = 1, mid = 0, high = v[n - 1] - v[0], res = 0;
	while (low <= high) {
		mid = (low + high) / 2;
		int last = v[0], cnt = 1;
		for (int i = 1; i < n; i++) {
			if (v[i] - last >= mid) { //현재 정해 놓은 거리랑 같거나 긴 거리안에 설치할 수 있으면
				cnt++;
				last = v[i];
			}
		}
		if (c <= cnt) { //c개 이상 설치 가능할 때 거리 더 늘릴 수 있는 지 확인
			res = max(res, mid);
			low = mid + 1;
		}
		else { //c개 이상 설치가 안되면 거리를 줄인다.
			high = mid - 1;
		}
	}
	cout << res;
}