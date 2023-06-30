// 11653

#include <iostream>
using namespace std;



int main() {
	int n;
	cin >> n;

	int i = 2;

	for (i; i <= n; i++) {
		if (n == 1)break;
		while (n % i == 0) {
			cout << i << "\n";
			n /= i;
		}
	}



	return 0;
}