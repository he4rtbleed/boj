#include <bits/stdc++.h>
using namespace std;

int dx[8] = {2, 2, 1, 1, -2, -2, -1, -1};
int dy[8] = {1, -1, 2, -2, 1, -1, 2, -2};

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);
	
	int TC;
	cin >> TC;
	
	while (TC--) {
		int l;
		cin >> l;

		vector<vector<int>> dist(l, vector<int>(l));
		
		int cx, cy;
		cin >> cx >> cy;
		
		int tx, ty;
		cin >> tx >> ty;
		
		if (cx == tx && cy == ty) {
			cout << "0\n";
			continue;;
		}
		
		dist[cx][cy] = 1;
		queue<pair<int, int>> Q;
		Q.push({cx, cy});
		bool approached = false;
		while (!Q.empty() && !approached) {
			pair<int, int> cur = Q.front(); Q.pop();
			for (auto i = 0; i < 8; i++) {
				int newx = cur.first + dx[i];
				int newy = cur.second + dy[i];
				if (newx < 0 || newx >= l || newy < 0 || newy >= l) continue;
				if (dist[newx][newy]) continue;
				if (newx != tx || newy != ty) {
					dist[newx][newy] = dist[cur.first][cur.second] + 1;
					Q.push({newx, newy});
					continue;
				}
				approached = true;
				break;
			}
			if (approached) {
				cout << dist[cur.first][cur.second] << "\n";
				break;
			}
		}
	}
}