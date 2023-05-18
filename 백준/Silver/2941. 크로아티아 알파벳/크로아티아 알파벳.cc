//2941
#include <iostream>

using namespace std;

int main() {
	string s;
	cin >> s;
	int cnt = 0;

	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'd') {
			if (s[i + 1] == 'z' && s[i + 2] == '=') {
				i += 2; cnt++;
				continue;
			}
		}
		if (s[i] == 'c' || s[i] == 's' || s[i] == 'z' || s[i] == 'd') {
			if (s[i + 1] == '=' || s[i + 1] == '-') {
			continue;
			}
		}
		else if (s[i] == 'l' || s[i] == 'n') {
			if (s[i + 1] == 'j')continue;
		}
		cnt++;
	}

	cout << cnt << "\n";



}

