// 4134

#include <iostream>
#include <cmath>
using namespace std;

bool IsPrimeNumber(long long n) {
	for (int i = 2;i<=sqrt(n); i++) {
		if (n % i == 0)return false;
	}
	return true;
}


int main() {
	int t;
	long long n;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		if (n <= 2)cout << "2\n";
		else {
			for (long long i = n;; i++) {
				if (IsPrimeNumber(i)) {
					cout << i << "\n"; break;
				}
			}

		}

	}
}