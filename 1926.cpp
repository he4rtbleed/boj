#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1}; // 하우상좌

template<typename T>
void fnProcessInput(int m, int n, T& board) {
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
	
	int n, m;
	cin >> n >> m;
	
	vector<vector<int>> board(n, vector<int>(m));
	vector<vector<bool>> vis(n, vector<bool>(m));
	
	fnProcessInput(m, n, board);
	
	int totalCount{}, maxArea{}; // 그림의 총 개수, 가장 넓은 그림의 넓이
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if(vis[i][j] || board[i][j] != 1) continue; // 방문한적 있거나 그림이 아닌 부분은 스킵
			totalCount++; // 조건에 부합한 그림을 찾았으므로 그림의 총 개수 증가
			int curArea{};
			
			vis[i][j] = true;
			queue<pair<int, int>> Q;
			Q.push({i, j}); // 큐에 조건에 부합한 그림의 좌표 추가
			while(!Q.empty()) { // 조건에 부합한 그림의 초기 좌표로부터 하우상좌 순으로 모두 살펴보며(BFS) 그림의 넓이 스캔
				pair<int, int> cur = Q.front(); Q.pop(), curArea++; // 큐에서 제거할때마다 그림의 상하좌우에 색깔이 있는것이므로 그림의 넓이 증가
				for(int dir = 0; dir < 4; dir++){ // 상하좌우(하우상좌 순) 칸을 살펴볼 것이다.
					int nx = cur.first + dx[dir];
					int ny = cur.second + dy[dir]; // nx, ny에 dir에서 정한 방향의 인접한 칸의 좌표가 들어감
					if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue; // 범위 밖일 경우 스킵
					if(vis[nx][ny] || board[nx][ny] != 1) continue; // 이미 방문한 칸이거나 그림이 아닐경우 스킵
					vis[nx][ny] = true; // (nx, ny)를 방문했다고 체크
					Q.push({nx,ny});
				}
			}
			maxArea = max(curArea, maxArea);
		}
	}
	
	cout << totalCount << "\n" << maxArea;
}