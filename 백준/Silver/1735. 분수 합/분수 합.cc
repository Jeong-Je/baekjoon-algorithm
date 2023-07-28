// 1735

#include <iostream>

using namespace std;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

void Reduction(int& r1, int& r2, int& d) {
	while ((r1 % d == 0) && (r2 % d == 0) && (d != 1)) {
		r1 /= d;r2 /= d;
	}
}


int main() {
	int a1, b1;
	int a2, b2;
	int r1, r2;
	cin >> a1 >> b1;
	cin >> a2 >> b2;

	r1 = a1 * b2 + a2 * b1;
	r2 = b1 * b2;

	int divisor = gcd(r1, r2);
	Reduction(r1, r2, divisor);

	cout << r1 << " " << r2;

}