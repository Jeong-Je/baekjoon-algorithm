//14425

#include <iostream>
#include <vector>
#include<map>

using namespace std;

int main() {
	int n, m, cnt = 0;
	string s;
	map<string, bool> set;
	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		cin >> s;
		set[s] = true;
	}

	
	for (int i = 0; i < m; i++) {
		cin >> s;
		if (set[s])cnt++;
	}

	cout << cnt;
	return 0;
}