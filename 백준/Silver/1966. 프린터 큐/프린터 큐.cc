#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
/*
중요도 순서대로 인쇄를 한다.
중요도가 높은게 뒤에 있으면 맨 앞에 있는건 맨 뒤로 뺀다.
내가 확인하려는 문서는 몇번 째에 인쇄되는가?

중요도 높은 순서대로 pop을 하다가 내가 찾으려던 문서가 나오면 종료

아까 방법 똑같이 하기
*/

using namespace std;

int importance[10];

int main() {
	int t;
	cin >> t;
	while (t--) {
		queue<pair<int, int>>q; // 문서 순서, 중요도 
		int n, m, cnt = 0;// 문서의 개수 확인하려는 문서의 순서(인덱스)
		cin >> n >> m;
		memset(importance, 0, sizeof(importance));
		for (int i = 0; i < n; i++) { // 중요도
			int x;
			cin >> x;
			q.push({ i,x });
			importance[x]++;
		}
		while (1) {
			int cur_importance = 0;
			for (int i = 9; i >= 1; i--) { // 현재 가장 높은 중요도 찾기
				if (importance[i] != 0) {
					cur_importance = i;
					break;
				}
			}
			if (q.front().second == cur_importance) {
				if (q.front().first == m) { // 내가 원하던 걸 출력하려고 하면 pop하고 종료
					q.pop();
					cnt++;
					break;
				}
				else { //내가 원하던 문서가 아니면 cnt만 증가
					q.pop();
					cnt++;
					importance[cur_importance]--;
				}
			}
			else { //더 중요도가 높은 문서가 있으면 맨 뒤로 보내기
				q.push(q.front());
				q.pop();
			}
		}
		cout << cnt << "\n";
	}
}