#include <bits/stdc++.h>
using namespace std;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);
	
	int T;
	cin >> T;

	while (T--) {
		deque<int> dq;
		string p;
		cin >> p;
		int n;
		cin >> n;
		string x_str;
		cin >> x_str;
		vector<string> xs(n);
		int xs_idx{};
		for (auto x : x_str) {
			if (isdigit(x)) xs[xs_idx] += x;
			else if (x == ',') xs_idx++;
		}
		for (auto x : xs) {
			dq.push_back(stoi(x));
		}
		bool error_flag = false;
		bool reverse_flag = false;
		for (auto c : p) {
			if (c == 'R') {
				if (reverse_flag) reverse_flag = false;
				else reverse_flag = true;
			}else if (c == 'D') {
				if (dq.empty()) error_flag = true;
				else {
					if (reverse_flag) dq.pop_back();
					else dq.pop_front();
				}
			}
		}
		if (!error_flag) {
			cout << "[";
			if (reverse_flag) {
				for (auto i = dq.rbegin(); i != dq.rend(); i++) {
					if (i != dq.rbegin()) cout << "," << *i;
					else cout << *i;
				}
			}
			else {
				for (auto i = dq.begin(); i != dq.end(); i++) {
					if (i != dq.begin()) cout << "," << *i;
					else cout << *i;
				}
			}
			cout << "]\n";
		}else cout << "error\n";
	}
}