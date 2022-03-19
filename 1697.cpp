#include <bits/stdc++.h>
using namespace std;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);
	
	int N, K;
	cin >> N >> K;
	
	vector<int> dist(100001);
	dist[N] = 1;
	queue<int> Q;
	Q.push(N);
	
	if (N == K) {
		cout << 0;
		return 0;
	}
	
	while (!Q.empty()) {
		int cur = Q.front(); Q.pop();
		auto nxt = {cur - 1, cur + 1, cur * 2};
		for (auto n : nxt) {
			if (n < 0 || n > 100000) continue;
			if (dist[n]) continue;
			if (n == K) {
				cout << dist[cur];
				return 0;
			}
			dist[n] = dist[cur] + 1;
			Q.push(n);
		}
	}
}