#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

template<typename T>
void fnProcessInput(int n, int m, T& board) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int temp;
			cin >> temp;
			board[i][j] = temp;
		}
	}
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);
	
	int m, n;
	cin >> m >> n;
	
	vector<vector<int>> board(n, vector<int>(m));
	vector<vector<int>> day_taken(n, vector<int>(m));
	
	fnProcessInput(n, m, board);
	
	queue<pair<int, int>> Q;
	int max_day{};
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (day_taken[i][j] || board[i][j] != 1) continue;
			day_taken[i][j] = 1;
			Q.push({i, j});
		}
	}
	
	
	while (!Q.empty()) {
		pair<int, int> cur = Q.front(); Q.pop();
		for (auto i = 0; i < 4; i++) {
			int newx = cur.first + dx[i];
			int newy = cur.second + dy[i];
			if (newx < 0 || newx >= n || newy < 0 || newy >= m) continue;
			if (day_taken[newx][newy] || board[newx][newy]) continue;
			day_taken[newx][newy] = day_taken[cur.first][cur.second] + 1;
			max_day = max(max_day, day_taken[newx][newy]);
			Q.push({newx, newy});
		}
	}
	
	bool all_riped = true;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!day_taken[i][j] && board[i][j] != -1) all_riped = false;
		}
	}
	
	if (all_riped)
		cout << max(max_day-1, 0);
	else
		cout << -1;
}