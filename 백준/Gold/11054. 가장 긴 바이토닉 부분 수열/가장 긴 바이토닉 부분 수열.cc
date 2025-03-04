#include <iostream>
#include <vector>
#include <algorithm>
/*
양 옆으로 가장 긴 증가하는 수열을 찾는다.
각 경우에서 가장 긴 수열의 인덱스에서 가장 긴 감소하는 수열을 찾는다.
둘 중 더 큰 값을 정한다.

가장 긴 증가하는 수열은 어떻게?


*/

using namespace std;

int LIS[1001];
int LDS[1001];
int arr[1001];

int main() {
	int n, res = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) {
				LIS[i] = max(LIS[i], LIS[j] + 1);
			}
		}
	}

	for (int i = n - 1; i >= 0; i--) {
		for (int j = n - 1; j > i; j--) {
			if (arr[i] > arr[j]) {
				LDS[i] = max(LDS[i], LDS[j] + 1);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		res = max(res, LIS[i] + LDS[i]);
	}
	cout << res + 1;
}