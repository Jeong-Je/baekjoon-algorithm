// 28278

#include <iostream>
#include <stack>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	stack<int> stack;
	int n,command;
	cin >> n;
	while (n--) {
		cin >> command;
		switch (command) {
		case 1:
			cin >> command;
			stack.push(command);
			break;
		case 2:
			if (!stack.empty()) {
				cout << stack.top() << "\n";
				stack.pop();
			}
			else cout << "-1\n";

			break;
		case 3:
			cout << stack.size()<<"\n";
			break;
		case 4:
			if (stack.empty())cout << "1\n";
			else cout << "0\n";
			break;
		case 5:
			if (!stack.empty())
				cout << stack.top() << "\n";
			else
				cout << "-1\n";
			break;
		default:
			break;
			}
		}
	return 0;
}

