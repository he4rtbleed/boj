#include <bits/stdc++.h>
using namespace std;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);
	
	int64_t A, B;
	cin >> A >> B;
	
	if (A == B) {
		cout << 0;
	}else if (A < B) {
		cout << B - A - 1 << "\n";

		for (int64_t i = A + 1; i < B; i++) {
			cout << i << " ";
		}
	} else {
		cout << A - B - 1 << "\n";

		for (int64_t i = B + 1; i < A; i++) {
			cout << i << " ";
		}
	}
}