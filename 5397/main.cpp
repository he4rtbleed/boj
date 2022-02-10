#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N;
	cin >> N;
	
	while (N--) {
		string logged_key_input;
		cin >> logged_key_input;
		list<char> str;
		
		auto it = str.end();
		
		for (auto& c : logged_key_input) {
			if (c == '<' && it != str.begin()) it--;
			else if (c == '>' && it != str.end()) it++;
			else if (c == '-' && it != str.begin()) it--, it = str.erase(it);
			else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) str.insert(it, c);
		}

		for (auto c : str){
			cout << c;
		}
		cout << '\n';
	}
}