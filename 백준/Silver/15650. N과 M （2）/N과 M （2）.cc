#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int>num;
void com(int prev);

int main() {
	cin >> n >> m;
	com(0);
}

void com(int prev) {
	if (num.size() == m) {
		for (int a : num) {
			cout << a << ' ';
		}
		cout << "\n";
		return;
	}

	for (int i = prev+1; i <= n; i++) {
		num.push_back(i);
		com(i);
		num.pop_back();
	}
}