#include <iostream>
#include <deque>
#include <vector>
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
	deque<int>dq;//좌표, 시간
	map[x] = 0;
	dq.push_back(x);
	while (k!=dq.front()) {
		int nx = dq.front();
		
		dq.pop_front();
		if (isOutofLine(nx * 2) && nx != 0) { //*2
			if (map[nx * 2] > map[nx]) {
				map[nx * 2] = map[nx];
				dq.push_front(nx * 2);
				
			}
		}
		if (isOutofLine(nx - 1)) {//-1
			if (map[nx - 1] > map[nx] + 1) {
				map[nx - 1] = map[nx] + 1;
				dq.push_back(nx - 1);
			}
		}
		if (isOutofLine(nx + 1)) { // +1
			if (map[nx + 1] > map[nx] + 1) {
				map[nx + 1] = map[nx] + 1;
				dq.push_back(nx + 1);
			}
		}
		
	}
}

int main() {
	cin >> n >> k;
	bfs(n);
	
	cout << map[k];
}