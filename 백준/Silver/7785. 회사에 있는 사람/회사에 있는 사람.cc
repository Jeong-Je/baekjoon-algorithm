//  7785

#include <iostream>
#include <map>

using namespace std;

int main() {
	int n;
	cin >> n;
	string name, log;
	map<string, string> m;
	
	for (int i = 0; i < n; i++) {
		cin >> name >> log;
		if (m.find(name) != m.end())
			m.erase(name);
		else
			m.insert({ name, log });
	}

	for (auto iter = m.rbegin(); iter != m.rend(); iter++) {
		cout << iter->first << "\n";
	}

	return 0;
}