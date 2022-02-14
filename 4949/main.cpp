#include <bits/stdc++.h>
using namespace std;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);
	
	for (;;) {
		stack<char> S;
		
		bool error = false;
		string PS;
		getline(cin, PS);
		if (PS == ".") break;
		for (auto c : PS) {
			if (c == '(' || c == '[') S.push(c);
			else if (c == ')') {
				if (S.empty() || S.top() != '(') {
					error = true;
					break;	//4ms -> 0ms
				}
				else S.pop();
			}
			else if (c == ']') {
				if (S.empty() || S.top() != '[') {
					error = true;
					break;
				}
				else S.pop();
			}
		}
		if (S.size() || error) cout << "no\n";
		else cout << "yes\n";
	}
}