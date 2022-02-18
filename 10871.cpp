#include <bits/stdc++.h>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N, X;
	cin >> N >> X;
	
	int tmp;
	while (N--) {
		cin >> tmp;
		if (tmp < X) cout << tmp << " ";
	}
	return 0;
}