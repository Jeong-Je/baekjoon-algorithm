// 9012

#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
	int t;
	string ps;
	cin >> t;

	string answer;
	while (t--) {
		answer = "YES";
		stack<char>stack;
		cin >> ps;

		//입력받은 문자열의 크기가 홀수라면 VPS가 될 수 없다.
		if (ps.size() % 2 != 0) {
			cout << "NO\n";
			continue;
		}


		for (int i = 0; i < ps.size(); i++) {
			//첫번째 문자열은 무조건 '('
			if (ps[i] == '(')
				stack.push(ps[i]);
			else if (!stack.empty() && ps[i] == ')' && stack.top() == '(') {
				stack.pop();
			}
			else {
				answer = "NO"; break;
			}
		}

		if (!stack.empty()) {
			answer = "NO";
		} 
		cout << answer<<"\n";

	}
	return 0;
}