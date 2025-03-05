#include <iostream>

using namespace std;




int main() {
	int t;
	cin >> t;
	while (t--) {
		double d, r;
		double x1, y1, r1, x2, y2, r2;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		d = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2); //두 점 사이의 거리의 제곱
		r = (r1 - r2) * (r1 - r2);
		if (d == 0 && r1 == r2) { // 두 원이 겹칠 때
			cout << -1 << "\n";
		}
		else if (d > (r1 + r2) * (r1 + r2)) { // 두 원이 만나지 않을 때
			cout << 0 << "\n";
		}
		else if (d < (r1 - r2) * (r1 - r2)) { // 한 원이 다른 원 안에 있을 때
			cout << 0 << "\n";
		}
		else if (d == (r1 + r2) * (r1 + r2)) { // 외접할 때
			cout << 1 << "\n";
		}
		else if (d == (r1 - r2) * (r1 - r2)) { // 내접할 때
			cout << 1 << "\n";
		}
		else { // 교점이 두 개 일 때
			cout << 2 << "\n";
		}
	}
}