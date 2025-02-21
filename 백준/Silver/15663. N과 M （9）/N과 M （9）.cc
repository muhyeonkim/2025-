#include <iostream>
#include <vector>
#include <algorithm>

/*
배열에는 크기 순으로 있다.
중복된 수열이 있으면 안된다.
배열에는 중복된 숫자가 있을 수 있다.

*/

using namespace std;

vector<int>v;
vector<int>v2;
bool isvisited[10];
int n, m;

void backtracking(int cnt) {
	if (cnt == m) {
		for (int a : v2) {
			cout << a << ' ';
		}
		cout << "\n";
		return;
	}
	int tmp = 0;
	for (int i = 0; i < n; i++) {
		if (isvisited[i] == 1||tmp==v[i])
			continue;
		v2.push_back(v[i]);
		isvisited[i] = 1;
		tmp = v[i];
		backtracking(cnt + 1);
		v2.pop_back();
		isvisited[i] = 0;
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	backtracking(0);
}