// 10773

#include <iostream>
#include <stack>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int k,n;
	cin >> k;
	stack<int> stack;
	while (k--) {
		cin >> n;
		if (n == 0)stack.pop();
		else stack.push(n);
	}

	int sum = 0;
	for (;!stack.empty();) {
		sum += stack.top();
		stack.pop();
	}

	cout << sum;
	return 0;
}