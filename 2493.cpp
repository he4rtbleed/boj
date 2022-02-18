#include <bits/stdc++.h>
using namespace std;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);
	
	int N;
	cin >> N;
	
	stack<pair<int, int>> H;
	for (auto i = 0; i < N; i++) {
		int n;
		cin >> n;
		
		while (!H.empty() && H.top().second < n) H.pop();
		
		if (H.empty()) cout << "0 ";
		else cout << H.top().first << " ";
		
		H.push(make_pair(i+1, n));
	}
}