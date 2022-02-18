#include <bits/stdc++.h>
using namespace std;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);
	
	int T;
	cin >> T;
	
	while (T--) {
		stack<char> S;
		
		bool error = false;
		string PS;
		cin >> PS;
		for (auto c : PS) {
			if (c == '(') S.push(c);
			else if (c == ')') {
				if (S.empty()) error = true;
				else S.pop();
			}
		}
		if (S.size() || error) cout << "NO\n";
		else cout << "YES\n";
	}
}