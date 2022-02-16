#include <bits/stdc++.h>
using namespace std;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);
	
	int N;
	cin >> N;
	
	vector<int> S;
	for (auto i = 0; i < N; i++) {
		int n;
		cin >> n;
		S.push_back(n);
	}
	
	stack<int> S_, ans;
	for (auto i = N-1; i >= 0; i--) {
		while (!S_.empty() && S_.top() <= S[i])
			S_.pop();
		
		if (S_.empty()) ans.push(-1);
		else ans.push(S_.top());
		
		S_.push(S[i]);
	}
	
	while (!ans.empty()) {
		cout << ans.top() << " ";
		ans.pop();
	}
}