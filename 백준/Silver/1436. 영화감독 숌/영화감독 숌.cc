// 1436

#include <iostream>
#include <string>
using namespace std;

int main() {
	int n, cnt=0,i=0;
	cin >> n;
	while(true) {
		if (to_string(i).find("666") != string::npos) {
			cnt++;
		}
		if (cnt == n) {
			cout << i;
			return 0;
		}
		i++;
	}

	return 0;
}
