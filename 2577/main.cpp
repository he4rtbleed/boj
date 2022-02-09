#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int A, B, C;
	cin >> A >> B >> C;
	
	vector<int> cnt(10);
	int mul = A * B * C;
	while (mul) {
		cnt[mul % 10]++;
		mul /= 10;
	}
	
	for (auto a : cnt) cout << a << "\n";
}