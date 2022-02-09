#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	string first_str;
	cin >> first_str;
	
	list<char> str;
	
	for (auto c : first_str) {
		str.push_back(c);
	}
	
	auto it = str.end();
	
	int M;
	cin >> M;
	
	for (int i = 0; i < M; i++) {
		char command;
		cin >> command;
		switch (command) {
			case 'L':
				if (it != str.begin()) it--;
				break;
			case 'D':
				if (it != str.end()) it++;
				break;
			case 'B':
				if (it != str.begin()){
					it--;
					it = str.erase(it);
				}
				break;
			case 'P':
				char add_char;
				cin >> add_char;
				str.insert(it, add_char);
		}
	}
	
	for (auto c : str){
		cout << c;
	}
}