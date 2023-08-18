// 12789
#include <iostream>
#include <queue>
#include <stack>
using namespace std;



int main(void) {
	int n;
	queue<int> queue;
	stack<int> stack;
	vector<int> v;
	cin >> n;
	while (n--) {
		int a;
		cin >> a;
		queue.push(a);
	}

	int turn = 1;
	while (!queue.empty()) {
		if (queue.front() == turn) {
			v.push_back(turn);
			turn++;
			queue.pop();
		}
		else if (!stack.empty() && stack.top() == turn) {
			stack.pop();
			v.push_back(turn);
			turn++;
		}
		else {
			stack.push(queue.front());
			queue.pop();
		}
	}

	while (!stack.empty()) {
		v.push_back(stack.top());
		stack.pop();
	}

	bool result = true;
	for (int i = 0; i < v.size()-1; i++) {
		if (v[i] > v[i + 1]) {
			result = false;
			break;
		}
	}

	if (result)cout << "Nice";
	else cout << "Sad";

}