#include <bits/stdc++.h>
using namespace std;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);
	
	int N;
	cin >> N;
	
	queue<int> Q;
	for (auto i = 1; i <= N; i++) {
		Q.push(i);
	}
	
	bool should_push = false;
	while (Q.size() != 1) {
		auto front = Q.front();
		Q.pop();
		if (!should_push)
			should_push = true;
		else
			Q.push(front), should_push = false;
	}
	cout << Q.front();
}