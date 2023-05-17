//10988
#include <iostream>

using namespace std;

int main() {
	string s;
	cin >> s;
	int cnt = 0;
	for (int i = 0; i < s.length() / 2; i++) {
		if (s[i] == s[s.length() - i-1]) {
			cnt++;
		}
	}
	if (cnt == s.length() / 2) {
		cout << "1";
	}
	else {
		cout << "0";
	}

}

