#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N, K;
	cin >> N >> K;
	K--;
	
	list<int> josephus;
	for (int i = 1; i <= N; i++) josephus.push_back(i);
	
	cout << "<";
	while (!josephus.empty()) {
		for (int i = 0; i < K; i++) {
			josephus.push_back(josephus.front());
			josephus.pop_front();
		}
		cout << josephus.front();
		josephus.pop_front();
		if (!josephus.empty()) cout << ", ";
	}
	cout << ">";
}