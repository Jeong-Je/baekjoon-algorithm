// 28279

#include <iostream>
#include <deque>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
	int n;
	cin >> n;
	deque<int> dq;

	int c;
	while (n--) {
		cin >> c;
		switch (c) {
		case 1:
			cin >> c;
			dq.push_front(c);
			break;
		case 2:
			cin >> c;
			dq.push_back(c);
			break;
		case 3:
			if (!dq.empty()) {
				cout << dq.front() << "\n";
				dq.pop_front();
			}
			else {
				cout << "-1\n";
			}
			break;
		case 4:
			if (!dq.empty()) {
				cout << dq.back() << "\n";
				dq.pop_back();
			}
			else {
				cout << "-1\n";
			}
			break;
		case 5:
			cout << dq.size() << "\n";
			break;
		case 6:
			if (dq.empty())
				cout << "1\n";
			else
				cout << "0\n";
			break;
		case 7:
			if (!dq.empty())
				cout << dq.front() << "\n";
			else
				cout << "-1\n";
			break;
		case 8:
			if (!dq.empty())
				cout << dq.back() << "\n";
			else
				cout << "-1\n";
			break;
		}
	}

	return 0;
}