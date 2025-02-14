#include <iostream>
#include <map>
#include <queue>
using namespace std;

/*
삽입 할 때 3개에 다넣는다.
삭제 할 때 1이면  map의 value감소 후 max_pq에서 삭제
삭제 할 때 -1이면  map의 value감소 후 min_pq에서 삭제
해당 key의 value가 0이면 다음 원소 삭제

현재 top의 value가 0이 아닐 때 까지 pop
그 후 top의 value를 1 감소, 0이면 pop 아니면 그대로 두기
*/

int main() {
	int t;
	cin >> t;
	while (t--) {
		map<int, int>m; // key, value
		priority_queue<int>max_pq; // 내림 차순
		priority_queue<int, vector<int>, greater<>>min_pq; // 오름 차순
		int k;
		cin >> k;
		while (k--) {
			char c;
			int x;
			cin >> c >> x;
			if (c == 'I') {
				max_pq.push(x);
				min_pq.push(x);
				m[x]++;
			}
			else { // c=='D'
				if (m.empty() == 1) {
					continue;
				}
				if (x == 1) { // 최대 
					while (max_pq.empty() == 0 && m[max_pq.top()] == 0) {
						max_pq.pop();
					}
					if (max_pq.empty() == 0) {
						m[max_pq.top()]--;
						max_pq.pop();
					}
				}
				else {
					while (min_pq.empty() == 0 && m[min_pq.top()] == 0) {
						min_pq.pop();
					}
					if (min_pq.empty() == 0) {
						m[min_pq.top()]--;
						min_pq.pop();
					}
				}
			}
		}
		while (max_pq.empty() == 0 && m[max_pq.top()] == 0) {
			max_pq.pop();
		}

		while (min_pq.empty() == 0 && m[min_pq.top()] == 0) {
			min_pq.pop();
		}

		if (max_pq.empty() == 1 || min_pq.empty() == 1) {
			cout << "EMPTY" << "\n";
		}
		else {
			cout << max_pq.top() << ' ' << min_pq.top() << "\n";
		}
	}
}