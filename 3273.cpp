#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N;
	cin >> N;
	
	vector<int> dat(N);
	
	for (auto i = 0; i < N; i++) cin >> dat[i];
	
	int X;
	cin >> X;
	
	int cnt{};
	vector<int> dat_inv(2000000);
	for (auto a : dat) {
		if ((X > a) && (dat_inv[X-a])) {
			cnt++;
		}
		dat_inv[a] = 1;
	}
	cout << cnt;
}