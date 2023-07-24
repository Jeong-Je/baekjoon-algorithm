// 1620

#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int n, m;
	string s;
	cin >> n >> m;
	map<int, string> map1;
	map<string, int> map2;
	for (int i = 0; i < n; i++) {
		cin >> s;
		map1.insert(make_pair(i + 1, s));
		map2.insert(make_pair(s, i+1));
	}

	for (int i = 0; i < m; i++) {
		cin >> s;
		if (s[0] <= 57) {
			cout<< map1[stoi(s)]<<"\n";
		}
		else {
			cout << map2[s]<<"\n";
		}
	}

	return 0;
}