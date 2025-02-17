#include <iostream>
#include <queue>
using namespace std;

char tree[26][2];

void travel1(int x) { // 전위
	cout << char(x+'A');
	if (tree[x][0] != '.') {
		travel1(tree[x][0] - 'A');
	}
	if (tree[x][1] != '.') {
		travel1(tree[x][1] - 'A');
	}
}

void travel2(int x) { // 중위
	if (tree[x][0] != '.') {
		travel2(tree[x][0] - 'A');
	}
	cout << char(x + 'A');

	if (tree[x][1] != '.') {
		travel2(tree[x][1] - 'A');
	}
}

void travel3(int x) { // 후위
	if (tree[x][0] != '.') {
		travel3(tree[x][0] - 'A');
	}

	if (tree[x][1] != '.') {
		travel3(tree[x][1] - 'A');
	}
	cout << char(x + 'A');
}
int main() {
	int  n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		char first, second, third;
		cin >> first >> second >> third;
		
		if (second == '.') {
			tree[first - 'A'][0] = '.';
		}
		else {
			tree[first - 'A'][0] = second;
		}
		if (third == '.') {
			tree[first - 'A'][1] = '.';
		}
		else {
			tree[first - 'A'][1] = third;
		}
	}
	
	travel1(0);
	cout << "\n";
	travel2(0);
	cout << "\n";
	travel3(0);

}