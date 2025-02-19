#include <iostream>
#include <queue>

using namespace std;

vector<int>map(100001, 100001);
int n, k;

bool isOutofLine(int x) {
	if (x >= 0 && x <= 100000) {
		return true;
	}
	else
		return false;
}

void bfs(int x) {
	queue<int>q;//좌표, 시간
	map[x] = 0;
	q.push(x);
	while (k!=q.front()) {
		int nx = q.front();
		
		q.pop();
		if (isOutofLine(nx - 1)) {//-1
			if (map[nx - 1] > map[nx] + 1) {
				map[nx - 1] = map[nx] + 1;
				q.push(nx - 1);
			}
		}
		if (isOutofLine(nx + 1)) { // +1
			if (map[nx + 1] > map[nx] + 1) {
				map[nx + 1] = map[nx] + 1;
				q.push(nx + 1);
			}
		}
		if (isOutofLine(nx * 2) && nx != 0) { //*2
			if (map[nx * 2] > map[nx]) {
				map[nx * 2] = map[nx];
				q.push(nx * 2);
			}
		}
	}
}

int main() {
	cin >> n >> k;
	bfs(n);
	
	cout << map[k];
}