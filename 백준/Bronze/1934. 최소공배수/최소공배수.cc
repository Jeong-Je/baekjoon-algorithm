// 1934

#include <iostream>

using namespace std;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int main() {
	int t, a, b;
	cin >> t;
	for (int i = 0;i < t; i++) {
		cin >> a >> b;
		cout << a / gcd(a, b) * b<<"\n";
	}
	return 0;
}