#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N, K;
	cin >> N >> K;
	
	vector<vector<int>> student(2, vector<int>(6, 0));
	
	for (auto i = 0; i < N; i++) {
		int sex, grade;
		cin >> sex >> grade;
		student[sex][grade-1]++;
	}
	
	int room4f{}, room4m{};
	for (auto j : student[0]) {
		if (j) room4f += j / K + ((j % K) ? 1 : 0);
	}
	
	for (auto j : student[1]) {
		if (j) room4m += j / K + ((j % K) ? 1 : 0);
	}
	
	cout << room4f + room4m;
}