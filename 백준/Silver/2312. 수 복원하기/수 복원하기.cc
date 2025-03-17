#include <iostream>
#include <cstring>
/*
양의 정수 입력
해당 숫자가 1이될 때 까지 인수로 나누기
1이 되면 인수들 출력하기

해당 숫자를 나눌 인수를 구하기 (o)

*/

int prime[100001];
int arr[100001];

using namespace std;

int main() {
	int n;
	cin >> n;

	for (int i = 2; i <= 100000; i++) {
		prime[i] = i;
	}
	for (int i = 2; i <= 1000; i++) {
		for (int j = 2 * i; j <= 100000; j += i) {
			prime[j] = 0;
		}
	}

	for (int i = 0; i < n; i++) {
		int x, idx = 2;
		cin >> x;
		while (x != 1) {
			if (prime[idx] != 0) {
				if (x % prime[idx] == 0) {//해당 인수로 나눌 수 있으면 나누기
					x = x / prime[idx];
					arr[idx]++;
				}
				else idx++; // 해당 인수로 나눌 수 없으면 다음 소수를 찾으러 가기
			}
			else idx++; // 해당 숫자가 소수가 아니면 다음 소수를 찾으러 가기
		}
		for (int i = 2; i <= 100000; i++) {
			if (arr[i] != 0) cout << i << ' ' << arr[i] << "\n";
		}
		memset(arr, 0, sizeof(arr));
	}
}