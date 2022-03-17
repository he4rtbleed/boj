#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

template<typename T>
deque<pair<int, int>> fnProcessInput(int n, int m, T& board) {
	deque<pair<int, int>> positions{};
	for (int i = 0; i < n; i++) {
		string line;
		getline(cin, line);
		for (int j = 0; j < m; j++) {
			board[i][j] = line[j];
			if (line[j] == 'F') positions.push_back({i, j});
			if (line[j] == 'J') positions.push_front({i, j});
		}
	}
	return positions;
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);
	
	int C, R;
	cin >> C >> R;
	
	vector<vector<char>> board(C, vector<char>(R));
	vector<vector<int>> dist4fire(C, vector<int>(R));
	vector<vector<int>> dist4jihun(C, vector<int>(R));
	cin.ignore(); // 버퍼 클리어 안해주면 fnProcessInput에서 getline 함수에 C R 이 들어감
	
	auto positions = fnProcessInput(C, R, board);
	
	auto j_pos = positions.front(); positions.pop_front();
	
	// 불이 옮겨 붙는 시간 계산
	queue<pair<int, int>> Q;
	for (auto f : positions) {
		Q.push(f);
		dist4fire[f.first][f.second] = 1;
	}

	while (!Q.empty()) {
		pair<int, int> cur = Q.front(); Q.pop();
		for (auto i = 0; i < 4; i++) {
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];

			if (nx < 0 || nx >= C || ny < 0 || ny >= R) continue;
			if (dist4fire[nx][ny] || board[nx][ny] == '#') continue;
			dist4fire[nx][ny] = dist4fire[cur.first][cur.second] + 1;
			Q.push({nx, ny});
		}
	}
	
	// 지훈이의 움직임 BFS
	Q.push(j_pos);
	dist4jihun[j_pos.first][j_pos.second] = 1;
	
	while (!Q.empty()) {
		pair<int, int> cur = Q.front(); Q.pop();
		for (auto i = 0; i < 4; i++) {
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];

			if (nx < 0 || nx >= C || ny < 0 || ny >= R) {
				cout << dist4jihun[cur.first][cur.second];
				return 0;
			}
			if (dist4jihun[nx][ny] || board[nx][ny] == '#') continue;
			if (dist4fire[nx][ny] && dist4jihun[cur.first][cur.second] + 1 >= dist4fire[nx][ny]) continue;
			dist4jihun[nx][ny] = dist4jihun[cur.first][cur.second] + 1;
			Q.push({nx, ny});
		}
	}
	
	cout << "IMPOSSIBLE";
}