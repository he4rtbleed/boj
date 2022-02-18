#include <bits/stdc++.h>
using namespace std;

int fact(int n) {
	if (n) return n-- * fact(n);
	else return 1;
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);
	
	int N;
	cin >> N;
	
	cout << fact(N);
}