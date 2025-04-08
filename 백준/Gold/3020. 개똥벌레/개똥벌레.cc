#include <iostream>

using namespace std;

int bottom[500001];
int top[500001];

int main() {
	int n, h, cnt = 0, min_item = 200001;
	cin >> n >> h;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (i % 2 == 0) {
			bottom[x]++;
		}
		else {
			top[x]++;
		}
	}

	for (int i = h - 1; i >= 1; i--) {
		bottom[i] += bottom[i + 1];
		top[i] += top[i + 1];
	}

	for (int i = 1; i <= h; i++) {
		int item = bottom[i] + top[h - i + 1];
		if (item < min_item) { // 더 적은 장애물일 경우
			min_item = item;
			cnt = 1;
		}
		else if (item == min_item) {
			cnt++;
		}
	}

	cout << min_item << ' ' << cnt;
}