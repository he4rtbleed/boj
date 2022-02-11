#include <bits/stdc++.h>
using namespace std;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);
	
	int n;
	cin >> n;
	
	string str;
	stack<int> S;
	int cur = 1;
	while (n--) {
		int m;
		cin >> m;
		while (cur <= m) {
			S.push(cur++);
			str+="+\n";
		}
		if (S.top() != m) {
			cout << "NO";
			return 0;
		}
		S.pop();
		str+="-\n";
	}
	
	cout << str;
}