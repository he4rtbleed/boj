#include <bits/stdc++.h>
using namespace std;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);
	
	string pipe_str;
	getline(cin, pipe_str);

	int count{}, pipe_cnt{};
	deque<int> a{};
	for (auto i = 0; i < pipe_str.size(); i++) {
		if (i < pipe_str.size() && pipe_str[i+1] == ')' && pipe_str[i] == '(') {
			i++;
			count += pipe_cnt;
		} else if (pipe_str[i] == '(') {
			a.push_back('(');
			pipe_cnt++;
		} else if (pipe_str[i] == ')') {
			a.push_back(')');
			pipe_cnt--;
			count++;
		}
	}
	
	cout << count;
}