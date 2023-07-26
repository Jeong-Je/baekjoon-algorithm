// 1269

#include <iostream>
#include <map>

using namespace std;

int main() {
	int a, b,ele,cnt=0;
	cin >> a >> b;

	map<int, bool> m;
	for (int i = 0; i < a; i++) {
		cin >> ele;
		m.insert(make_pair(ele, true));
		cnt++;
	}

	for (int i = 0; i < b; i++) {
		cin >> ele;
		if (m.find(ele) != m.end()) {
			cnt--;
			continue;
		}
		cnt++;
	}

	cout << cnt;
	return 0;
}