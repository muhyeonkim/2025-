#include <iostream>
#include <vector>
#include <algorithm>
/*
맨위에 표현 하다가 해당 칸에 이미 기록되 있으면 그 밑에 부터 다시 채우기
달력에 표시는 
1. 시작일이 가장 앞선 일정 부터
2. 시작일이 같으면 일정 기간이 가장 긴 것 부터

다음 원소의 시작일이 전 원소일의 종료일 보다 1차이나면 가로 길이 증가
다음 원소의 시작일이 전 원소일의 종료일 보다 2이상 차이나면 길이 초기화
다음 원소의 시작일이 전 원소일의 종료일 보다 차이가 0이하이면 세로 길이 증가
start_row,end_row


그러면 일정 입력할 때 바로 달력에 적지 말고 배열에 넣고

*/
using namespace std;

bool calendar[1001][366];

bool cmp(pair<int, int> a, pair <int, int>b) {
	if (a.first == b.first) return a.second > b.second;
	else return a.first < b.first;
}

int main() {
	int n, depth = 0;
	vector<pair<int, int>>v;
	cin >> n;
	while (n--) {
		int s, e;
		cin >> s >> e;
		v.push_back({ s,e });

	}
	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < v.size(); i++) { // n번 반복
		for (int j = 0; j < v.size(); j++) { //해당 라인이 되는지 확인
			bool isDup = false;
			for (int k = v[i].first; k <= v[i].second; k++) {
				if (calendar[j][k] == 1) {
					isDup = true;
					break;
				}
			}
			if (isDup == true) continue;
			else {
				for (int k = v[i].first; k <= v[i].second; k++) { // 해당 라인에 칠하기
					calendar[j][k] = 1;
				}
				break;
			}
		}
	}
	int start = v[0].first, end = 0;
	for (int i = 0; i < v.size(); i++) {
		end = max(end, v[i].second);
	}
	int row = start, col = 0;

	for (int i = start; i <= end; i++) {
		int tmp_col = 0;
		bool isEmpty = true;
		for (int j = 0; j < v.size(); j++) {
			if (calendar[j][i] == 1) {
				isEmpty = false;
				tmp_col++;
			}
		}
		col = max(tmp_col, col);

		if (isEmpty == true) {
			depth += (i - row) * col;
			col = 0, row = i + 1;// 빈 곳이면 초기화
		}
	}
	//cout << end << ' ' << row << ' ' << col << ' ';
	depth += (end - row + 1) * col;
	cout << depth;
}