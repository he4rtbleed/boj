#include <bits/stdc++.h>
using namespace std;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);
	
	int N;
	cin >> N;
	
	deque<int> DQ;
	for (auto i = 0; i < N; i++) {
		string cmd;
		cin >> cmd;
		if (cmd == "push_front") {
			int i;
			cin >> i;
			DQ.push_front(i);
		}else if (cmd == "push_back") {
			int i;
			cin >> i;
			DQ.push_back(i);
		}else if (cmd == "pop_front") {
			if (DQ.empty()) cout << "-1\n";
			else cout << DQ.front() << "\n", DQ.pop_front();
		}else if (cmd == "pop_back") {
			if (DQ.empty()) cout << "-1\n";
			else cout << DQ.back() << "\n", DQ.pop_back();
		}else if (cmd == "size") {
			cout << DQ.size() << "\n";
		}else if (cmd == "empty") {
			cout << DQ.empty() << "\n";
		}else if (cmd == "front") {
			if (DQ.empty()) cout << "-1\n";
			else cout << DQ.front() << "\n";
		}else if (cmd == "back") {
			if (DQ.empty()) cout << "-1\n";
			else cout << DQ.back() << "\n";
		}
	}
}