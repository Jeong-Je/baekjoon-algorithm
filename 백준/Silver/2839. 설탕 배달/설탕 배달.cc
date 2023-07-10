// 1436

#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i * 3 + j * 5 == n) {
				cout << i + j;
				return 0;
			}
			
		}
	}
	cout << -1;
	return 0;
}
