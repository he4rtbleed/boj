#include <bits/stdc++.h>
using namespace std;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);
	
	int N;
	cin >> N;
	
	stack<int> S;
	while (N--) {
		string cmd;
		cin >> cmd;
		if (cmd == "push") {
			int i;
			cin >> i;
			S.push(i);
		}else if (cmd == "pop") {
			if (S.empty()) cout << "-1\n";
			else cout << S.top() << "\n", S.pop();
		}else if (cmd == "size") {
			cout << S.size() << "\n";
		}else if (cmd == "empty") {
			cout << S.empty() << "\n";
		}else if (cmd == "top") {
			if (S.empty()) cout << "-1\n";
			else cout << S.top() << "\n";
		}
	}
}