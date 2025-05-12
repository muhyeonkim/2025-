#include <iostream>
#include <cmath>

/*
주어진 자연수를 제곱수의 합으로 나타내는 최소 항의 개수
이전 수에서 1더한 수 vs 어떤 제곱수를 더한 수
*/

int num[100001];

using namespace std;

int main() {
	int n, tmp = 1;
	cin >> n;

	for (int i = 1; i <= sqrt(n); i++) {
		num[i * i] = 1; // 제곱수 설정
	}

	for (int i = 2; i <= n; i++) {
		int tmp = 10000;
		for (int j = 2; j <= sqrt(i); j++) {
			tmp = min(tmp, num[i- j * j]); //i보다 작은 수 중에서 제곱 수를 뺏을 때 가장 작은 수
		}
		num[i] = min(num[i - 1] + 1, tmp + 1);
	}
	cout << num[n];
}