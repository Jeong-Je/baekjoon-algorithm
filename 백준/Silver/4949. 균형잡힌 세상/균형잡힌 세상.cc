// 4949

#include <iostream>
#include <stack>
#include <string>
#include <ctype.h>
using namespace std;
int main() {
	while (1) {
		string s;
		stack<char> stack;
		getline(cin, s);
		if (s == ".")break;
		bool flag = 1;
		for (int i = 0; i < s.size() - 1 ; i++) {
			if (s[i] == '(' || s[i] == '[')stack.push(s[i]);
			else if (!stack.empty() && s[i] == ')' && stack.top() == '(')stack.pop();
			else if (!stack.empty() && s[i] == ']' && stack.top() == '[')stack.pop();
			else if (isalpha(s[i]) || s[i] == ' ') continue;
			else {
				flag = 0;
				break;
			}
		}

		if (flag && stack.empty()) {
			cout << "yes\n";
		}
		else {
			cout << "no\n";
		}
	}
	return 0;
}