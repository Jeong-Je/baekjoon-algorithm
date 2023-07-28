// 1934

#include <iostream>

using namespace std;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int main() {
	long long int a, b;
	cin >> a >> b;
	cout << a / gcd(a, b) * b << "\n";
	return 0;
}