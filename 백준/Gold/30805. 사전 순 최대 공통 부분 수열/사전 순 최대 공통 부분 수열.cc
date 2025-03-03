#include <iostream>
#include <vector>

/*
A와 B를 입력 받는다.
A에서 가장 큰 숫자를 찾는다.
B에 있는지 확인한다.
있다면 그 숫자가 있는 위치의 다음 인덱스부터 탐색을 다시한다.
없다면 처음부터 다시 찾는다.
A의 끝에 왔다면 종료한다.
가장 큰 숫자들을 출력한다.

*/
using namespace std;


int main() {
	int n, m;
	vector<int>v1;
	vector<int>v2;
	vector<int>res;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v1.push_back(x);
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		v2.push_back(x);
	}
	int idx1 = 0, idx2 = 0;
	while (idx1!=v1.size()) {
		int max_value = 0;
		bool isTrue = false;
		int tmp1 = idx1, tmp2 = idx2;
		
		for (int i = tmp1; i < v1.size(); i++) {
			if (max_value < v1[i]) {
				max_value = v1[i];
				idx1 = i + 1;
			}
		}
		
		for (int i = tmp2; i < m; i++) {
			if (max_value == v2[i]) {
				res.push_back(v2[i]);
				idx2 = i + 1;
				isTrue = true;
				break;
			}
		}
		if (isTrue == false) { //A값이 B에 없을 때
			v1.erase(v1.begin() + idx1 - 1);
			idx1 = tmp1;
		}
	}
	cout << res.size() << "\n";
	for (auto a : res) {
		cout << a << ' ';
	}
}