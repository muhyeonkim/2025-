#include <iostream>

using namespace std;

int arr[10001];

void post(int start,int end) {
	if (start >= end) return;

	int idx = start + 1;

	while (idx < end) {
		if (arr[start] < arr[idx]) {
			break;
		}
		idx++;
	}
	post(start + 1, idx);
	post(idx, end);
	cout << arr[start] << "\n";
}

int main() {
	int num;
	int idx = 0;
	while (cin >> num) {
		arr[idx++] = num;
	}
	post(0, idx);
	
}