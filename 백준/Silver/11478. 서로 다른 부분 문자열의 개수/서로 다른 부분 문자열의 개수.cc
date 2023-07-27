// 11478

#include <iostream>
#include <map>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	string s;
	int cnt = 0;
	cin >> s;

	map<string, bool> map;

	string str = "";
	for (int i = 0; i < s.length(); i++) {
		for (int j = i; j < s.length(); j++) {
			str += s[j];
			if (map.find(str) != map.end())continue;
			map.insert(make_pair(str, true)); cnt++;
		}
		str = "";
	}

	cout << cnt;
}