#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

template<typename T>
void fnProcessInput(int n, int m, T& board) {
	for (int i = 0; i < n; i++) {
		string line;
		getline(cin, line);
		for (int j = 0; j < m; j++) {
			board[i][j] = line[j] - '0';
		}
	}
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);
	
	int n, m;
	cin >> n >> m;
	cin.ignore(); // 버퍼 클리어 안해주면 fnProcessInput에서 getline 함수에 n m 이 들어감
	
	vector<vector<int>> board(n, vector<int>(m));
	vector<vector<int>> dist(n, vector<int>(m));
	
	fnProcessInput(n, m, board);
	
	dist[0][0] = 1;
	queue<pair<int, int>> Q;
	Q.push({0, 0});
	
	while (!Q.empty()) {
		pair<int, int> cur = Q.front(); Q.pop();
		for (auto i = 0; i < 4; i++) {
			int newx = cur.first + dx[i];
			int newy = cur.second + dy[i];
			if (newx < 0 || newx >= n || newy < 0 || newy >= m) continue;
			if (dist[newx][newy] || !board[newx][newy]) continue;
			dist[newx][newy] = dist[cur.first][cur.second] + 1;
			Q.push({newx, newy});
		}
	}
	
	cout << dist[n-1][m-1];
}