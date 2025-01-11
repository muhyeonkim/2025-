#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int main() {
	int t;
	cin >> t;
	vector<tuple<int, int, string>>v;
	for (int i = 0; i < t; i++) {
		int age;
		string name;
		cin >> age >> name;

		v.push_back({ age,i,name });
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < t; i++) {
		cout << get<0>(v[i]) << ' ' << get<2>(v[i]) << "\n";
	}
}