#include <iostream>
#include <cstring>

using namespace std;

char map[3100][6200];

void draw_star(int x, int y, int n) {
	if (n == 3) {
		map[x][y] = '*';
		map[x + 1][y] = ' ';
		map[x + 2][y] = '*';

		map[x + 1][y - 1] = '*';
		map[x + 1][y + 1] = '*';

		map[x + 2][y - 1] = '*';
		map[x + 2][y + 1] = '*';
		map[x + 2][y - 2] = '*';
		map[x + 2][y + 2] = '*';
		return;
	}
	else {
		draw_star(x, y, n / 2);
		draw_star(x + n / 2, y - n / 2, n / 2);
		draw_star(x + n / 2, y + n / 2, n / 2);
	}
}

int main() {
	memset(map, ' ', sizeof(map));
	int n;
	cin >> n;
	draw_star(0, n - 1, n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2 * n-1; j++) {
			cout << map[i][j];
		}
		cout << "\n";
	}
}