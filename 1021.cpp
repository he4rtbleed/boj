#include <bits/stdc++.h>
using namespace std;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);
	
	int N, M;
	cin >> N >> M;
	
	int count{};

	deque<int> a;
	for (auto i = 1; i <= N; i++) {
		a.push_back(i);
	}
	
	for (auto i = 0; i < M; i++) {
		int a_;
		cin >> a_;
		
		int idx;
		for (auto j = 0; j < a.size(); j++) {
			if (a[j] == a_) idx = j;
		}
		
		if (idx <= a.size() / 2) { // 왼쪽으로 회전하는게 더 빠를때
			for (auto j = 0; j < idx; j++) {
				count++;
				a.push_back(a.front());
				a.pop_front();
			}
			a.pop_front();
		}else if (idx > a.size() / 2) { // 오른쪽으로 회전하는게 더 빠를때
			for (auto j = 0; j < a.size() - idx; j++) {
				count++;
				a.push_front(a.back());
				a.pop_back();
			}
			a.pop_front();
		}
	}
	
	cout << count;
}