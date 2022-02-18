#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N, K;
	cin >> N >> K;
	
	vector<int> josephus;
	for (int i = 1; i <= N; i++) josephus.push_back(i);
	
	int cur = K-1;
	cout << "<";
	while (!josephus.empty()) {
		cout << josephus[cur];
		josephus.erase(josephus.begin() + cur);
		if (!josephus.empty()) {
			cout << ", ";
			cur = (cur + K - 1) % josephus.size();
		}
	}
	cout << ">";
}