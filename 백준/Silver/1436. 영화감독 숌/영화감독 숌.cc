#include <iostream>
#include <string>
using namespace std;

int main() {
	int n, num = 0;
	cin >> n;
	while (n!=0) {
		num++;
		string tmp = to_string(num);
		if (tmp.find("666") != string::npos) n--;
	}
	cout << num;
}