#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
/*
난이도 계산하기
아무 의견이 없으면 난이도는 0
하나 이상의 의견이 있다면 모든 사람의 난이도 의견의 상위 15%, 하위 15%는 제외
제외되는 사람의 수는 반올림
계산된 평균도 반올림

정렬
15%가 얼마인지 계산
평균 계산
*/

using namespace std;

int main() {
	int n, sum = 0, ex = 0;
	vector<int>v;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	for (int i = round(0.15 * n); i < n - round(0.15 * n); i++) {
		sum += v[i];
	}
	if (n == 0) cout << 0;
	else cout << round(sum / (n - (round(0.15 * n) + round(0.15 * n))));
}