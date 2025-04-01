#include <iostream>
#include <vector>
#include <queue>
/*
같은 지점에서 시작하는 투 포인터
k개를 초과하면 가장 처음 있는 위치 다음으로 left를 옮기기
위치는 배열에 저장하기
*/

using namespace std;

int nums[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k;
	vector<int>v;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	
	int left = 0, max_length = 0;
	for (int right = 0; right < n; right++) {
		nums[v[right]]++;
		if (nums[v[right]] > k) { // 해당 숫자가 k개를 초과할 경우
			nums[v[right]]--;
			while (v[right]!=v[left]) {
				nums[v[left]]--;
				left++;
			}
			left++;
		}
		max_length = max(max_length, right - left + 1);
		//cout << right << ' ' << left << ' ' << max_length << ' ' << right - left + 1 << "\n";
	}
	cout << max_length;
}