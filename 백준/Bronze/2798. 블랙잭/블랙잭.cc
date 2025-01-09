#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, m, ans = 0;
	vector <int> vec;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		vec.push_back(a);
	}
	for (int i = 0; i < n; i++) {
		int a, b, c;
		a = vec[i];
		for (int j = i+1; j < n; j++) {
			b = vec[j];
			for (int k =j+1; k < n; k++) {
				c = vec[k];
				if (a + b + c <= m && a + b + c >= ans) {
					ans = a + b + c;
				}
			}
		}
	}
	cout << ans;
}