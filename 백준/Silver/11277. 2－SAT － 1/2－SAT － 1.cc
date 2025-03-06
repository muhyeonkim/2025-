#include <iostream>
#include <vector>
/*
식 f를 true로 만들 수 있으면 1 없으면 0을 출력
boolean 변수가 있다.
음수는 not을 의미한다.
절은 V(or)로 만들어져 있고 절과 절끼리는 ^(and)로 이루어져 있다.

true가 되려면 모든 절이 true가 되어야 한다.
절은 or로 되어있다.
or는 둘다 0만 아니면 된다.
1. 입력 받으면서 1이 되는 경우가 없으면 false 처리하기 ->이 경우는 괜찮지만 이 값이 다른 경우에 영향 끼치는 걸 알 수없음
2. 다 입력받고 모든 경우 다 살펴보기 ->시간 복잡도 : 2^20 -> 약 백만 가능은 함

똑같은 변수를 어떻게 똑같다고 인식할 것인가
1. pair<int,int>로 절을 저장
2. 모든 경우를 고려하기
변수 3개->8번
2^n번 해야함

*/

using namespace std;
vector<pair<int, int>>v;

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		v.push_back({ x,y });
	}

	for (int i = 0; i < (1 << n); i++) { // 2^n 번 해당 비트가 1이면 true 0이면 false
		bool isTrue = true;
		for (int j = 0; j < m; j++) {
			bool a, b;
			int x = v[j].first;
			int y = v[j].second;
			a = (x > 0) ? ((i >> (x - 1)) & 1) : !((i >> (-x - 1)) & 1);
			b = (y > 0) ? ((i >> (y - 1)) & 1) : !((i >> (-y - 1)) & 1);
			
			if ((a || b) == false) {
				isTrue = false;
				break;
			}
		}
		if (isTrue == true) {
			cout << 1;
			return 0;
		}
	}
	cout << 0;
}