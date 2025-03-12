#include <iostream>
#include <cstring>

/*
골드바흐의 추측 : 2보다 큰 짝수는 두 소수의 합으로 나타낼 수 있다.
골드바흐 파티션의 개수를 구하기
소수 구해놓기 그 다음에
2개씩 골라서 되는지 확인하기
80000

*/

using namespace std;

bool prime[1000001];

int goldbach(int x) {
	int cnt = 0;
	for (int i = 2; i <= x / 2; i++) { // 절반까지만 확인
		if (prime[i] && prime[x - i]) {
			cnt++;
		}
	}
	return cnt;
}

int main() {
	
	memset(prime, 1, sizeof(prime));

	for (int i = 2; i * i <= 1000000; i++) {
		if (prime[i] == false)  continue;
		for (int j = 2 * i; j <= 1000000; j += i) {
			prime[j] = 0;
		}
	}

	int t;
	cin >> t;
	
	while (t--) {
		int n;
		cin >> n;
		cout << goldbach(n) << "\n";
	}
}