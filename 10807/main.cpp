#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N;
	cin >> N;
	
	vector<int> dat(N+210);
	
	for (auto i = 0; i < N; i++) {
		cin >> dat[i];
		dat[N+dat[i]+105]++;
	}
	
	int v;
	cin >> v;
	
	cout << dat[N+v+105];
}