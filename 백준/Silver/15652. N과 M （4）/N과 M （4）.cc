#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int>num;
void com(int prev);

int main() {
	cin >> n >> m;
	com(1);
}

void com(int prev) {
	if (num.size() == m) {
		for (int a : num) {
			cout << a << ' ';
		}
		cout << "\n";
		return;
	}

	for (int i = prev; i <= n; i++) {
		num.push_back(i);
		com(i);
		num.pop_back();
	}
}