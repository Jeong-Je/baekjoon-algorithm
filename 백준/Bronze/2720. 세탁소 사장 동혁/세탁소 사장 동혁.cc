//2720

#include <iostream>

using namespace std;

int main() {
	int t; 
	cin >> t;

	int c;
	int q = 25, d = 10, n = 5, p = 1;
	for (int i = 0; i < t; i++) {
		cin >> c;
		cout << int(c / q) << " ";
		c %= q;
		cout << int(c / d) << " ";
		c %= d;
		cout << int(c / n) << " ";
		c %= n;
		cout << int(c / p) << endl;
		c %= p;
	}
}