#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	string s;
	cin >> s;
	vector<int> alphabet_cnt(26);
	for (char c : s)
		alphabet_cnt[c - 97]++;
	
	for (int cnt : alphabet_cnt)
		cout << cnt << ' ';
}