#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N;
	cin >> N;
	
	vector<int> cnt(10);
	while (N) {
		cnt[N % 10]++;
		N /= 10;
	}
	
	cnt[6] += cnt[9];
	cnt[9] = 0;
	cnt[6] = cnt[6] / 2 + cnt[6] % 2;
	
	sort(cnt.begin(), cnt.end());
	cout << cnt.back();
}