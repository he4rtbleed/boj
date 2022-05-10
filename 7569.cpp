#include <bits/stdc++.h>
using namespace std;

int dx[6] = {0, 0, 1, -1, 0, 0};
int dy[6] = {1, -1, 0, 0, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

template<typename T>
void fnProcessInput(int n, int m, int h, T& board) {
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				int temp;
				cin >> temp;
				board[j][k][i] = temp;
			}
		}
	}
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);
	
	int m, n, h;
	cin >> m >> n >> h;
	
	vector<vector<vector<int>>> board(n, vector<vector<int>>(m, vector<int>(h)));
	vector<vector<vector<int>>> day_taken(n, vector<vector<int>>(m, vector<int>(h)));
	
	fnProcessInput(n, m, h, board);
	
	queue<tuple<int, int, int>> Q;
	int max_day{};
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (day_taken[j][k][i] || board[j][k][i] != 1) continue;
				day_taken[j][k][i] = 1;
				Q.push({j, k, i});
			}
		}
	}
	
	
	while (!Q.empty()) {
		auto cur = Q.front(); Q.pop();
		for (auto i = 0; i < 6; i++) {
			int newx = get<0>(cur) + dx[i];
			int newy = get<1>(cur) + dy[i];
			int newz = get<2>(cur) + dz[i];
			if (newx < 0 || newx >= n || newy < 0 || newy >= m || newz < 0 || newz >= h) continue;
			if (day_taken[newx][newy][newz] || board[newx][newy][newz]) continue;
			day_taken[newx][newy][newz] = day_taken[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
			max_day = max(max_day, day_taken[newx][newy][newz]);
			Q.push({newx, newy, newz});
		}
	}
	
	bool all_riped = true;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (!day_taken[j][k][i] && board[j][k][i] != -1) all_riped = false;
			}
		}
	}
	
	if (all_riped)
		cout << max(max_day-1, 0);
	else
		cout << -1;
}