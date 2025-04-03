#include <iostream>
#include <vector>
#include <cmath>

/*
left: 맨 왼쪽
right: 맨 오른쪽
음수면 left를 1증가 양수면 right를 1감소
*/

using namespace std; 
int arr[2];

int main() {
	int n;
	vector<int>v;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	int left = 0, right = n - 1, res = 2000000001;
	while (left < right) {
		int sum = v[left] + v[right];
		if (abs(res) > abs(sum)) {
			res = sum;
			arr[0] = v[left], arr[1] = v[right];
		}
		if (sum >= 0) { 
			right--;
		}
		else {
			left++;
		}
	}
	cout << arr[0] << ' ' << arr[1];
}