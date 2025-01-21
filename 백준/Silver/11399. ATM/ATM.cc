#include <iostream>
#include <vector>
#include <algorithm>
/*
오름 차순으로 하면 0번 원소를 1번, 마지막 원소를 n번 더하게 된다.
따라서 오름 차순이 아닌 내림차순으로 정렬해서 더한다.
혹은 오름 차순으로 정렬 후 역방향으로 더한다.
*/
using namespace std;

int main() {
	int n, sum = 0;
	vector<int>v;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int p;
		cin >> p;
		v.push_back(p);
	}

	sort(v.begin(), v.end(), greater<>());
	

	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			sum += v[j];
		}
	}
	cout << sum;
}