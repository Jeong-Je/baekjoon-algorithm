// 2346

#include <iostream>
#include <deque>

using namespace std;

int main(void) {
	int n, num;
	deque<pair<int, int>> d;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		d.push_back(make_pair(num, i + 1));
	}

	while (!d.empty()) {
		int c = d.front().first;
		cout << d.front().second<<" ";
		d.pop_front();

		if (d.empty())
			break;

		if (c > 0) {
			for (int i = 1; i < c; i++) {
				d.push_back(d.front());
				d.pop_front();
			}
		}
		else {
			for (int i = c; i < 0; i++) {
				d.push_front(d.back());
				d.pop_back();
			}
		}
	}
	return 0;
}