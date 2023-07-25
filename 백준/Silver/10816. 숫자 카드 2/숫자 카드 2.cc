// 10816

#include <iostream>
#include <map>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int n, m,tmp;
	cin >> n;
	map<int, int> mp;
	map<int, int>::iterator iter;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		iter = mp.find(tmp);
		if (iter != mp.end()) {
			iter->second += 1;
		}
		else {
			mp.insert(make_pair(tmp, 1));
		}
	}

	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> tmp;
		cout << mp[tmp] << " ";
	}
	return 0;
}