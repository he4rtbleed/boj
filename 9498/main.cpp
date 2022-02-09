#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int score;
	cin >> score;
	
	switch (score/10) {
		case 10:
			cout << "A";
			break;
		case 9:
			cout << "A";
			break;
		case 8:
			cout << "B";
			break;
		case 7:
			cout << "C";
			break;
		case 6:
			cout << "D";
			break;
		default:
			cout << "F";
			break;
	}
}