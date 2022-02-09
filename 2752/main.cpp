#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int A, B, C;
	cin >> A >> B >> C;
	
	int max = std::max(std::max(A, B), C);
	int min = std::min(std::min(A, B), C);
	int mid = A + B + C - max - min; //이 숫자는 1보다 크거나 같고, 1,000,000보다 작거나 같다 //오버플로 걱정 안해도됨
	
	cout << min << ' ' << mid << ' ' << max;
}