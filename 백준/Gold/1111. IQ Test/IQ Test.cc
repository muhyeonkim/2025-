#include <iostream>

/*
A: 다음 수가 여러 개일 때 : n이 1 일때, n이 2이고 두 수가 같을 때를 제외한 모든 경우
B: 다음 수를 구할 수 없을 때 : a,b가 변할 때
나머지 : 규칙에 맞는 다음 수가 있을 때 그 이외의 경우

*/

using namespace std;

int arr[51];

int main() {
	bool isTrue = true;
	int n, a = 0, b = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	if (n >= 3) {
		if (arr[1] == arr[0] && arr[1] == arr[2]) a = 1, b = 0;
		else if (arr[1] == arr[0] && arr[1] != arr[2]) {
			cout << 'B';
			return 0;
		}
		else if (arr[1] != arr[0] && arr[1] == arr[2]) {
			a = 0;
			b = arr[1];
		}
		else if ((arr[2] - arr[1]) % (arr[1] - arr[0]) != 0) {
			cout << 'B';
			return 0;
		}
		else {
			a = (arr[2] - arr[1]) / (arr[1] - arr[0]);
			b = arr[1] - arr[0] * a;
		}
	}
	
	for (int i = 3; i < n; i++) {
		if (arr[i] != arr[i - 1] * a + b) { //구한 a,b가 안먹힐 때
			isTrue = false;
			break;
		}
	}
	//cout << a << ' ' << b << "\n";
	if (n == 1) cout << 'A'; // 
	else if (n == 2 && arr[0] != arr[1]) cout << 'A'; // n이 2이고 두 수가 같지 않을 때
	else if (n == 2 && arr[0] == arr[1]) cout << arr[0]; // n이 2이고 두 수가 같을 때
	else if (isTrue == false) cout << 'B';
	else cout << arr[n - 1] * a + b;
}