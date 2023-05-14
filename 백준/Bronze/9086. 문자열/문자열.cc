//9086
#include <string>
#include <iostream>

using namespace std;

int main() {
	int T;
	cin >> T;

	string s;
	for (int i = 0; i < T; i++) {
		cin >> s;
		cout << s[0]<<s[s.length() - 1]<<"\n";
	}
}