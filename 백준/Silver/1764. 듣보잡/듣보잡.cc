// 1746

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int n, m,cnt=0;
	string name;
	cin >> n >> m;
	map<string, bool> mp;
	for (int i = 0; i < n; i++) {
		cin >> name;
		mp.insert(make_pair(name, true));
	}

	vector<string> v;
	for (int i = 0; i < m; i++) {
		cin >> name;
		if (mp[name]) {
			cnt++;
			v.push_back(name);
		}
	}

	sort(v.begin(), v.end());

	cout << cnt << "\n";
	for (int i = 0; i < v.size(); i++)
		cout << v.at(i) << "\n";

	return 0;
}