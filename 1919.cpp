#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	vector<int> str_diff(26, 0);
	
	string str1, str2;
	cin >> str1 >> str2;
	
	for (auto c : str1) {
		str_diff['z' - c]++;
	}
	for (auto c : str2) {
		str_diff['z' - c]--;
	}
	int cnt{};
	for (auto i : str_diff) {
		cnt+=abs(i);
	}
	cout << cnt;
}