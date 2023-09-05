// 24511

#include <iostream>
#include <stack>
#include <queue>

using namespace std;

bool flag[100000];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	stack<int> s;
	queue<int> q;

	int n;
	cin >> n;
	for (int i = 0; i < n;i++) {
		cin >> flag[i];
	}

	int input;
	for (int i = 0; i < n; i++) {
		cin >> input;
		if (flag[i] == 0) { // 큐 일때만 삽입
			s.push(input);
		}
	}

	while (!s.empty()) {
		q.push(s.top());
		s.pop();
	}

	int m;
	cin >> m;
	while (m--) {
		cin >> input;
		q.push(input);
		cout << q.front() << " ";
		q.pop();
	}

	return 0;
}