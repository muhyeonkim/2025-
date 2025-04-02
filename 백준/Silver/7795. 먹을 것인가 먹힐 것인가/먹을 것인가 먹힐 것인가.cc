#include <iostream>
#include <vector>
#include <algorithm>
/*
두 종류의 생명체 A와 B가 있다.
A는 B를 먹는다.
A는 자기보다 크기가 작은 먹이만 먹을 수 있다.
A의 크기가 B보다 큰 쌍의 개수를 출력(A가 먹을 수 있는 쌍의 수)
*/

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		vector<int>a;
		vector<int>b;
		int n, m, cnt = 0;
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			a.push_back(x);
		}
		for (int i = 0; i < m; i++) {
			int x;
			cin >> x;
			b.push_back(x);
		}
		sort(a.begin(), a.end()); //오름차순 정렬
		sort(b.begin(), b.end()); //오름차순 정렬
		int right = 0;
		for (int left = 0; left < n; left++) {
			while (right < m && b[right] < a[left]) {
				right++;
			}
			cnt += right;
		}
		cout << cnt << "\n";
	}
}
