#include <bits/stdc++.h>
using namespace std;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);
	
	string bracket;
	cin >> bracket;
	
	int current_depth{};
	int depth_sum[10000]{};
	bool error = false;
	stack<int> error_checker;
	for (auto c : bracket) {
		if (c == '(' || c == '[') {
			current_depth++;
			error_checker.push(c);
		}
		else if (c == ')' || c == ']') {
			if (current_depth) current_depth--;
			else {
				error = true;
				break;
			}
			int should_be_added;
			if (c == ')') {
				if (!error_checker.empty()) {
					if (error_checker.top() != '(') {	//올바르지 못한 입력 처리
						error = true;
						break;
					}
					error_checker.pop();
				}
				should_be_added = 2;
			}
			else if (c == ']') {
				if (!error_checker.empty()) {
					if (error_checker.top() != '[') {	//올바르지 못한 입력 처리
						error = true;
						break;
					}
					error_checker.pop();
				}
				should_be_added = 3;
			}
			
			should_be_added *= !depth_sum[current_depth+1] ? 1 : depth_sum[current_depth+1];
			
			depth_sum[current_depth+1] = 0;
			
			depth_sum[current_depth] += should_be_added;
		}
	}
	if (error)
		cout << 0;
	else
		cout << depth_sum[0];
}