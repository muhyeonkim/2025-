#include <iostream>
#include <vector>
#include <algorithm>

/*
n개의 수가 주어진다.
이중 두 개를 골라서 다른 수를 만들 수 있으면 그 수는 좋은 수이다.
좋은 수의 개수를 출력하기
배열 속 원소를 하나 고른다.
해당 원소가 좋은 수인지 확인하기 위해 투포인터를 사용한다.
해당 방법으로 모든 원소를 탐색한다.
*/
using namespace std;

int n;
vector<int>v;
int main() {
	int cnt = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++) {
		int left = 0, right = n - 1;
		while (left < right) {
			if (left == i) {
				left++;
				continue;
			}
			if (right == i) {
				right--;
				continue;
			}
			int sum = v[left] + v[right];
			if (sum == v[i]) {
				cnt++;
				break;
			}
			else if (sum > v[i]) { // sum을 줄여야할 경우
				right--;
			}
			else if (sum < v[i]) { //sum을 키워야할 경우
				left++;
			}
		}
	}
	cout << cnt;
}