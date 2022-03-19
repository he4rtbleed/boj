#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

template <typename T>
void fnProcessInput(int K, T& board) {
	for (int i = 0; i < K; i++) {
		int cab_pos_x, cab_pos_y;
		cin >> cab_pos_x >> cab_pos_y;
		board[cab_pos_y][cab_pos_x] = 1;
	}
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);
	
	int T;
	cin >> T;
	while (T--) {
		int M, N, K;
		cin >> M >> N >> K;
		vector<vector<int>> board(N, vector<int>(M));
		vector<vector<bool>> vis(N, vector<bool>(M));
		fnProcessInput(K, board);
		
		int worm_cnt{};
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (vis[i][j] || !board[i][j]) continue;
				worm_cnt++;
				
				vis[i][j] = true;
				queue<pair<int, int>> Q;
				Q.push({i, j});
				while (!Q.empty()) {
					auto cur = Q.front(); Q.pop();
					for (auto i = 0; i < 4; i++) {
						int nx = cur.first + dx[i];
						int ny = cur.second + dy[i];
						if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
						if (vis[nx][ny] || !board[nx][ny]) continue;
						vis[nx][ny] = true;
						Q.push({nx, ny});
					}
				}
			}
		}
		cout << worm_cnt << "\n";
	}
}