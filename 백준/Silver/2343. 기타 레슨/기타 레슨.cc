#include <iostream>
#include <vector>

/*
left,right= 블루레이의 크기
크기를 mid만큼 했을 때, m개를 만들 수 있는가

최소 블루레이의 크기 출력
*/

using namespace std;

int n, m;
vector<int>v;
bool isPossible(int mid) {
	int cnt = 0, sum = 0;
	for (int i = 0; i < n; i++) {
		if (v[i] > mid) return false; // 블루레이 크기보다 강의가 더 큰 경우 

		if (sum + v[i] > mid) { // 남은 블루레이 크기보다 강의가 더 큰 경우
			sum = 0;
			cnt++;
		}
		sum += v[i];
		if (sum == mid) {
			sum = 0;
			cnt++;
		}
		if (cnt > m) return false;
	}
	if (sum != 0) cnt++;
	if (cnt > m) return false;
	return true;
}

int main() {
	int max_length = 0,sum=0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
		max_length = max(max_length, x);
		sum += x;
	}
	int left = max_length, right = sum, res = 0;
	while (left <= right) {
		int mid = (left + right) / 2;
	//	cout << left << ' ' << mid << ' ' << right << "\n";
		if (isPossible(mid) == true) { // m개 이하로 가능할 때 크기를 줄여야 함
			res = mid;
			right = mid - 1;
		}
		else { //m개보다 더 필요할 때 크기를 늘려야함
			left = mid + 1; 
		}
	}
	cout << res;
}