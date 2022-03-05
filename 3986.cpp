#include <bits/stdc++.h>
using namespace std;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);
	
	int count, good_word_count{};
	cin >> count;
	
	while(count--) {
		stack<char> S;
		
		string word;
		cin >> word;
		for (auto c : word) {
			if (S.empty()) S.push(c);
			else if (S.top() != c) {
				S.push(c);
			}
			else if (S.top() == c) {
				S.pop();
			}
		}
		if (S.empty()) good_word_count++;
	}
	cout << good_word_count;
}