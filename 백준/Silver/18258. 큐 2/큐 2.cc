// 18258

#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	string c,cForPush;
	queue<int> q;
	while (n--) {
		cin >> c;
		if (c == "push") {
			cin >> cForPush;
			q.push(stoi(cForPush));
		}
		else if (c == "pop") {
			if (!q.empty()) {
				cout << q.front() << "\n";
				q.pop();
			}
			else {
				cout << "-1\n";
			}
		}
		else if (c == "size") {
			cout << q.size() << "\n";
		}
		else if (c == "empty") {
			if (q.empty())
				cout << "1\n";
			else
				cout << "0\n";
		}
		else if (c == "front") {
			if (!q.empty()) {
				cout << q.front() << "\n";
			}
			else {
				cout << "-1\n";
			}
		}
		else if (c == "back") {
			if (!q.empty()) {
				cout << q.back() << "\n";
			}
			else {
				cout << "-1\n";
			}
		}
	}
	return 0;
}