#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int>v;
vector<int>v2;
bool vistied[10];
int n, m;

void backtracking(int cnt,int idx) {
	if (cnt == m) {
		for (auto a : v2) {
			cout << a << ' ';
		}
		cout << "\n";
		return;
	}
	for (int i = idx; i < n; i++) {
		if (vistied[i] == true)
			continue;
		v2.push_back(v[i]);
		vistied[i] = true;
		backtracking(cnt + 1, idx);
		v2.pop_back();
		vistied[i] = false;
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
	backtracking(0, 0);
}