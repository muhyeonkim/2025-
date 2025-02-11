#include <iostream>
#include <deque>
#include <string>
using namespace std;

/*
현재 n=0이면 error 발생
*/
int main() {
	int t;
	cin >> t;
	while (t--) {
		deque<int>dq;
		string p1, p2, tmp = "";
		int n;
		bool isError = false, isReverse = false;
		cin >> p1 >> n >> p2;
		for (char c : p2) { // dq에 배열 넣기
			if (c == ',' || c == ']') {
				if (n!=0) 
					dq.push_back(stoi(tmp));
				tmp = "";
			}
			else if (c == '[') {

			}
			else {
				tmp += c;
			}
		}

		for (char c : p1) {
			if (c == 'R') {
				isReverse ^= 1;
			}
			else { // c=='D'
				if (dq.size() == 0) isError = true;

				else if (isReverse == 0) {
					dq.pop_front();
				}
				else {
					dq.pop_back();
				}
			}
		}
		if (isError == true) {
			cout << "error";
		}
		else {
			cout << '[';
			if (isReverse == 1 && n != 0) {
				for (int i = dq.size() - 1; i >= 0; i--) {
					cout << dq[i];
					if (i != 0) cout << ',';
				}
			}
			else if (isReverse == 0 && n != 0) {
				for (int i = 0; i < dq.size(); i++) {
					cout << dq[i];
					if (i != dq.size() - 1) cout << ',';
				}
			}
			cout << ']';
		}
		cout << "\n";
	}
}