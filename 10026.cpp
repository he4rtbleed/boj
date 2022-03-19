#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

template <typename T>
void fnProcessInput(int N, T& board) {
	for (int i = 0; i < N; i++) {
		string line;
		cin >> line;
		for (int j = 0; j < N; j++) {
			board[i][j] = line[j];
		}
	}
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);
	
	int N;
	cin >> N;
	cin.ignore();
	
	vector<vector<char>> board(N, vector<char>(N));
	vector<vector<bool>> vis(N, vector<bool>(N));
	fnProcessInput(N, board);
	
	int areaCnt{}, areaCnt_normal{};
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (vis[i][j]) continue;
			areaCnt++;
			
			vis[i][j] = true;
			queue<pair<int, int>> Q;
			Q.push({i, j});
			char saved_color = board[i][j];
			while (!Q.empty()) {
				auto cur = Q.front(); Q.pop();
				for (auto i = 0; i < 4; i++) {
					int nx = cur.first + dx[i];
					int ny = cur.second + dy[i];
					
					if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
					if (vis[nx][ny]) continue;
					if (saved_color == 'R' || saved_color == 'G') {
						if (board[nx][ny] == 'B') continue;
					}
					else {
						if (board[nx][ny] == 'R' || board[nx][ny] == 'G') continue;
					}
					vis[nx][ny] = true;
					Q.push({nx, ny});
				}
			}
		}
	}
	
	fill(vis.begin(), vis.end(), vector<bool>(N, 0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (vis[i][j]) continue;
			areaCnt_normal++;
			
			vis[i][j] = true;
			queue<pair<int, int>> Q;
			Q.push({i, j});
			char saved_color = board[i][j];
			while (!Q.empty()) {
				auto cur = Q.front(); Q.pop();
				for (auto i = 0; i < 4; i++) {
					int nx = cur.first + dx[i];
					int ny = cur.second + dy[i];
					
					if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
					if (vis[nx][ny]) continue;
					if (board[cur.first][cur.second] != board[nx][ny]) continue;
					vis[nx][ny] = true;
					Q.push({nx, ny});
				}
			}
		}
	}
	cout << areaCnt_normal << " " << areaCnt;
}