#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N;
	cin >> N;
	
	vector<vector<int>> str_map(N, vector<int>(26, 0)), fried_str_map(N, vector<int>(26, 0));
	
	for (auto i = 0; i < N; i++) {
		string str, fried_str;
		cin >> str >> fried_str;
		for (auto c : str) {
			str_map[i]['z' - c]++;
		}
		for (auto c : fried_str) {
			fried_str_map[i]['z' - c]++;
		}
		
		bool possible = true;
		for (int j = 0; j < 26; j++) {
			if (str_map[i][j] != fried_str_map[i][j]) {
				cout << "Impossible\n";
				possible = false;
				break;
			}
		}
		if (possible) cout << "Possible\n";
	}
}