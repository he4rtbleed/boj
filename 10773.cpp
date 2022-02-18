#include <bits/stdc++.h>
using namespace std;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);
	
	int K;
	cin >> K;
	
	stack<int> S;
	while (K--) {
		int m;
		cin >> m;
		if (!m && !S.empty()) S.pop();
		else S.push(m);
	}
	
	int total{};
	while (!S.empty()) {
		total += S.top();
		S.pop();
	}
	cout << total;
}