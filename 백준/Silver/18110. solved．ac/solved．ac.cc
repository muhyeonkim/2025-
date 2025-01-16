#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
/*
n개의 의견을 받는다.
그중 상위 15%,하위 15%의 의견은 받지 않는다.
사람 수가 소숫점인 경우는 반올림을 한다.
평균을 계산한다.
평균 값을 반올림 한다.

*/
using namespace std;

int main() {
	int n;
	double del = 0, sum = 0, total = 0;
	vector<int>v;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	del = round(n * 0.15);
	for (int i = del; i < n - del; i++) {
		sum += v[i];
	}
	total = n - (2 * del);
	if (n == 0) cout << 0;
	else cout << round(sum / total);
}