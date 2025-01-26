#include <iostream>
#include <queue>

using namespace std;
int n, c;
bool com[101][101];
bool inf[101];

void func() {
	int cnt = 0;
	queue<int>q;
	q.push(1);
	while (!q.empty()) {
		int num = q.front();
		q.pop();
		for (int i = 1; i <= n; i++) {
			if (com[num][i] == 1 && inf[i] != 1) {
				inf[i] = 1;
				q.push(i);
				cnt++;
			}
		}
	}
	cout << cnt;
}


int main() {
	cin >> n >> c;
	inf[1] = 1;
	for (int i = 0; i < c; i++) {
		int a, b;
		cin >> a >> b;
		com[a][b] = 1;
		com[b][a] = 1;
	}

	func();
}